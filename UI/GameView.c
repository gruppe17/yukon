//
// Created by Nylander on 07-05-2021.
//

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "GameView.h"
#include "GameViewConstants.h"
#include "GameViewInternalFunctions.h"
#include "../utils/integerUtils.h"
#include "../utils/strutils.h"

char* gameToDisplayString(Game game){
	char* buffer = newString(1024);
	int numColumns = NUM_COLUMNS_IN_GAME;
	int numFinishedDecks = PLAYING_CARD_NUM_SUITS;

	unsigned long long headerEnd = writeColumnHeaders(numColumns, buffer);

	Deck* columns = getColumns(game);
	if (getTallestColumnHeight(columns, numColumns) == 0){
		columns = getDeckAsColumns(game);
	}

	writeColumns(columns, numColumns, getFinished(game), numFinishedDecks, buffer + headerEnd);

	realloc(buffer, (strlen(buffer) + 1) * sizeof(char));
	return buffer;
}

unsigned long long writeColumnHeaders(int numColumns, char *str){
	char *headerText = getHeaderText(numColumns);
	unsigned long long length = strlen(headerText);
	strcpy(str, headerText);
	free(headerText);
	return length;
}

char* getHeaderText(int numColumns){
	unsigned long long headerLength =   numColumns * strlen(columnPrefix) +
										(numColumns - 1) * strlen(columnSpacer) +
	                                    numDigitsInRange(1, numColumns + 1, 10) +
	                                    strlen(headerSuffix) +
	                                    1; //Terminating null character
	char *headerText = NULL;
	while (headerText == NULL) headerText = (char *) malloc ((headerLength + 1) * sizeof(char));

	unsigned long long offset = 0;
	for (int i = 0; i < numColumns - 1; ++i) {
		offset += sprintf_s(headerText + offset, headerLength - offset, "%s%d%s", columnPrefix, i + 1, columnSpacer);
	}
	sprintf_s(headerText + offset, headerLength - offset, "%s%d%s", columnPrefix, numColumns, headerSuffix);
	return headerText;
}

unsigned long long writeColumns(Deck *columns, int numColumns, Deck *finishedDecks, int numFinishedDecks, char* str){
	//Todo: it would be preferable if each column was written instead of each row
	// then it would not be necessary to iterate through each list as much.
	// It would probably be necessary to do basically the same thing with
	// the string instead, so actually maybe this is fine?
	int height = getTallestColumnHeight(columns, numColumns);
	if (height < gameViewMinNumColumns) height = gameViewMinNumColumns;

	unsigned long long offset = 0;
	for (int i = 0; i < height; ++i) {
		offset += writeRow(i, columns, numColumns, str+offset);
		if (i % 2 == 0 && i / 2 < numFinishedDecks) {
			offset--;
			offset += writeFinishedDeck(finishedDecks[i / 2] , str + offset);
		}
	}
	return offset;
}

unsigned long long writeRow(int row, Deck *columns, int numColumns, char *str){
	//todo: this is basically identical to writeColumnHeaders. Do something about it; there is no need to have both
	char* rowText = getRowText(row, columns, numColumns);
	unsigned long long length = strlen(rowText);
	strcpy(str, rowText);
	free(rowText);
	return length;
}

char* getRowText(int row, Deck *columns, int numColumns){
	unsigned long long rowMaxLength =   (numColumns - 1) * strlen(columnSpacer) +
										numColumns * PLAYING_CARD_MAX_LENGTH_AS_STRING +
										strlen(rowSuffix) +
	                                    1; //Terminating null character
	char *rowTextBuffer = newString(rowMaxLength);
	unsigned long long offset = 0;
	for (int i = 0; i < numColumns; ++i) {
		char * cardText = getCardText(get(columns[i], row));
		offset += sprintf_s(rowTextBuffer + offset, rowMaxLength - offset, "%s%s", cardText, columnSpacer);
		free(cardText);
	}
	sprintf_s(rowTextBuffer + offset - 1, rowMaxLength - offset + 1, "%s", rowSuffix); //Remove last column spacer and write suffix
	return realloc(rowTextBuffer, offset + 1);
}

char *getCardText(PlayingCard card){
	if (card == NULL) return newString(0); //Return an empty string
	if (isFaceUp(card)) return playingCardToString(card);
	return strcpy(newString(strlen(hiddenCardText)), hiddenCardText);
}

int getTallestColumnHeight(Deck *columns, int numColumns){
	int maxSize = size(*columns);
	for (int i = 1; i < numColumns; ++i) {
		int contenderSize = size(*(columns + i));
		if (contenderSize > maxSize) maxSize = contenderSize;
	}
	return maxSize;
}

unsigned long long writeFinishedDeck(Deck finished, char *str){
	char* deckString = getFinishedDeckText(finished);
	unsigned long long length = strlen(deckString) + strlen(finishedColumnSpacer) + strlen(rowSuffix);
	sprintf(str,"%s%s%s", finishedColumnSpacer, deckString, rowSuffix);
	free(deckString);
	return length;
}

char* getFinishedDeckText(Deck deck){
	PlayingCard card = poll(deck);
	if (card == NULL) return strcpy(newString(strlen(hiddenCardText)), hiddenCardText);
	return playingCardToString(card);
}
