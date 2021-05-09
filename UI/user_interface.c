#include "user_interface.h"
#include "user_input.h"
#include <stdio.h>
#include "GameView.h"

void displayGame(Game* game, char* commandStr) {
    gameToDisplayString(game);
    printConsoleMenu(commandStr);
}

void initDisplay(Game* game) {
	char* string = gameToDisplayString(game);
	printf("%s", string);
    printConsoleMenu("Welcome to Yukon!");    
}
