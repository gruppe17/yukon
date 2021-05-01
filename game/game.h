//
// Created by Nylander on 01-05-2021.
//

#ifndef YUKON_GAME_H
#define YUKON_GAME_H


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
 * @return True if the game was successfully saved
 * @author Rasmus Nylander, s205418
 */
BOOL saveGameToFile(Game game, char* filename);
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
 * Sets the Deck of the specified Game to the specified
 * Deck. NB the old Deck is NOT freed!
 * @param game the Game whose deck it to be set
 * @param deck new Deck of the specified Game
 * @return True if the game changed
 * @author Rasmus Nylander, s205418
 */
BOOL setDeck(Game game, Deck deck);

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


#endif //YUKON_GAME_H
