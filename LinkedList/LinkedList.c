//
// Created by Rasmus Nylander on 16-04-2021.
//

#include "LinkedList.h"
#include <stdlib.h>
#include <time.h>

typedef struct _node{
	struct _node* next;
	void* data;
} Node;

Node* newNode(void* data);

Node* newNode(void* data){
	Node *node = (Node *) malloc(sizeof(Node));
	node->next = NULL;
	node->data = data;
	return node;
}


Node* getLastNode(LinkedList *linkedList);

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

BOOL hasComparator(LinkedList *linkedList){
	return linkedList->comparator != NULL;
}

void setComparator(LinkedList *linkedList, int (*comparator) (void* a, void* b)){
	linkedList->comparator = comparator;
}

BOOL validIndex(LinkedList *linkedList, int index){
	return index < linkedList->size && index >= 0;
}

void* get(LinkedList* linkedList, int index){
	if (!validIndex(linkedList, index)) return NULL;
	if (index == linkedList->size) return getLast(linkedList);

	Node* node = linkedList->head;
	for (int i = 0; i < index; ++i) {
		node = node->next;
	}
	return node->data;
}

void* getFirst(LinkedList* linkedList){
	return linkedList->head->data;
}

void* getLast(LinkedList *linkedList) {
	return getLastNode(linkedList)->data;
	//return linkedList->tail->data;
}

/*
void addedItemHead(LinkedList *linkedList){
	if (linkedList->size == 0){
		linkedList->tail = linkedList->head;
	}
	linkedList->size++;
}

void removedItemHead(LinkedList *linkedList){
	if (linkedList->size < 3){
		linkedList->tail = linkedList->head;
	}
	linkedList->size--;
}
*/

Node** getNode(LinkedList *linkedList, int index){
	if (!validIndex(linkedList, index)) return NULL;

	Node **tracer = &linkedList->head;
	for (int i = 0; i < index; ++i) {
		tracer = &(*tracer)->next;
	}
	return tracer;
}

Node* getLastNode(LinkedList *linkedList){
	Node **tracer = &linkedList->head;
	while ((*tracer)->next != NULL){
		tracer = &(*tracer)->next;
	}
	return (*tracer);
	//return linkedList->tail;
}

BOOL add(LinkedList *linkedList, void* t){
	Node *node = newNode(t);
	if (node == NULL) return FALSE;
	linkedList->size++;
	getLastNode(linkedList)->next = node;
	/*
	if (linkedList->size == 1){
		linkedList->tail = node;
		linkedList->head = node;
		return TRUE;
	}
	linkedList->tail->next = node;
	linkedList->tail = node;
	 */
	return TRUE;
}

BOOL appendToEmpty(LinkedList *appendTo, LinkedList *appending){
	appendTo->head = appending->head;
	appendTo->tail = appending->tail;
	appendTo->size = appending->size;
	free(appending);
	return TRUE;
}

BOOL append(LinkedList *appendTo, LinkedList *appending){
	if (appendTo->size == 0) return appendToEmpty(appendTo, appending);
	appendTo->size += appending->size;
	appendTo->tail->next = appending->head;
	appendTo->tail = appending->tail;
	free(appending);
	return TRUE;
}

/**
 * Cuts out the sublist beginning and ending with the
 * specified indices inclusive, and returns the removed
 * sublist as a new linked list.
 * @param linkedList 	The LinkedList which is to be cut
 * @param startIndex 	The index of the first element in
 * 						the sublist
 * @param endIndex 		The index of the last element in
 * 						the sublist
 * @return				A new LinkedList containing the
 * 						elements from startIndex inclusive
 * 						through endIndex
 */
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


BOOL push(LinkedList *linkedList, void *t){
	Node *node = newNode(t);
	if (node == NULL) return FALSE;

	node->next = linkedList->head;
	linkedList->head = node;
	linkedList->size++;
	if (linkedList->size == 1) linkedList->tail = linkedList->head;
	return TRUE;
}

