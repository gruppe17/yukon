#include "user_interface.h"
#include "user_input.h"
#include <stdio.h>
#include <stdlib.h>
#include "GameView.h"
#include "../utils/strutils.h"
#include "../commands/command_utils.h"
#include <string.h>
#include <windows.h>

const char consoleMenuText[] = "Last command: %s\nMessage: %s\nInput:> ";
const int numVariablesConsoleMenuText = 2;

void clearScreen(){
	system("cls");
	Sleep(25);
}

void displayGame(Game game, char* commandStr) {
	clearScreen();
	char *stringGame = gameToDisplayString(game), *stringMenu = consoleMenuString(commandStr);
	printf("%s%s", stringGame, stringMenu);
	free(stringGame);
	free(stringMenu);
}

void initDisplay(Game game) {
	displayGame(game, "Welcome to Youkon!");
}

char* consoleMenuString(char* message){
	char *lastCommand = getLastCommand();
	char *string = newString(strlen(consoleMenuText) - 2*numVariablesConsoleMenuText + strlen(lastCommand) + strlen(message));
	sprintf(string, consoleMenuText, lastCommand, message);
	free(lastCommand);
	return string;
}
