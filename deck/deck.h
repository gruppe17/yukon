//
// Created by Nylander on 09-04-2021.
//

#ifndef YUKON_DECK_H
#define YUKON_DECK_H

#include "playingCard.h"

typedef int BOOL;

typedef struct _deck{
	CARD* card;
	struct _deck* next;
} DECK;

DECK *NewDeck();

DECK *NewDeckElement(CARD* card);
DECK *NewDeckElement2(unsigned char suit, unsigned char number);

void InsertDeckElement(DECK** root, DECK * newElementPtr, int (*comparator)(DECK*, DECK*) );
void InsertDeckElementBefore(DECK** deckElement, DECK *newElement);
BOOL InsertDeckElementAtIndex(DECK* root, DECK * newElementPtr, int index);
DECK* GetElementAtIndex(DECK *header, int index);

BOOL RemoveCard(DECK** root, CARD *card);
BOOL DeleteCard(DECK** root, CARD *card);

DECK* CutDeckAfter(DECK* deck);
BOOL MoveAfterToDeck(DECK* newEnd, DECK* newDeckHead);
DECK* InterweaveDecks(DECK* a, DECK* b);
void ShuffleDeck(DECK** deck);


#endif //YUKON_DECK_H
