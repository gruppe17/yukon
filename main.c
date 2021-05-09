
// Library includes
#include <stdio.h>
#include <stdlib.h>

// Project includes
#include "deck/deck.h"
#include "commands/command_utils.h"
#include "utils/strutils.h"
#include "game/game.h"
#include "UI/GameView.h"
#include "UI/user_interface.h"


int main() {
	Game game = newGame();
	setDeck(game, newStandardDeck());
	shuffle(getDeck(game));
	dealCards(game);

	initDisplay(game);

    shouldExit = false;

    while(!shouldExit){
        char *str = ReadString();
        char* commandStr = RunCommand(str);
		displayGame(game, commandStr);
    }

	return 0;
}