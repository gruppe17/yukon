//
// Created by Tobias Maneschijn, on 16/04/2021.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "command_utils.h"
#include "../utils/strutils.h"
#include "commands.h"

#define COMMAND_LD "LD"
#define COMMAND_SW "SW"
#define COMMAND_SI "SI"
#define COMMAND_SR "SR"
#define COMMAND_SD "SD"
#define COMMAND_P "P"
#define COMMAND_Q "Q"
#define COMMAND_QQ "QQ"

/**
 * The last command called by the player
 * @author Tobias Maneschijn, s205422
 */
char* lastCommand;
int lastCommandBufferSize = 0;

char* getLastCommand(){
	if (lastCommand == NULL) lastCommand = newString(0);
	char *lastCommandCopy = newString(strlen(lastCommand));
	strcpy(lastCommandCopy, lastCommand);
	return lastCommandCopy;
}

bool setLastCommand(char* commandString){
	if (commandString == NULL) return false;
	if (strlen(commandString) >= lastCommandBufferSize){
		free(lastCommand);
		lastCommand = newString(strlen(commandString));
	}
	strcpy(lastCommand, commandString);
	return true;
}

bool _shouldExit = false;
bool shouldExit(){
	return _shouldExit;
}

void setShouldExit(bool shouldExit){
	_shouldExit = shouldExit;
}

char *RunCommand(Game game, char *str)
{
    const char delim[] = " ";
    char *firstWord = strtok(str, delim);
    char *secondWord = strtok(NULL, delim);//Todo: This is never freed

    char *firstWordCpy;
    if (strlen(firstWord) > 0)
    {

        // Remove leading and trailing whitespaces
        trim(firstWord);
        trim(secondWord);

        setLastCommand(firstWord);
        // add if else ladder here with command checks
        if (strcmp(lastCommand, COMMAND_LD) == 0)
        {
            return LD(game, secondWord);
        }
        else if (strcmp(lastCommand, COMMAND_SW) == 0)
        {
            return (SW(game));
        }
        else if (strcmp(lastCommand, COMMAND_SI) == 0)
        {
            return SI(game, secondWord);
        }
        else if (strcmp(lastCommand, COMMAND_SR) == 0)
        {
            return (SR(game));
        }
        else if (strcmp(lastCommand, COMMAND_SD) == 0)
        {
            return (SD(game, secondWord));
        }
        else if (strcmp(lastCommand, COMMAND_P) == 0)
        {
            return (P(game));
        }
        else if (strcmp(lastCommand, COMMAND_QQ) == 0)
        {
            return (QQ());
        }
        else if (strcmp(lastCommand, COMMAND_Q) == 0)
        {
            return (Q(game));
        }
        else
        {
        	secondWord = strtok(NULL, "->");
        	trim(secondWord);
	        if (secondWord != NULL && strlen(secondWord) > 0){
		        return move(game, firstWord, secondWord);
	        }
	        return newStringFromString("The command was not found! Try again...");
        }
    }
    else
    {
        return newStringFromString("You have to write a command!");
    }
}
