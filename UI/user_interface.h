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
 */
void initDisplay(Game game);


#endif // USER_INTERFACE_H
