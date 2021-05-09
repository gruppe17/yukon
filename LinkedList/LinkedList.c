//
// Created by Rasmus Nylander on 16-04-2021.
//

#include "LinkedList.h"
#include "LinkedListInternalFunctions.h"
#include <stdlib.h>
#include <time.h>

struct _node{
	struct _node* next;
	void* data;
};

Node* newNode(void* data){
	Node *node = (Node *) malloc(sizeof(Node));
	node->next = NULL;
	node->data = data;
	return node;
}

struct linkedList {
	int size;
	Node* head;
	Node* tail;
	int (*comparator) (void* a, void* b);
};

LinkedList* newLinkedList(){
	LinkedList *linkedList = (LinkedList *) malloc(sizeof(LinkedList));
	linkedList->size = 0;
	linkedList->head = NULL;
	//Tail is no longer used. It is in part maintained however.
	//Todo: determine whether to implement tail completely or scrap it.
	linkedList->tail = NULL;
}

bool hasComparator(LinkedList *linkedList){
	return linkedList->comparator != NULL;
}

void setComparator(LinkedList *linkedList, int (*comparator) (void* a, void* b)){
	linkedList->comparator = comparator;
}

/**
 * Returns whether the specified index is a valid index of the specified list
 * @param linkedList the list which the index should be validated for
 * @param index the index to validate
 * @return true if the index is valid
 * @author Rasmus Nylander, s205418
 */
bool validIndex(LinkedList *linkedList, int index){
	return index < linkedList->size && index >= 0;
}

void* extractData(Node* node){
	if (node == NULL) return NULL;
	return node->data;
}

void* get(LinkedList* linkedList, int index){
	return extractData(getNodePtr(linkedList, index));
}

void* getFirst(LinkedList* linkedList){
	return extractData(linkedList->head);
}

void* getLast(LinkedList *linkedList) {
	return extractData(getLastNode(linkedList));
}

Node* getNodePtr(LinkedList *linkedList, int index){
	Node **pNode = getNodePtrPtr(linkedList, index);
	if (pNode == NULL) return NULL;
	return *pNode;
}

Node** getNodePtrPtr(LinkedList *linkedList, int index){
	if (!validIndex(linkedList, index)) return NULL;

	Node **tracer = &linkedList->head;
	for (int i = 0; i < index; ++i) {
		tracer = &(*tracer)->next;
	}
	return tracer;
}

Node* getLastNode(LinkedList *linkedList){
	Node **tracer = &linkedList->head;
	while ((*tracer) && (*tracer)->next != NULL){
		tracer = &(*tracer)->next;
	}
	return *tracer;
	//return linkedList->tail;
}

bool add(LinkedList *linkedList, void* t){
	Node *node = newNode(t);
	if (node == NULL) return false;

	Node *lastNode = getLastNode(linkedList);
	if (lastNode == NULL) return push(linkedList, t);
	lastNode->next = node;

	linkedList->size++;
	linkedList->tail = node;
	return true;
}

bool append(LinkedList *appendTo, LinkedList *appending){
	if (appendTo->size == 0) return appendToEmpty(appendTo, appending);
	appendTo->size += appending->size;
	appendTo->tail->next = appending->head;
	appendTo->tail = appending->tail;
	free(appending);
	return true;
}

bool appendToEmpty(LinkedList *appendTo, LinkedList *appending){
	appendTo->head = appending->head;
	appendTo->tail = appending->tail;
	appendTo->size = appending->size;
	free(appending);
	return true;
}

bool push(LinkedList *linkedList, void *t){
	Node *node = newNode(t);
	if (node == NULL) return false;

	node->next = linkedList->head;
	linkedList->head = node;
	linkedList->size++;
	if (linkedList->size == 1) linkedList->tail = linkedList->head;
	return true;
}

void* pop(LinkedList* linkedList){
	if (isEmpty(linkedList)) return NULL;
	Node *popped = linkedList->head;
	linkedList->head = linkedList->head->next;
	linkedList->size--;
	if (linkedList->size == 1) linkedList->tail = linkedList->head;

	void *data = popped->data;
	free(popped);
	return data;
}

void* poll(LinkedList* linkedList){
	return getFirst(linkedList);
}

void* removeIndex(LinkedList *linkedList, int index){
	if (!validIndex(linkedList, index)) return NULL;

	Node** tracer = getNodePtrPtr(linkedList, index);
	Node *target = *tracer;
	*tracer = (*tracer)->next;
	void *data = target->data;
	free(target);
	return data;
}

bool removeElement(LinkedList *linkedList, void* t){
	if (!hasComparator(linkedList)) return false;

	bool present = false;
	Node **tracer = &(linkedList->head);
	while ((*tracer)->next != NULL) { //This could be a for loop
		if ( (present = (linkedList->comparator(t, (*tracer)->data)) == 0) ) break;
		tracer = &(*tracer)->next;
	}
	if (present){
		Node* node = *tracer; //Remember the node
		*tracer = (*tracer)->next; //Remove the node from the linked list
		free(node); //Free the memory of the node
		linkedList->size--;
	}
	return present;
}

bool insert(LinkedList *linkedList, void *t){
	if (linkedList->comparator == NULL) return false;
	Node* node = newNode(t);
	if (node == NULL) return false;

	Node **tracer = &linkedList->head;
	while ((*tracer != NULL) && linkedList->comparator((*tracer)->data, t) < 1){
		tracer = &(*tracer)->next;
	}
	node->next = *tracer;
	*tracer = node;
	linkedList->size++;
	return true;
}

