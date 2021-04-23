#include <stdio.h>
#include <stdlib.h>
#include "LinkedList/LinkedList.h"
//#include "deck/deck.h"



int comparator(int* a, int* b){
	if (a < b) return -1;
	if (a == b) return 0;
	if (a > b) return 1;
}

void printIntList(LinkedList *linkedList){
	for (int i = 0; i < size(linkedList); ++i) {
		printf("%d ", get(linkedList, i));
	}
	printf("\n\n");
}

int main() {
	LinkedList* linkedList = newLinkedList();
	setComparator(linkedList, (int (*)(void *, void *)) &comparator);
	for (int i = 0; i < 64; ++i) {
		push(linkedList, i);
	}
	printIntList(linkedList);
	interweaveLinkedList(linkedList, cutEnd(linkedList, size(linkedList)/2));
	printIntList(linkedList);
	shuffle(linkedList);
	printIntList(linkedList);
	sort(linkedList);
	printIntList(linkedList);
	shuffle(linkedList);
	printIntList(linkedList);

	printf("Hello, World!\n");
	return 0;
}