void* pop(LinkedList* linkedList){
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
/*
void* remove(LinkedList* linkedList){
	return pop(linkedList);
}
*/
void* removeIndex(LinkedList *linkedList, int index){
	if (!validIndex(linkedList, index)) return NULL;

	Node** tracer = &linkedList->head;
	for (int i = 0; i < index; i++){
		tracer = &(*tracer)->next;
	}
	Node *target = *tracer;
	*tracer = (*tracer)->next;
	void *data = target->data;
	free(target);
	return data;
}

void* removeElement(LinkedList *linkedList, void* t){
	if (!hasComparator(linkedList)) return NULL;

	BOOL present = FALSE;
	Node **tracer = &(linkedList->head);
	for (int i = 0; i < linkedList->size; ++i) { //This could be a while loop
		if ( (present = (linkedList->comparator(t, (*tracer)->data)) == 0) ) break;
		tracer = &(*tracer)->next;
	}
	if (present){
		Node* node = *tracer; //Remember the node
		*tracer = (*tracer)->next; //Remove the node from the linked list
		void *data = node->data; //Free the memory of the node and return the data the node contained
		free(node);
		linkedList->size--;
		return data;
	}
	return NULL;
}

BOOL insert(LinkedList *linkedList, void *t){
	if (linkedList->comparator == NULL) return FALSE;
	Node* node = newNode(t);
	if (node == NULL) return FALSE;

	Node **tracer = &linkedList->head;
	while ((*tracer != NULL) && linkedList->comparator((*tracer)->data, t) < 1){
		tracer = &(*tracer)->next;
	}
	node->next = *tracer;
	*tracer = node;
	linkedList->size++;
	return TRUE;
}

BOOL insertAt(LinkedList *linkedList, void *t, int index){
	if (!validIndex(linkedList, index)) return FALSE;
	Node *node = newNode(t);
	if (node == NULL) return FALSE;

	Node **tracer = &linkedList->head;
	for (int i = 0; i < index; ++i) {
		tracer = &(*tracer)->next;
	}
	node->next = *tracer;
	*tracer = node;
	return TRUE;
}

int size(LinkedList *linkedList){
	return linkedList->size;
}

BOOL interweaveLinkedList(LinkedList *into, LinkedList *linkedList){
	if (linkedList == NULL || into == NULL || linkedList->size == 0) return FALSE;
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
	return TRUE;
}

BOOL shuffle(LinkedList *linkedList){
	int s = size(linkedList);
	if (s < 2) return TRUE;

	time_t t;
	srand((unsigned) time(&t));
	int swaps = s - 1;
	for (int i = 0; i < swaps; ++i) {
		swap(linkedList, i, (rand() % (s - i)) + i);
	}
	return TRUE;
}

BOOL swapNodes(Node **a, Node **b){
	if (*a == *b || (*a) == NULL || (*b) == NULL) return FALSE;
	Node *temp = (*a);
	*a = *b;
	*b = temp;

	temp = (*a)->next;
	(*a)->next = (*b)->next;
	(*b)->next = temp;
	return TRUE;
}

BOOL swap(LinkedList *linkedList, int i, int j){
	if (!validIndex(linkedList, i) || !validIndex(linkedList, j)) return FALSE;
	return swapNodes(getNode(linkedList, i), getNode(linkedList, j));
}

BOOL mergeSort(LinkedList *linkedList, int startIndex, int endIndex);
BOOL bubbleSort(LinkedList *linkedList);

BOOL sort(LinkedList *linkedList){
	if (!hasComparator(linkedList)) return FALSE;
	if (linkedList->size < 2) return TRUE;
	//return mergeSort(linkedList, 0, size(linkedList) - 1);
	bubbleSort(linkedList);
}

BOOL bubbleSort(LinkedList *linkedList){
	if (!hasComparator(linkedList)) return FALSE;

	int listLength = size(linkedList);
	for (int i = 0; i < listLength; ++i) {
		BOOL hasSwapped = FALSE;
		Node **tracer = &linkedList->head;
		for (int j = 0; j < listLength - i - 1; ++j) {
			if (linkedList->comparator((*tracer)->data, (*tracer)->next->data) >= 1){
				swapNodes(tracer, &(*tracer)->next);
				hasSwapped = TRUE;
			}
			tracer = &(*tracer)->next;
		}
		if (!hasSwapped) return TRUE;
	}
	return TRUE;
}

/**DOES NOT WORK!*/
BOOL mergeSorted(LinkedList *linkedList, int startIndex, int endIndex, int midPoint);
BOOL mergeSort(LinkedList *linkedList, int startIndex, int endIndex){
	if (!hasComparator(linkedList)) return FALSE;
	if (endIndex - startIndex < 1) return TRUE;

	int midpoint = ((endIndex - startIndex) / 2) + startIndex;
	mergeSort(linkedList, startIndex, midpoint);
	mergeSort(linkedList, midpoint + 1, endIndex);
	mergeSorted(linkedList, startIndex, endIndex, midpoint);
	return TRUE;
}

BOOL mergeSorted(LinkedList *linkedList, int startIndex, int endIndex, int midPoint){
	if (!hasComparator(linkedList)) return FALSE;

	Node *startNode = *getNode(linkedList, startIndex);
	Node *midNode = *getNode(linkedList, midPoint + 1);
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

	return TRUE;
}