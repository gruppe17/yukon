
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
	//setDeck(game, newStandardDeck());

	initDisplay(game);

    while(!shouldExit()){
        char *str = ReadString();
        char* commandStr = RunCommand(game, str);
		displayGame(game, commandStr);
		free(commandStr);
    }

	return 0;
}