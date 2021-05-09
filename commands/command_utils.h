//
// Created by Tobias Maneschijn on 16/04/2021.
//

#ifndef YUKON_COMMAND_UI_H
#define YUKON_COMMAND_UI_H

#include <stdbool.h>

/**
 * Tries to run a command corresponding to the given string. 
 * If the command is found, then it will be called and then returns a string with a message.
 * If the command is not found, then it will return an error message.
 * @param str the char* pointer to compare with the command names.
 * @author Tobias Maneschijn, s205422
 */
char *RunCommand(char *str);

/**
 * Last command called by player
 */
char *lastCommand;

/**
 * Should the program close?
 */
bool shouldExit;
#endif //YUKON_COMMAND_UI_H
