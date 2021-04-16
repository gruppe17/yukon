//
// Created by Nylander on 09-04-2021.
//

#include <stdlib.h>
#include "deck.h"

#define TRUE 1;
#define FALSE 0;



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

BOOL InsertDeckElementAtIndex(DECK* root, DECK * newElementPtr, int index){
	if (newElementPtr == NULL) return FALSE;

	DECK *element = GetElementAtIndex(root, index - 1);
	if (element == NULL) return FALSE;
	MoveAfterToDeck(element, newElementPtr);
	element->next = newElementPtr;
	return TRUE;
}

DECK* GetElementAtIndex(DECK *header, int index){
	for (; index > 0; index--) {
		if (!header) break;
		header = header->next;
	}
	return header;
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

DECK* InterweaveDecks(DECK* a, DECK* b){
	if (a == NULL) return b;
	DECK* newDeckHead = a, *aNext;
	while (a != NULL && b != NULL){
		//Remember the next card in the a pile
		aNext = a->next;
		//Set the next card in the a pile to the next card in b pile
		a->next = b;
		//Move to the next pair of cards
		a = a->next;
		b = b->next;
		//Set the next card of the a pile to the original next card
		a->next = aNext;
		//Move a to point at this card
		a = a->next;
	}
	return newDeckHead;
}

int _randomComparator(void* a, void* b){
	return rand() % 2 == 0 ? -1 : 1;
}

void ShuffleDeck(DECK** deck){
	DECK* shuffledDeck = NULL;
	while (deck != NULL){
		DECK* deckElement = deck;
		deck = deck->next;
		deckElement->next = NULL;
		InsertDeckElement(&shuffledDeck, deckElement, (int (*)(DECK *, DECK *)) _randomComparator);
	}
	(*deck)=shuffledDeck;
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
