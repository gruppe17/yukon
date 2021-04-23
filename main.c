
// Library includes
#include <stdio.h>
#include <stdlib.h>

// Project includes
#include "deck/deck.h"
#include "commands/command_ui.h"
#include "utils/strutils.h"
#include "LinkedList/LinkedList.h"

#define NUM_COLUMNS_IN_GAME 7

int main() {
    PrintConsoleMenu("Welcome to Yukon!");
    LinkedList *decks = newLinkedList();


    shouldExit = false;

    while(!shouldExit){
        char *str = ReadString();
        GetCommandFromString(str);
    }

	return 0;
}