
// Library includes
#include <stdio.h>
#include <stdlib.h>

// Project includes
#include "deck/deck.h"
#include "commands/command_ui.h"
#include "utils/strutils.h"
#include "LinkedList/LinkedList.h"


int main() {
    PrintConsoleMenu("Welcome to Yukon!");

    shouldExit = false;

    while(!shouldExit){
        char *str = ReadString();
        GetCommandFromString(str);
    }

	return 0;
}