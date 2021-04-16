//
// Created by Nylander on 09-04-2021.
//

#include <stdlib.h>
#include "deck.h"

#define TRUE 1;
#define FALSE 0;

typedef struct _deck{
	CARD* card;

	struct _deck* next;
} DECK;

DECK *NewDeckElement(CARD* card) {
	DECK *newDeckElementPtr;
	newDeckElementPtr = (DECK *) malloc(sizeof(DECK));
	newDeckElementPtr->card = card;
	newDeckElementPtr->next = NULL;
	return newDeckElementPtr;
}

DECK *NewDeckElement2(unsigned char suit, unsigned char number) {
	CARD* card = NewCard(suit, number);
	if (card == NULL){
		return NULL;
	}
	return NewDeckElement(card);
}

void InsertDeckElement(DECK** root, DECK * newElementPtr, int (*comparator)(DECK*, DECK*) ){
	DECK ** tracer = root;
	while (tracer && comparator((*tracer), newElementPtr) < 1){
		tracer = &(*tracer)->next;
	}
	InsertDeckElementBefore(root, newElementPtr);
}

void InsertDeckElementBefore(DECK** deckElement, DECK *newElement){
	newElement->next = *deckElement;
	*deckElement = newElement;
}

void InsertDeckElementAtIndex(DECK** root, DECK * newElementPtr, int index){
	DECK ** tracer = root;
	for (int i = 0; i < index; ++i) {
		if (!tracer) break;
		tracer = &(*tracer)->next;
	}
	newElementPtr->next = *tracer;
	*tracer = newElementPtr;
}

BOOL RemoveCard(DECK** root, CARD *card){
	int found = FALSE;
	DECK *old;
	DECK **tracer = root;

	while ((*tracer) && !(found = (*tracer)->card == card )) tracer = &(*tracer)->next;

	if(found) {
		old = *tracer;
		*tracer = (*tracer)->next;
		free(old);
	}

	return found;
}

BOOL DeleteCard(DECK** root, CARD *card){
	if (!RemoveCard(root, card)) return FALSE;
	free(card);
	return TRUE;
}

DECK* CutDeckAfter(DECK* deck){
	DECK *cut = deck->next;
	deck->next = NULL;
	return cut;
}

BOOL MoveAfterToDeck(DECK* newEnd, DECK* newDeckHead){
	DECK *end = CutDeckAfter(newEnd);
	while (newDeckHead->next != NULL){
		newDeckHead = newDeckHead->next;
	}
	newDeckHead->next = end;
	return TRUE;
}

DECK *NewDeck(){
	DECK *deck = NULL, *tail;
	InsertDeckElementBefore(&deck, NewDeckElement2(0, 0));
	tail = deck;

	for (int suit = 0; suit < NUM_SUITS; ++suit) {
		for (int number = 1; number < NUM_CARDS_IN_SUIT; ++number) {
			InsertDeckElementBefore(&(tail->next), NewDeckElement2(suit, number));
			tail = tail->next;
		}
	}
	return deck;
}
