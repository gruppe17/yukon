//
// Created by Nylander on 08-05-2021.
//

#ifndef YUKON_LINKEDLISTINTERNALFUNCTIONS_H
#define YUKON_LINKEDLISTINTERNALFUNCTIONS_H

typedef struct _node Node;

/**
 * Creates a new node containing the specified data and returns
 * a pointer to it or NULL if memory allocation failed.
 * @param data a pointer to the data the nodes should contain
 * @return a pointer to a new node containing the specified data
 * 			or NULL if memory allocation fails
 * @author Rasmus Nylander, s205418
 */
Node* newNode(void* data);
/**
 * Extract the data of a specified node and returns it.
 * If the node is NULL function returns NULL,
 * @param node the node to extract data from
 * @return the data contained in the node or NULL if the node is NULL
 * @author Rasmus Nylander, s205418
 */
void* extractData(Node* node);

Node* getLastNode(LinkedList *linkedList);
Node* getNodePtr(LinkedList *linkedList, int index);
Node** getNodePtrPtr(LinkedList *linkedList, int index);

bool appendToEmpty(LinkedList *appendTo, LinkedList *appending);

bool swapNodes(Node **a, Node **b);

#endif //YUKON_LINKEDLISTINTERNALFUNCTIONS_H
