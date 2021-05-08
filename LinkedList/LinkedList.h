//
// Created by Nylander on 16-04-2021.
//

#ifndef YUKON_LINKEDLIST_H
#define YUKON_LINKEDLIST_H
//There probably should be a file with this

#include <stdbool.h>

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
 * @return true if the specified LinkedList has been assigned a comparator function
 * @author Rasmus Nylander, s205418
 */
bool hasComparator(LinkedList *linkedList);
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
bool add(LinkedList *linkedList, void* t);
/**
 * Appends a LinkedList to another and frees appended lists memory
 * @param appendTo the list to append to
 * @param appending the list to append
 * @return true if either list was changed
 * @author Rasmus Nylander, s205418
 */
bool append(LinkedList *appendTo, LinkedList *appending);
/**
 * Adds the specified element to the front of the specified list
 * @param linkedList the LinkedList to which an element should be added
 * @param t the element which is to be added to the from of the list
 * @return true if the list was changed
 * @author Rasmus Nylander, s205418
 */
bool push(LinkedList *linkedList, void *t);
/**
 * Removes the first element in the specified list and returns it
 * @param linkedList the LinkedList from which to pop the first element
 * @return the first element in the list or NULL if the list is empty
 * @author Rasmus Nylander, s205418
 */
void* pop(LinkedList* linkedList);
/**
 * Returns the 0'th element of the specified list or null if the list is empty.
 * Identical to getFirst
 * @param linkedList the LinkedList from which to retrieve the first element
 * @return the 0'th element of the specified list or null if the list is empty
 * @author Rasmus Nylander, s205418
 */
void* poll(LinkedList* linkedList);
/**
 * Removes the element at the specified index in the specified LinkedList
 * and returns it or NULL if no such element exists.
 * @param linkedList the LinkedList from which an element should be removed
 * @param index the index of the element to remove
 * @return The removed element or NULL if no such element exists
 * @author Rasmus Nylander, s205418
 */
void* removeIndex(LinkedList *linkedList, int index);
/**
 * Removes the specified element from the specified LinkedList.
 * The comparator function of the specified LinkedList must be set.
 * If the element is not contained in the list or if the list have
 * not been assigned a comparator, the list will be unchanged.
 * @param linkedList the LinkedList from which to remove an element
 * @param t the element to remove from the list
 * @return true if the list was changed
 * @author Rasmus Nylander, s205418
 */
bool removeElement(LinkedList *linkedList, void* t);

/**
 * Inserts the specified element in the specified list
 * in such a way that if the list is sorted it will
 * remain sorted after the insert.
 * Requires the list to have been assigned a comparator:
 * if the list has not been assigned a comparator the list
 * will remain unchanged.
 * @param linkedList tbe LinkedList into which the element should be inserted
 * @param t the element to insert into the list
 * @return true if the list was changed
 * @author Rasmus Nylander, s205418
 */
bool insert(LinkedList *linkedList, void *t);
/**
 * Inserts the specified element at the specified position
 * in the specified LinkedList, such that the elements index
 * will be equal to the specified index after insertion. If
 * the index is invalid the list will remain unchanged.
 * @param linkedList the list into which the element should be inserted
 * @param t the element which to insert into the list
 * @param index the index of the element after insertion
 * @return true if the list was changed
 * @author Rasmus Nylander, s205418
 */
bool insertAt(LinkedList *linkedList, void *t, int index);

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
 * 						through endIndex or NULL if the
 * 						indices are invalid or memory
 * 						cannot be allocated
 * @author Rasmus Nylander, s205418
 */
LinkedList* cutList(LinkedList *linkedList, int startIndex, int endIndex);
/**
 * Cuts off the end of the specified LinkedList and returns
 * it as a new LinkedList.
 * @param linkedList 	the linkedList to cut
 * @param startIndex 	the index of the first element in the
 * 						removed sublist
 * @return 	A new linked list containing the element at
 * 			startIndex and all subsequent element
 * @author Rasmus Nylander, s205418
 */
LinkedList* cutEnd(LinkedList *linkedList, int startIndex);

/**
 * Returns the number of elements in the specified LinkedList
 * @param linkedList the LinkedList whose length is desired
 * @return the number of elements in the specified LinkedList
 * @author Rasmus Nylander, s205418
 */
int size(LinkedList *linkedList);

/**
 * Weaves one LinkedList into another and frees its memory.
 * If one list is longer than the other, then the excess is
 * appended to the end of the list.
 * 1 → 2 → 3 → 4 → 5 → 6 → 7 & a → b → c → d → e
 * will become
 * 1 → a → 2 → b → 3 → c → 4 → d → 5 → e → 6 → 7.
 * @param into the LinkedList to weave the other into
 * @param linkedList the LinkedList to weave into another
 * @return true if either list changed
 * @author Rasmus Nylander, s205418
 */
bool interweaveLinkedList(LinkedList *into, LinkedList *linkedList);
/**
 * Shuffles the specified LinkedList pseudo-randomly.
 * @param linkedList the LinkedList to shuffle
 * @return true if the list changed
 * @author Rasmus Nylander, s205418
 */
bool shuffle(LinkedList *linkedList);
/**
 * Swaps the two elements at the specified indices in the
 * specified LinkedList. The list is unchanged if either
 * index is invalid.
 * @param linkedList the LinkedList in which to swap to element
 * @param i the index of the first element
 * @param j the index of the other element
 * @return true is the list changed
 * @author Rasmus Nylander, s205418
 */
bool swap(LinkedList *linkedList, int i, int j);

/**
 * Sorts the list in acceding order. Requires the list
 * to have been assigned a comparator; if the list has
 * not been assigned a comparator the list cannot be
 * sorted.
 * @param linkedList the LinkedList to sort
 * @return true if the list is sorted
 */
bool sort(LinkedList *linkedList);

/**
 * Empties the list.
 * <p>
 * <b>Note:</b> does not free the memory used
 * by the list elements
 * @param linkedList the LinkedList to clear
 * @return true if the list changed
 */
bool clearList(LinkedList *linkedList);

/**
 * Frees the memory used by the list.
 * <b>Note:</b> this does not include the memory
 * used be the list's elements
 * <p>
 * <b>Note:</b> this includes the list's Nodes
 * @param linkedList the LinkedList to destroy
 */
void destroyList(LinkedList *linkedList);

/**
 * Returns whether the specified LinkedList is empty
 * @param linkedList the LinkedList to determine if empty
 * @return true if the specified list is empty
 */
bool isEmpty(LinkedList *linkedList);



#endif //YUKON_LINKEDLIST_H
