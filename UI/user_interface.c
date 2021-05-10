#include "user_interface.h"
#include "user_input.h"
#include <stdio.h>
#include <stdlib.h>
#include "GameView.h"
#include "../utils/strutils.h"
#include "../commands/command_utils.h"
#include <string.h>

const char consoleMenuText[] = "Last command: %s\nMessage: %s\nInput:> ";
const int numVariablesConsoleMenuText = 2;

void displayGame(Game game, char* commandStr) {
	char *stringGame = gameToDisplayString(game), *stringMenu = consoleMenuString(commandStr);
	printf("%s%s", stringGame, stringMenu);
	free(stringGame);
	free(stringMenu);
}

void initDisplay(Game game) {
	char* string = gameToDisplayString(game);
	printf("%s", string);
    printConsoleMenu("Welcome to Yukon!");    
}

char* consoleMenuString(char* message){
	char *lastCommand = getLastCommand();
	char *string = newString(strlen(consoleMenuText) + strlen(lastCommand) + strlen(message));
	sprintf(string, consoleMenuText, lastCommand, message);
	free(lastCommand);
	return string;
}
