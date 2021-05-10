#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "../game/game.h"

/**
 * @brief 
 * Display the full game screen
 * @param game the game to display
 * @param commandStr the message from the last command
 * @author Tobias Maneschijn, s205422
 */
void displayGame(Game game, char* commandStr);

/**
 * @brief Shows the first screen
 * 
 * @param game the game to display
 * @author Tobias Maneschijn, s205422
 * @author Rasmus Nylander, s205418
 */
void initDisplay(Game game);

/**
 * Creates a new string containing the console menu
 * including the specified message.
 * @param message the message to display in the menu
 * @return a new string containing the console menu text
 * @author Rasmus Nylander, s205418
 */
char* consoleMenuString(char* message);


#endif // USER_INTERFACE_H
