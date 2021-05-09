#include "user_input.h"
#include <stdio.h>
#include "../commands/command_utils.h"

char *printConsoleMenu(char *message)
{
    printf("LAST Command: %s \n", lastCommand);
    printf("Message: %s \n", message);
    printf("Input:> ");
}