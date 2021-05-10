//
// Created by Nylander on 01-05-2021.
//

#ifndef YUKON_GAME_H
#define YUKON_GAME_H

#define NUM_COLUMNS_IN_GAME 7

#include "../deck/deck.h"

typedef struct game* Game;

/**
 * Creates a new Game and returns it
 * @return a new Game or null if memory allocation fails
 * @author Rasmus Nylander, s205418
 */
Game newGame();
/**
 * Saves the specified Game to the specified file
 * @param game the Game to save
 * @param filename the path of the file to save the game to
 * @return true if the game was successfully saved
 * @author Rasmus Nylander, s205418
 */
bool saveGameToFile(Game game, char* filename);
/**
 * Loads the Game saved in the specified file and returns it
 * @param filename the path to where the Game has been saved
 * @return 	a new Game loaded from the specified file, or NULL if
 * 			unsuccessful
 * @author Rasmus Nylander, s205418
 */
Game loadGameFromFile(char* filename);

/**
 * Returns the Deck of the specified Game
 * @param game the Game whose Deck is desired
 * @return the Deck of the specified Game
 * @author Rasmus Nylander, s205418
 */
Deck getDeck(Game game);

/**
 * Returns the Deck of the specified Game in the same format
 * as get columns, as if the cards were dealt by placing one
 * card in each column left to right until no cards remain.
 * @param game the Game which Deck is desired
 * @return 	the Deck of the specified Game in the same format
 * 			as getColumns
 * @author Rasmus Nylander, s205418
 */
Deck* getDeckAsColumns(Game game);

/**
 * Sets the Deck of the specified Game to the specified
 * Deck. NB the old Deck is NOT freed!
 * @param game the Game whose deck it to be set
 * @param deck new Deck of the specified Game
 * @return true if the game changed
 * @author Rasmus Nylander, s205418
 */
bool setDeck(Game game, Deck deck);

/**
 * Returns a pointer to the columns of the specified
 * Game
 * @param game the Game whose columns are desired
 * @return a pointer to the columns of the game
 * @author Rasmus Nylander, s205418
 */
Deck* getColumns(Game game);

/**
 * Returns a pointer to the finished-decks of the specified
 * Game
 * @param game the Game whose finished-decks are desired
 * @return a pointer to the finished-decks of the game
 * @author Rasmus Nylander, s205418
 */
Deck* getFinished(Game game);

/**
 * Deals the cards of the specified Game
 * @param game the Game which cards are to be dealt
 * @author Rasmus Nylander, s205418
 */
void dealCards(Game game);

/**
 * Starts the specified Game, i.e. deals the cards,
 * and returns if successful
 * @param game the Game to start
 * @return true if the Game was started
 */
bool startGame(Game game);

/**
 * Empties the columns and finished decks of the game
 * and turns the cards in the deck to face down.
 * @param game the game to pseudo-end
 */
void unstartGame(Game game);


#endif //YUKON_GAME_H
