//
// Created by Nylan on 16-04-2021.
//

#ifndef YUKON_LINKEDLIST_H
#define YUKON_LINKEDLIST_H
//There probably should be a file with this
typedef int BOOL;
#define TRUE 1
#define FALSE 0

typedef struct linkedList LinkedList;

LinkedList* newLinkedList();

BOOL hasComparator(LinkedList *linkedList);
void setComparator(LinkedList *linkedList, int (*comparator) (void* a, void* b));

void* get(LinkedList* linkedList, int index);
void* getFirst(LinkedList* linkedList);
void *getLast(LinkedList *LinkedList);

BOOL add(LinkedList *linkedList, void* t);
BOOL append(LinkedList *appendTo, LinkedList *appending);
BOOL push(LinkedList *linkedList, void *t);
void* pop(LinkedList* linkedList);
void* poll(LinkedList* linkedList);
//void* remove(LinkedList* linkedList);
void* removeIndex(LinkedList *linkedList, int index);
void* removeElement(LinkedList *linkedList, void* t);

BOOL insert(LinkedList *linkedList, void *t);
BOOL insertAt(LinkedList *linkedList, void *t, int index);

LinkedList* cutList(LinkedList *linkedList, int startIndex, int endIndex);
LinkedList* cutEnd(LinkedList *linkedList, int startIndex);


int size(LinkedList *linkedList);
BOOL sort(LinkedList *linkedList);

#endif //YUKON_LINKEDLIST_H
