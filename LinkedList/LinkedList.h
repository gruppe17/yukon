//
// Created by Nylander on 16-04-2021.
//

#ifndef YUKON_LINKEDLIST_H
#define YUKON_LINKEDLIST_H
//There probably should be a file with this
typedef int BOOL;
#define TRUE 1
#define FALSE 0

/**
 * Represents a generic linked list
 * @author Rasmus Nylander, s205418
 */
typedef struct linkedList LinkedList;

/**
 * Returns a pointer to a new list, or null if memory
 * allocation failed.
 * @author Rasmus Nylander, s205418
 */
LinkedList* newLinkedList();

/**
 * Whether the specified LinkedList has been assigned
 * a comparator function
 * @param linkedList the LinkedList to check if assigned a comparator function
 * @return TRUE if the specified LinkedList has been assigned a comparator function
 * @author Rasmus Nylander, s205418
 */
BOOL hasComparator(LinkedList *linkedList);
/**
 * Sets the comparator function of a LinkedList to the specified function
 * @param linkedList the LinkedList which is to be assigned a comparator function
 * @param comparator a pointer to a function which can compare to elements in the list
 * @author Rasmus Nylander, s205418
 */
void setComparator(LinkedList *linkedList, int (*comparator) (void* a, void* b));

/**
 * Returns i'th element of the specified list. If there is no
 * i'th element returns null.
 * @param linkedList the LinkedList from which to retrieve an element
 * @param index the index of the element to be retrieved
 * @return 	the element at the specified index in the specified LinkedList, or null
 * 			if the index is invalid.
 * @author Rasmus Nylander, s205418
 */
void* get(LinkedList* linkedList, int index);
/**
 * Returns the 0'th element of the specified list or null if the list is empty
 * @param linkedList the LinkedList from which to retrieve the first element
 * @return the 0'th element of the specified list or null if the list is empty
 * @author Rasmus Nylander, s205418
 */
void* getFirst(LinkedList* linkedList);
/**
 * Returns the last element of the specified list or null if the list is empty
 * @param LinkedList the LinkedList from which to retrieve the last element
 * @return the last element of the specified list or null if the list is empty
 * @author Rasmus Nylander, s205418
 */
void *getLast(LinkedList *LinkedList);

/**
 * Adds the specified element to the end of the specified list
 * @param linkedList the LinkedList to which the element should be appended
 * @param t the element to append to the list
 * @return True if the list was modified
 * @author Rasmus Nylander, s205418
 */
BOOL add(LinkedList *linkedList, void* t);
/**
 * Appends a LinkedList to another and frees appended lists memory
 * @param appendTo the list to append to
 * @param appending the list to append
 * @return TRUE if either list was changed
 * @author Rasmus Nylander, s205418
 */
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

BOOL interweaveLinkedList(LinkedList *into, LinkedList *linkedList);
BOOL shuffle(LinkedList *linkedList);
BOOL swap(LinkedList *linkedList, int i, int j);

BOOL sort(LinkedList *linkedList);

#endif //YUKON_LINKEDLIST_H
