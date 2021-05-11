//
// Created by Nylander on 01-05-2021.
//

#include "game.h"
#include <stdlib.h>

const int numCardsInColumns[NUM_COLUMNS_IN_GAME] = {1, 6, 7, 8, 9, 10, 11};
const int numShownCardsAtStart = 4;

/**
 * Saves the columns of the specified Game to the specified file
 * @param game the game whose columns are to be saved
 * @param filename the name of the file in which to save the game's columns
 * @return True if the game's columns were successfully saved
 * @author Rasmus Nylander, s205418
 */
bool saveGameColumnsToFile(Game game, char *filename);
/**
 * Saves the "finished-deck"s of the specified Game to the specified file
 * @param game the game whose "finished-deck"s are to be saved
 * @param filename the name of the file in which to save the game's "finished-deck"s
 * @return True if the game's "finished-deck"s were successfully saved
 * @author Rasmus Nylander, s205418
 */
bool saveGameFinishedToFile(Game game, char *filename);
/**
 * Saves the specified array of Decks to the specified file
 * @param decks the array of decks to save
 * @param length the length of the array
 * @param filename the name of the file in which to save the array
 * @return true if the array was successfully saved
 * @author Rasmus Nylander, s205418
 */
bool saveDeckArrayToFile(Deck decks[], int length, char *filename);
/**
 * Saves the stack of moves of the specified Game to the specified file
 * @param game the game whose stack of moves are to be saved
 * @param filename the name of the file in which to save the game's stack of moves
 * @return True if the game's stack of moves were successfully saved
 * @author Rasmus Nylander, s205418
 */
bool saveGameMovesToFile(Game game, char *filename);

/**
 * Clears the decks in the specified deck array
 * @param decks the array of decks to clear
 * @param size the number of elements in the array
 * @author Rasmus Nylander, s205418
 */
void emptyDeckArray(Deck* decks, int size);

struct game {
	Deck deck;
	Deck columns[NUM_COLUMNS_IN_GAME];
	Deck finished[PLAYING_CARD_NUM_SUITS];
	LinkedList *moves;
	bool hasStarted;
};

Game newGame(){
	Game newGame = malloc(sizeof(struct game));
	if (newGame == NULL) return NULL;
	newGame->deck = NULL;
	for (int i = 0; i < NUM_COLUMNS_IN_GAME; ++i) {
		newGame->columns[i] = newDeck();
	}
	for (int i = 0; i < PLAYING_CARD_NUM_SUITS; ++i) {
		newGame->finished[i] = newDeck();
	}
	newGame->moves = newLinkedList();
	newGame->hasStarted = false;
	return newGame;
}

bool saveGameToFile(Game game, char* filename){
	if (game->hasStarted)
	//Todo: check if valid file
	return  saveDeckToFile(getDeck(game), filename) &&
			saveGameColumnsToFile(game, filename) &&
			saveGameFinishedToFile(game, filename) &&
			saveGameMovesToFile(game, filename);
}

bool saveGameColumnsToFile(Game game, char *filename){
	return saveDeckArrayToFile(game->columns, NUM_COLUMNS_IN_GAME, filename);
}

bool saveGameFinishedToFile(Game game, char *filename){
	return saveDeckArrayToFile(game->finished, PLAYING_CARD_NUM_SUITS, filename);
}

bool saveDeckArrayToFile(Deck decks[], int length, char *filename){
	bool successful = true;
	for (int i = 0; i < length; ++i) {
		if (!saveDeckToFile(decks[i], filename)) successful = false;
	}
	return successful;
}

bool saveGameMovesToFile(Game game, char *filename){
	return false;
}

Deck getDeck(Game game){
	return game->deck;
}

bool setDeck(Game game, Deck deck){
	Deck oldDeck = getDeck(game);
	if (deck == oldDeck) return false;
	destroyDeck(getDeck(game));
	game->deck = deck;
	return true;
}

Deck* getDeckAsColumns(Game game){

	Deck* deckAsColumns = NULL;
	while (deckAsColumns == NULL) deckAsColumns = (Deck*) malloc(NUM_COLUMNS_IN_GAME * sizeof(Deck));
	for (int i = 0; i < NUM_COLUMNS_IN_GAME; ++i) {
		*(deckAsColumns + i) = newDeck();
	}

	Deck deck = getDeck(game);
	if (deck == NULL) return deckAsColumns;
	int deckSize = size(deck);
	for (int i = 0; i < deckSize; ++i) {
		add(*(deckAsColumns + (i % NUM_COLUMNS_IN_GAME)), get(deck, i));
	}
	return deckAsColumns;
}

Deck* getColumns(Game game){
	return game->columns;
}

Deck* getFinished(Game game){
	return game->finished;
}

bool isStarted(Game game){
	return game->hasStarted;
}

void dealCards(Game game){
	Deck cards = getDeck(game);
	emptyDeckArray(getFinished(game), PLAYING_CARD_NUM_SUITS);
	Deck* columns = getColumns(game);
	emptyDeckArray(columns, NUM_COLUMNS_IN_GAME);
	alignCards(cards, false);

	int numCardsAdded = 0;
	for (int i = 0; i < NUM_COLUMNS_IN_GAME; ++i) {
		for (int j = 0; j < numCardsInColumns[i]; ++j) {
			PlayingCard card = get(cards, numCardsAdded++);
			if (card == NULL) return;
			add(columns[i], card);
			if (numCardsInColumns[i] - j <= numShownCardsAtStart) flipPlayingCard(card);
		}
	}
}

void emptyDeckArray(Deck* decks, int size){
	for (int i = 0; i < size; ++i) {
		clearList(*(decks + i));
	}
}

bool startGame(Game game){
	if (game == NULL || getDeck(game) == NULL || isStarted(game)) return false;
	game->hasStarted = true;
	dealCards(game);
	return true;
}

bool unstartGame(Game game) {
	if (game == NULL || !isStarted(game)) return false;
	emptyDeckArray(getColumns(game), NUM_COLUMNS_IN_GAME);
	emptyDeckArray(getFinished(game), PLAYING_CARD_NUM_SUITS);
	clearList(game->moves);
	Deck deck = getDeck(game);
	int deckSize = size(deck);
	for (int i = 0; i < deckSize; ++i) {
		setFaceUp(get(deck, i), false);
	}
	game->hasStarted = false;
	return true;
}
