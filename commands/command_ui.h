//
// Created by Tobias Maneschijn on 16/04/2021.
//

#ifndef YUKON_COMMAND_UI_H
#define YUKON_COMMAND_UI_H


#include <stdbool.h>

/**
 * Returns a command corresponding to the given string.
 * @author Tobias Maneschijn, s205422
 */
void GetCommandFromString(char* str);



/**
 * Prints a string
 * @param message the message to show
 * @param lastCommand
 * @author Tobias Maneschijn, s205422
 */

char *PrintConsoleMenu(char *message);

/**
 * Last command called by player
 */
char* lastCommand;

/**
 * If program should exit
 */
 bool shouldExit;
#endif //YUKON_COMMAND_UI_H
