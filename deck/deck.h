//
// Created by Nylander on 09-04-2021.
//

#ifndef YUKON_DECK_H
#define YUKON_DECK_H

#include "playingCard.h"

typedef int BOOL;

typedef struct _deck DECK;

DECK *NewDeck();

DECK *NewDeckElement(CARD* card);
DECK *NewDeckElement2(unsigned char suit, unsigned char number);

void InsertDeckElement(DECK** root, DECK * newElementPtr, int (*comparator)(void*, void*));
void InsertDeckElementBefore(DECK** deckElement, DECK *newElement);
void InsertDeckElementAtIndex(DECK** root, DECK * newElementPtr, int index);

BOOL RemoveCard(DECK** root, CARD *card);
BOOL DeleteCard(DECK** root, CARD *card);



#endif //YUKON_DECK_H