bool insertAt(LinkedList *linkedList, void *t, int index){
	if (index == size(linkedList)) return add(linkedList, t);
	if (!validIndex(linkedList, index)) return false;
	Node *node = newNode(t);
	if (node == NULL) return false;

	Node **tracer = &linkedList->head;
	for (int i = 0; i < index; ++i) {
		tracer = &(*tracer)->next;
	}
	node->next = *tracer;
	*tracer = node;
	return true;
}

LinkedList* cutList(LinkedList *linkedList, int startIndex, int endIndex){
	if (startIndex > endIndex || startIndex < 0 || endIndex >= linkedList->size) return NULL;
	LinkedList* newList = (LinkedList*) malloc(sizeof(LinkedList));
	if (newList == NULL) return NULL;

	//Find the start of the new list
	Node** tracer = &linkedList->head, **cut;
	for (int i = 0; i < startIndex; ++i) {
		tracer = &(*tracer)->next;
	}
	newList->head = *tracer;
	cut = tracer;
	//Find the end of the new list
	for (int i = startIndex; i < endIndex; ++i) {
		tracer = &(*tracer)->next;
	}
	*cut = (*tracer)->next;
	newList->tail = *tracer;
	newList->tail->next = NULL;
	newList->size = endIndex - startIndex + 1;
	linkedList->size -= newList->size;
	return newList;
}

LinkedList* cutEnd(LinkedList *linkedList, int startIndex){
	return cutList(linkedList, startIndex, linkedList->size - 1);
}


int size(LinkedList *linkedList){
	return linkedList->size;
}

bool interweaveLinkedList(LinkedList *into, LinkedList *linkedList){
	if (linkedList == NULL || into == NULL || linkedList->size == 0) return false;
	Node *a = into->head, *b = linkedList->head, *aNext;
	while (a->next != NULL && b != NULL){
		aNext = a->next;

		a->next = b;
		a = a->next;
		b = b->next;
		a->next = aNext;

		a = a->next;
	}
	if (b != NULL) {
		a->next = b;
		into->tail = linkedList->tail;
	}
	into->size += linkedList->size;
	free(linkedList);
	return true;
}

bool shuffle(LinkedList *linkedList){
	int s = size(linkedList);
	if (s < 2) return false;

	time_t t;
	srand((unsigned) time(&t));
	int swaps = s - 1;
	for (int i = 0; i < swaps; ++i) {
		swap(linkedList, i, (rand() % (s - i)) + i);
	}
	return true;
}

bool swapNodes(Node **a, Node **b){
	if (*a == *b || (*a) == NULL || (*b) == NULL) return false;
	Node *temp = (*a);
	*a = *b;
	*b = temp;

	temp = (*a)->next;
	(*a)->next = (*b)->next;
	(*b)->next = temp;
	return true;
}

bool swap(LinkedList *linkedList, int i, int j){
	if (!validIndex(linkedList, i) || !validIndex(linkedList, j)) return false;
	return swapNodes(getNodePtrPtr(linkedList, i), getNodePtrPtr(linkedList, j));
}

bool mergeSort(LinkedList *linkedList, int startIndex, int endIndex);
/**
 * Sorts a list bubbly! I.e. sorts a list with bubble sort.
 * @param linkedList the LinkedList to be sorted
 * @return true if the list is sorted
 * @author Rasmus Nylander, s205418
 */
bool bubbleSort(LinkedList *linkedList);

bool sort(LinkedList *linkedList){
	if (!hasComparator(linkedList)) return false;
	if (size(linkedList) < 2) return true;
	//return mergeSort(linkedList, 0, size(linkedList) - 1);
	bubbleSort(linkedList);
}

bool bubbleSort(LinkedList *linkedList){
	if (!hasComparator(linkedList)) return false;

	int listLength = size(linkedList);
	for (int i = 0; i < listLength; ++i) {
		bool hasSwapped = false;
		Node **tracer = &linkedList->head;
		for (int j = 0; j < listLength - i - 1; ++j) {
			if (linkedList->comparator((*tracer)->data, (*tracer)->next->data) >= 1){
				swapNodes(tracer, &(*tracer)->next);
				hasSwapped = true;
			}
			tracer = &(*tracer)->next;
		}
		if (!hasSwapped) return true;
	}
	return true;
}

/**DOES NOT WORK!*/
bool mergeSorted(LinkedList *linkedList, int startIndex, int endIndex, int midPoint);
bool mergeSort(LinkedList *linkedList, int startIndex, int endIndex){
	if (!hasComparator(linkedList)) return false;
	if (endIndex - startIndex < 1) return true;

	int midpoint = ((endIndex - startIndex) / 2) + startIndex;
	mergeSort(linkedList, startIndex, midpoint);
	mergeSort(linkedList, midpoint + 1, endIndex);
	mergeSorted(linkedList, startIndex, endIndex, midpoint);
	return true;
}

bool mergeSorted(LinkedList *linkedList, int startIndex, int endIndex, int midPoint){
	if (!hasComparator(linkedList)) return false;

	Node *startNode = getNodePtr(linkedList, startIndex);
	Node *midNode = getNodePtr(linkedList, midPoint + 1);
	while (startIndex <= midPoint && endIndex > midPoint){
		Node *startNext = startNode->next;

		if (linkedList->comparator(midNode->data, startNode->data) < 1){
			startNode->next = midNode;
			midNode = midNode->next;
			startNode->next = startNext;
			endIndex--;
		} else startIndex++;
		startNode = startNode->next;
	}
	if (midPoint < endIndex){
		startNode->next = midNode;
	}

	return true;
}

bool clearList(LinkedList *linkedList){
	if (isEmpty(linkedList)) return false;
	while (!isEmpty(linkedList)){
		pop(linkedList);
	}
	return true;
}

void destroyList(LinkedList *linkedList){
	clearList(linkedList);
	free(linkedList);
}

bool isEmpty(LinkedList *linkedList){
	return size(linkedList) < 1;
}

