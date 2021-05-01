//
// Created by Nylander on 01-05-2021.
//

#include "game.h"
#include <stdlib.h>

#define NUM_COLUMNS_IN_GAME 7
const int numCardsInColumns[NUM_COLUMNS_IN_GAME] = {1, 6, 7, 8, 9, 10, 11};

/**
 * Saves the columns of the specified Game to the specified file
 * @param game the game whose columns are to be saved
 * @param filename the name of the file in which to save the game's columns
 * @return True if the game's columns were successfully saved
 * @author Rasmus Nylander, s205418
 */
BOOL saveGameColumnsToFile(Game game, char *filename);
/**
 * Saves the "finished-deck"s of the specified Game to the specified file
 * @param game the game whose "finished-deck"s are to be saved
 * @param filename the name of the file in which to save the game's "finished-deck"s
 * @return True if the game's "finished-deck"s were successfully saved
 * @author Rasmus Nylander, s205418
 */
BOOL saveGameFinishedToFile(Game game, char *filename);
/**
 * Saves the specified array of Decks to the specified file
 * @param decks the array of decks to save
 * @param length the length of the array
 * @param filename the name of the file in which to save the array
 * @return true if the array was successfully saved
 * @author Rasmus Nylander, s205418
 */
BOOL saveDeckArrayToFile(Deck decks[], int length, char *filename);
/**
 * Saves the stack of moves of the specified Game to the specified file
 * @param game the game whose stack of moves are to be saved
 * @param filename the name of the file in which to save the game's stack of moves
 * @return True if the game's stack of moves were successfully saved
 * @author Rasmus Nylander, s205418
 */
BOOL saveGameMovesToFile(Game game, char *filename);

struct game {
	Deck columns[NUM_COLUMNS_IN_GAME];
	Deck finished[PLAYING_CARD_NUM_SUITS];
	LinkedList *moves;
};

Game newGame(){
	Game newGame = malloc(sizeof(struct game));
	if (newGame == NULL) return NULL;
	for (int i = 0; i < NUM_COLUMNS_IN_GAME; ++i) {
		newGame->columns[i] = newDeck();
	}
	for (int i = 0; i < PLAYING_CARD_NUM_SUITS; ++i) {
		newGame->finished[i] = newDeck();
	}
	newGame->moves = newLinkedList();
}



BOOL saveGameToFile(Game game, char* filename){
	//Todo: check if valid file
	return  saveGameColumnsToFile(game, filename) &&
			saveGameFinishedToFile(game, filename) &&
			saveGameMovesToFile(game, filename);
}

BOOL saveGameColumnsToFile(Game game, char *filename){
	return saveDeckArrayToFile(game->columns, NUM_COLUMNS_IN_GAME, filename);
}

BOOL saveGameFinishedToFile(Game game, char *filename){
	return saveDeckArrayToFile(game->finished, PLAYING_CARD_NUM_SUITS, filename);
}

BOOL saveDeckArrayToFile(Deck decks[], int length, char *filename){
	BOOL successful = TRUE;
	for (int i = 0; i < length; ++i) {
		if (!saveDeckToFile(decks[i], filename)) successful = FALSE;
	}
	return successful;
}

BOOL saveGameMovesToFile(Game game, char *filename){
	return FALSE;
}