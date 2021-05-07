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
char* LD(char *filename);

/**
 * Show all cards
 * @author Tobias Maneschijn, s205422
 */
char* SW();

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
 * @author Tobias Maneschijn, s205422
 */
char* SR();

/**
 * Save the cards from the current deck to a file
 * @param filename the file to save to
 * @author Tobias Maneschijn, s205422
 */
char* SD(char *filename);

/**
 * Quit the program
 * @author Tobias Maneschijn, s205422
 * */
char* QQ();

/**
 * Start game using current deck
  * @author Tobias Maneschijn, s205422
  * */
char* P();

/**
 * Stop current game and go back to startup phase
  * @author Tobias Maneschijn, s205422
  * */
char* Q();

/**
 * Move card
 * @param from
 * @param to
 * @author Tobias Maneschijn, s205422
 */
char* move(char *from, char *to);

#endif //YUKON_COMMANDS_H
