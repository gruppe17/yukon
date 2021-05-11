//
// Created by Nylan on 09-04-2021.
//

#include <stdlib.h>
#include <string.h>
#include "playingCard.h"
#include "../utils/integerUtils.h"
#include "../utils/strutils.h"

#define BITS_FOR_SUITS 2
#define BITS_FOR_CARDS_IN_SUIT 4

struct playingCard{
	unsigned int suit : BITS_FOR_SUITS;
	unsigned int number : BITS_FOR_CARDS_IN_SUIT;
	bool faceUp : 1;
};

void writePlayingCardSuitToString(PlayingCard card, char *string);
void writePlayingCardNumberToString(PlayingCard card, char* string);

PlayingCard newCard(unsigned char suit, unsigned char number){
	if (suit >= PLAYING_CARD_NUM_SUITS || number >= PLAYING_CARD_NUM_CARDS_IN_SUIT) {
		//Do something! This can't be tolerated!
		return NULL;
	}
	PlayingCard card = (PlayingCard) malloc(sizeof(struct playingCard));
	if (card == NULL) return NULL;
	card->suit = suit;
	card->number = number;
	card->faceUp = false;
	return card;
}

bool isFaceUp(PlayingCard card){
	return card->faceUp;
}

bool setFaceUp(PlayingCard card, bool up){
	if (isFaceUp(card) == up) return false;
	card->faceUp = up;
	return true;
}

int getCardSize(PlayingCard card){
	return card->number;
}

bool isDifferentSuit(PlayingCard cardA, PlayingCard cardB){
	return cardA->suit != cardB->suit;
}

bool flipPlayingCard(PlayingCard card){
	return setFaceUp(card, !isFaceUp(card));
}

char* playingCardToString(PlayingCard card){
	char *cardNumberString = playingCardNumberToString(card);
	if (cardNumberString == NULL) return NULL;

	int numberStringLength = strlen(cardNumberString);
	char *cardString = realloc(cardNumberString,  (numberStringLength + 2) * sizeof (char));
	if (cardString == NULL){
		cardString = malloc(numberStringLength + 2);
		if (cardString == NULL) {
			free(cardNumberString);
			return NULL;
		}
		strcpy(cardString, cardNumberString);
		free(cardNumberString);
	}
	writePlayingCardSuitToString(card, cardString + numberStringLength);
	*(cardString + numberStringLength + 1) = 0;

	return cardString;
}

//This should also use a dictionary or something
char* playingCardSuitToString(PlayingCard card){
	char *suitString = newString(2);
	writePlayingCardSuitToString(card, suitString);
	return suitString;
}

void writePlayingCardSuitToString(PlayingCard card, char *string){
	char suit;
	switch (card->suit) {
		case 0:
			suit = 'C';
			break;
		case 1:
			suit = 'D';
			break;
		case 2:
			suit = 'H';
			break;
		case 3:
			suit = 'S';
			break;
	}
	*string = suit;
}

char* playingCardNumberToString(PlayingCard card){
	int stringLength = 1;
	if (card->number == 9) stringLength++;
	char *numberString = newString(stringLength);

	*(numberString + stringLength) = 0;
	writePlayingCardNumberToString(card, numberString);
	return numberString;
}

//This should use a dictionary or something
void writePlayingCardNumberToString(PlayingCard card, char* string) {
	int number = card->number;
	switch (number) {
		case 0:
			*string = 'A';
			break;
		case 10:
			*string = 'J';
			break;
		case 11:
			*string = 'Q';
			break;
		case 12:
			*string = 'K';
			break;
		default: {
			number++;
			int numDigits = getNumDecDigits(number);
			for (int i = numDigits - 1; i >= 0; --i) {
				*(string + i) = (number % 10) + 48;
				number /= 10;
			}
		}
	}
}