//
// Created by Tobias Maneschijn on 16/04/2021.
//

#ifndef YUKON_COMMAND_UI_H
#define YUKON_COMMAND_UI_H

#include <stdbool.h>
#include "../game/game.h"
/**
 * Tries to run a command corresponding to the given string. 
 * If the command is found, then it will be called and then returns a string with a message.
 * If the command is not found, then it will return an error message.
 * @param str the char* pointer to compare with the command names.
 * @author Tobias Maneschijn, s205422
 */
char *RunCommand(Game game, char *str);

/**
 * Returns a copy of the last command called by the player.
 * @return a string containing the last command called by the player
 * @author Rasmus Nylander, s205418
 */
char* getLastCommand();

/**
 * Sets the last command called by the player to the
 * contents of the specified string.
 * @param commandString the string which contents will the new last command called by the player
 * @return true if the last command changed
 * @author Rasmus Nylander, s205418
 */
bool setLastCommand(char* commandString);

/**
 * Should the program close?
 */
bool shouldExit;
#endif //YUKON_COMMAND_UI_H
