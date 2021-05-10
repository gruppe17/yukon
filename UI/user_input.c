#include "user_input.h"
#include <stdio.h>
#include <stdlib.h>
#include "../commands/command_utils.h"
#include "user_interface.h"

void printConsoleMenu(char *message){
	char* consoleMenuString = consoleMenuString(message);
	printf("%s", consoleMenuString);
	free(consoleMenuString);
}