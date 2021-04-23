//
// Created by Nylan on 09-04-2021.
//

#include <stdlib.h>
#include "playingCard.h"

typedef struct card{
	unsigned int suit : BITS_FOR_SUITS;
	unsigned int number : BITS_FOR_CARDS_IN_SUIT;
} CARD;

CARD* NewCard(unsigned char suit, unsigned char number){
	if (suit >= NUM_SUITS || number >= NUM_CARDS_IN_SUIT) {
		//Do something! This can't be tolerated!
		return NULL;
	}
	CARD *newCardPtr;
	newCardPtr = (CARD *) malloc(sizeof(CARD));
	newCardPtr->suit = suit;
	newCardPtr->number = number;
	return newCardPtr;
}