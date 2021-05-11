//
// Created by Tobias Maneschijn on 23/04/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "commands.h"
#include "command_utils.h"
#include "../utils/strutils.h"
#include "../UI/GameViewConstants.h"


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
	if (game == NULL || getDeck(game) == NULL) return newStringFromString("Game has no deck and thus its cards cannot be shown");
	if (isStarted(game)) return newStringFromString("I'm sorry Dave, I'm afraid I can't do that.");

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

bool isFinishedPrefix(char *prefix){
	return strcmp(prefix, finishedPrefix) == 0;
}

bool isValidColumnPrefix(char* prefix){
	if (strcmp(prefix, columnPrefix) == 0 || isFinishedPrefix(prefix)) return true;
	return false;
}

int getColumnNumber(char *column){
	return atoi(&column[strlen(columnPrefix)]);
}

bool isValidColumnNumber(int number, bool isFinishedDeck){
	if (number < 0) return false;
	if (isFinishedDeck) return number < PLAYING_CARD_NUM_SUITS;
	return number < NUM_COLUMNS_IN_GAME;
}

char* getColumnPrefix(char* column){
	//todo: should be more intelligent
	char *prefix = newString(1);
	prefix[0] = toupper(column[0]);
	return prefix;
}

bool isValidMoveSyntax(char* fromColumn, char *card, char *to){
	bool isValid = true;
	char *fromColumnPrefix = getColumnPrefix(fromColumn);
	char *toPrefix = getColumnPrefix(to);
	if (!isValidColumnPrefix(fromColumnPrefix) || !isValidColumnPrefix(toPrefix)) {
		free(fromColumnPrefix);
		free(toPrefix);
		isValid = false;
	}
	if (isValid &&
		(!isValidColumnNumber(getColumnNumber(fromColumn), isFinishedPrefix(fromColumn)) ||
	    !isValidColumnNumber(getColumnNumber(to), isFinishedPrefix(to)))) {
		isValid = false;
	}
	if (isValid && strcmp(fromColumn, to) == 0) isValid = false;

	free(fromColumnPrefix);
	free(toPrefix);

	return isValid;
}

Deck getDeckFromColumnText(Game game, char* text){
	if (isFinishedPrefix(getColumnPrefix(text))){
		return getFinished(game)[getColumnNumber(text)];
	}
	return getColumns(game)[getColumnNumber(text)];
}

bool cardMayMoveTo(PlayingCard card, PlayingCard to){
	if (card == NULL) return false;
	if ( (to == NULL && getCardSize(card) == 12)) return true;
	if ((getCardSize(to) > getCardSize(card) && isDifferentSuit(card, to))){
		return true;
	}
	return false;
}

//This should be done much better but there is no time
char* move(Game game, char *from, char *to){
	if (!isStarted(game)) return newStringFromString("Cannot make a move before game has begun");

	char * fromColumn = strtok(from, moveDelimiter);
	char * fromCard = strtok(NULL, moveDelimiter);
	//char * toColumn = strtok(to, moveDelimiter);
	trim(fromColumn);
	trim(fromCard);
	trim(to);

	if (!isValidMoveSyntax(from, fromCard, to)) return newStringFromString(invalidMove);

	Deck toDeck = getDeckFromColumnText(game, to);
	Deck fromDeck = getDeckFromColumnText(game, fromColumn);
	//Should use comparator thingy
	int deckIndex = size(fromDeck) - 1;
	if (deckIndex < 0) return newStringFromString(invalidMove);
	PlayingCard card;
	if (fromCard == NULL) card = getLast(fromDeck);
	else{
		for (; deckIndex >= 0; deckIndex--) {
			card = get(fromDeck, deckIndex);
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
	if (cardMayMoveTo(card, cardEndTo)){
		append(toDeck, cutEnd(fromDeck, deckIndex));
		return newStringFromString("Move successful");
	}
	return newStringFromString(invalidMove);
}