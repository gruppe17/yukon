//
// Created by Tobias Maneschijn on 23/04/2021.
//

#ifndef YUKON_COMMANDS_H
#define YUKON_COMMANDS_H

#include "../deck/deck.h"
#include "../game/game.h"

/**
 * Load a deck of cards
 * @param filename
 * @author Tobias Maneschijn, s205422
 */
char* LD(Game game, char *filename);

/**
 * Turns all the cards face up
 * @param game the game whose Deck is to be turned face-up
 * @author Rasmus Nylander, s205418
 */
char* SW(Game game);

 /**
  * Shuffles the deck of a Game in an interleaved manner
  * @param game 		the Game which Deck to shuffle
  * @param parameters 	a string representation of an integer
  * 					determining where to split the deck
  * @return 			A string describing what happened
  * @author Rasmus Nylander, s205418
  */
char* SI(Game game, char *parameters);

/**
 * Shuffles the card in a random manner
 * @author Rasmus Nylander, s205418
 */
char* SR(Game game);

/**
 * Save the cards from the current deck to a file
 * @param filename the file to save to
 * @author Tobias Maneschijn, s205422
 */
char* SD(Game game, char *filename);

/**
 * Quit the program
 * @author Tobias Maneschijn, s205422
 * */
char* QQ();

/**
 * Starts the specified game
 * @author Rasmus Nylander, s205418
 */
char* P(Game game);

/**
 * Stops the specified game and goes back to startup phase
 * @param Game the Game to stop
 * @author Rasmus Nylander, s205418
 */
char* Q(Game game);

/**
 * Move card
 * @param from
 * @param to
 * @author Tobias Maneschijn, s205422
 */
char* move(Game game, char *from, char *to);

#endif //YUKON_COMMANDS_H
