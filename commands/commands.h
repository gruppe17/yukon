//
// Created by Tobias Maneschijn on 23/04/2021.
//

#ifndef YUKON_COMMANDS_H
#define YUKON_COMMANDS_H

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
 * Shuffles the cards in an interleaved manner
 * @param split How many piles to split
 * @author Tobias Maneschijn, s205422
 */
char* SI(int split);

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
