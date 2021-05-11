//
// Created by Tobias Maneschijn on 23/04/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"
#include "command_utils.h"
#include "../utils/strutils.h"


char* LD(Game game, char* filename){
	if (game == NULL || isStarted(game)){
		return newStringFromString("Cannot load a new deck");
	}

	destroyDeck(getDeck(game));
    if(!filename || strlen(filename) < 0){
        setDeck(game, newStandardDeck());
    	return newStringFromString("Loaded a new standard deck");
    }
    Deck deck = loadDeckFromFile(filename);
	if (deck == NULL) return newStringFromString("Could not load deck");

    setDeck(game, deck);
    char out[255] = "Loading deck from file ";
    return strcat(out, filename) ;
}

char* SW(Game game) {
	char* output = newString(256);

	if (game == NULL || getDeck(game) == NULL){
		sprintf(output, "Game has no deck and thus its cards cannot be shown");
		return output;
	}
	Deck deck = getDeck(game);
	int deckSize = size(deck);
	for (int i = 0; i < deckSize; ++i) {
		setFaceUp(get(deck, i), true);
	}
    return newStringFromString("SW was called and executed correctly");
}

char* SI(Game game, char *parameters) {
	char *output = newString(256);

	if (game == NULL || getDeck(game) == NULL) {
		sprintf(output, "SI was called but game has no deck");
		return output;
	}

	int split = size(getDeck(game))/2;
	trim(parameters);
	if (parameters != NULL && strlen(parameters)  > 0){
		int parameter = atoi(parameters);
		if (parameter < 0 || parameter > size(getDeck(game))) {
			sprintf(output,
		   "SI was called with parameter %s, which resulted in an error. SI must be provided with an integer in the range 0 - %d",
		   parameters, size(getDeck(game)));
			return output;
		}
		split = parameter;
	}

	interweaveLinkedList(getDeck(game), cutEnd(getDeck(game), split));
    sprintf(output, "SI was called with parameter %i", split); //No parameter is the same as half the deck size
    return output;
}

char* SR(Game game) {
	char* output = newString(256);

	if (game == NULL || getDeck(game) == NULL) {
		sprintf(output, "SR was called but game has no deck");
		return output;
	}
	shuffle(getDeck(game));
	sprintf(output, "SR was called and deck was shuffled");
	return output;
}

char* SD(Game game, char *filename) {
	Deck deck;
	if (game == NULL || (deck = getDeck(game)) == NULL) return newStringFromString("Game has no deck to save");
    char* output = newString(256);
	if (!saveDeckToFile(deck, filename)){
		sprintf(output, "Deck could not be saved to %s", filename);
		return output;
	}
    sprintf(output, "Deck was saved to file %s", filename);
    return output;
}

char* QQ() {
    setShouldExit(true);
    return newStringFromString("Stopping program");
}

char* P(Game game) {
	if(startGame(game)) newStringFromString("Starting game");
    return newStringFromString("Could not start game");
}

char* Q(Game game)  {
	if (unstartGame(game)) newStringFromString("Quitting current game");
    return newStringFromString("Could not quit current game");
}