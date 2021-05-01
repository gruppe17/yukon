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


#endif //YUKON_GAME_H
