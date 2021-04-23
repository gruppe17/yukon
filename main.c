
// Library includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Project includes
#include "deck/deck.h"
#include "commands/command.h"
#include "utils/strutils.h"


int main() {

    PrintConsoleMenu("Welcome to Yukon!");

    bool shouldClose = false;

    while(!shouldClose){

        char *str= ReadString();
        trim(str);
        if(strcmp("exit", str) == 0){
            shouldClose = true;
        }

        GetCommandFromString(str);
    }

	return 0;
}