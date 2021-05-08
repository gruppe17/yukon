//
// Created by Nylander on 09-04-2021.
//

#include <stdlib.h>
#include "deck.h"


Deck newDeck(){
	Deck deck = newLinkedList();
	return deck;
}

Deck newStandardDeck(){
	Deck deck = newDeck();
	if (deck != NULL) fillDeck(deck);
	return deck;
}

bool fillDeck(Deck deck){
	if (deck == NULL) return false;
	for (int suit = 0; suit < PLAYING_CARD_NUM_SUITS; ++suit) {
		for (int cardNumber = 0; cardNumber < PLAYING_CARD_NUM_CARDS_IN_SUIT; ++cardNumber) {
			PlayingCard card = NULL;
			while (card == NULL) card = newCard(suit, cardNumber);
			add(deck, card);
		}
	}
	return true;
}

bool saveDeckToFile(Deck deck, char* fileName){
	return false;
}