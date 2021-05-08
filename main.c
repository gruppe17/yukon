
// Library includes
#include <stdio.h>
#include <stdlib.h>

// Project includes
#include "deck/deck.h"
#include "commands/command_ui.h"
#include "utils/strutils.h"
#include "game/game.h"
#include "UI/GameView.h"


int main() {
	Game game = newGame();
	setDeck(game, newStandardDeck());
	shuffle(getDeck(game));
	dealCards(game);

	char* string = gameToDisplayString(game);
	printf("%s", string);

    PrintConsoleMenu("Welcome to Yukon!");

    shouldExit = false;

    while(!shouldExit){
        char *str = ReadString();
        GetCommandFromString(str);
    }

	return 0;
}