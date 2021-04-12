//
// Created by Nylan on 09-04-2021.
//

#include <stdlib.h>
#include "playingCard.h"

typedef struct card{
	unsigned char topSuit : BITS_FOR_SUITS;
	unsigned char topNumber : BITS_FOR_CARDS_IN_SUIT;
} CARD;

CARD* NewCard(unsigned char suit, unsigned char number){
	if (suit >= NUM_SUITS || number >= NUM_CARDS_IN_SUIT) {
		//Do something! This can't be tolerated!
		return NULL;
	}
	CARD *newCardPtr;
	newCardPtr = (CARD *) malloc(sizeof(CARD));
	newCardPtr->topSuit = suit;
	newCardPtr->topNumber = number;
	return newCardPtr;
}