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

void destroyDeck(Deck deck){
	if (deck == NULL) return;
	int deckSize = size(deck);
	while (!isEmpty(deck)){
		free(pop(deck));
	}
	free(deck);
}

Deck loadDeckFromFile(char* fileName){
	return NULL;
}

bool saveDeckToFile(Deck deck, char* fileName){
	return false;
}

bool alignCards(Deck deck, bool faceUp){
	//todo: this maybe should be done with internal stuff
	// LinkedList should maybe have an applyFunctionToEach
	int length = size(deck);
	bool changed = false;
	for (int i = 0; i < length; ++i) {
		if (setFaceUp(get(deck, i), faceUp)) changed = true;
	}
	return changed;
}