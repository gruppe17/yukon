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
		return newStringFromString("Cannot load a new deck now");
	}

    if(!filename || strlen(filename) < 0){
        setDeck(game, newStandardDeck());
    	return newStringFromString("Loaded a new standard deck");
    }
    Deck deck = loadDeckFromFile(filename);
	if (deck == NULL) return newStringFromString("Could not load deck. Check that the filename was correct");
	setDeck(game, deck);
    char out[255] = "Loading deck from file ";
    return strcat(out, filename) ;
}

char* SW(Game game) {
	if (isStarted(game)) return newStringFromString("I'm sorry Dave, I'm afraid I can't do that.");
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
	if(startGame(game)) return newStringFromString("Starting game");
    return newStringFromString("Could not start game");
}

char* Q(Game game)  {
	if (unstartGame(game)) return newStringFromString("Quitting current game");
    return newStringFromString("Could not quit current game");
}

const char *invalidMove = "Invalid move";
const char *moveDelimiter = ":";


char* move(Game game, char *from, char *to){
	if (!isStarted(game)) return newStringFromString("Cannot make a move before game has begun");
	//This should be done much better but there is no time
	if ((from[0] != 'C' && from[0] != 'F') || (to[0] != 'C' && to[0] != 'F')) return newStringFromString(invalidMove);

	char * fromColumn = strtok(from, moveDelimiter);
	char * fromCard = strtok(NULL, moveDelimiter);

	char * toColumn = strtok(to, moveDelimiter);
	if (strcmp(fromColumn, toColumn) == 0) return newStringFromString(invalidMove);

	int columnFrom = atoi(&fromColumn[1]) - 1;
	int columnTo = atoi(&toColumn[1]) - 1;
	if (columnFrom < 0 || columnTo < 0 || columnFrom > NUM_COLUMNS_IN_GAME || columnTo > NUM_COLUMNS_IN_GAME)
		return newStringFromString(invalidMove);
	if ((from[0] == 'F' && columnFrom > PLAYING_CARD_NUM_SUITS) || (to[0] == 'F' && columnTo > PLAYING_CARD_NUM_SUITS))
		return newStringFromString(invalidMove);

	Deck* columns = getColumns(game);
	Deck toDeck;
	if (toColumn[0] == 'F'){
		toDeck = getFinished(game)[columnTo];
	}
	else toDeck = columns[columnTo];

	//Should use comparator thingy
	int deckIndex = size(columns[columnFrom]) - 1;
	if (deckIndex < 0) return newStringFromString(invalidMove);
	PlayingCard card;
	if (fromCard == NULL) card = getLast(columns[columnFrom]);
	else{
		for (; deckIndex >= 0; deckIndex--) {
			card = get(columns[columnFrom], deckIndex);
			if (!isFaceUp(card)) break;
			char *cardString = playingCardToString(card);
			if (strcmp(cardString, fromCard) == 0){
				free(cardString);
				break;
			}
			free(cardString);
		}
	}
	PlayingCard cardEndTo = getLast(toDeck);
	if ( (cardEndTo == NULL && getCardSize(card) == 12) ||
			(getCardSize(cardEndTo) > getCardSize(card) && isDifferentSuit(card, cardEndTo))){
		append(toDeck, cutEnd(columns[columnFrom], deckIndex));
		return newStringFromString("Move successful");
	}
	return newStringFromString(invalidMove);
}