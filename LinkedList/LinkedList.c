//
// Created by Rasmus Nylander on 16-04-2021.
//

#include "LinkedList.h"
#include <stdlib.h>

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

void* get(LinkedList* linkedList, int index){
	if (index < 0 || index >= linkedList->size) return NULL;
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

Node* getLastNode(LinkedList *linkedList){
	Node **tracer = &linkedList->head;
	while ((*tracer)->next != NULL){
		tracer = (*tracer)->next;
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

LinkedList* cutList(LinkedList *linkedList, int startIndex, int endIndex){
	if (startIndex > endIndex || startIndex < 0 || endIndex >= linkedList->size) return NULL;
	LinkedList* newList = (LinkedList*) malloc(sizeof(LinkedList));
	if (newList == NULL) return NULL;

	//Find the start of the new list
	Node** tracer = &linkedList->head;
	for (int i = 0; i < startIndex; ++i) {
		tracer = &(*tracer)->next;
	}
	newList->head = *tracer;
	Node **cut = tracer;
	//Find the end of the new list
	for (int i = 0; i < endIndex; ++i) {
		tracer = &(*tracer)->next;
	}
	newList->tail = *tracer;
	*cut = (*tracer)->next;
	(*tracer)->next = NULL;
	newList->size = endIndex - startIndex + 1;
	linkedList->size -= newList->size;
	return newList;
}

LinkedList* cutEnd(LinkedList *linkedList, int startIndex){
	return cutList(linkedList, startIndex, linkedList->size);
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
	if (index < 0 || index > linkedList->size) return NULL;

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
	if (index < 0 || index > linkedList->size) return FALSE;
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

BOOL interweaveLinkedList(LinkedList *linkedList, LinkedList *into){
	if (linkedList == NULL || into == NULL || linkedList->size == 0) return FALSE;
	Node *a = into->head, *b = linkedList->head, **aNext;
	while (a != NULL && b != NULL){
		//Remember the next card in the a pile
		aNext = &a->next;
		//Insert the next card in the b pile into the a pile
		a->next = b;
		b = b->next;
		a->next = (*aNext);
		//Move to the next card in the a pile
		a = a->next;
	}
	if (a == NULL) {
		(*aNext) = b;
		into->tail = linkedList->tail;
	}
	free(linkedList);
	return TRUE;
}

BOOL sort(LinkedList *linkedList){
	if (linkedList->comparator == NULL) return FALSE;
	//Todo: implement this
	return FALSE;
}




