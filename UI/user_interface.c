#include "user_interface.h"
#include "user_input.h"
#include <stdio.h>
#include "GameView.h"
#include "../utils/strutils.h"
#include "../commands/command_utils.h"
#include <string.h>

const char consoleMenuText[] = "Last command: %s\nMessage: %s\nInput:> ";
const int numVariablesConsoleMenuText = 2;

void displayGame(Game game, char* commandStr) {
    gameToDisplayString(game);
    printConsoleMenu(commandStr);
}

void initDisplay(Game game) {
	char* string = gameToDisplayString(game);
	printf("%s", string);
    printConsoleMenu("Welcome to Yukon!");    
}

char* consoleMenuString(char* message){
	char *string = newString(strlen(consoleMenuText) + strlen(lastCommand) + strlen(message));
	sprintf(string, consoleMenuText, lastCommand, message);
	return string;
}
