#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deck/deck.h"
#include "commands/command.h"


int main() {

    PrintString("Welcome to Yukon!");

    while(1){

        char *str= ReadString();
        GetCommandFromString(str);
    }

	return 0;
}