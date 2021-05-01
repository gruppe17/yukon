//
// Created by Nylan on 09-04-2021.
//

#include <stdlib.h>
#include "playingCard.h"

#define BITS_FOR_SUITS 2
#define BITS_FOR_CARDS_IN_SUIT 4

struct playingCard{
	unsigned int suit : BITS_FOR_SUITS;
	unsigned int number : BITS_FOR_CARDS_IN_SUIT;
};

PlayingCard* newCard(unsigned char suit, unsigned char number){
	if (suit >= PLAYING_CARD_NUM_SUITS || number >= PLAYING_CARD_NUM_CARDS_IN_SUIT) {
		//Do something! This can't be tolerated!
		return NULL;
	}
	PlayingCard *cardPtr = (PlayingCard *) malloc(sizeof(PlayingCard));
	if (cardPtr == NULL) return NULL;
	cardPtr->suit = suit;
	cardPtr->number = number;
	return cardPtr;
}

char* playingCardToString(PlayingCard* card){
	return "PlayingCardToString Not Implemented";
}