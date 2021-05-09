//
// Created by Tobias Maneschijn, on 16/04/2021.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "command_utils.h"
#include "../utils/strutils.h"
#include "commands.h"

#define COMMAND_LD "LD"
#define COMMAND_SW "SW"
#define COMMAND_SI "SI"
#define COMMAND_SR "SR"
#define COMMAND_SD "SD"
#define COMMAND_P "P"
#define COMMAND_Q "Q"
#define COMMAND_QQ "QQ"

char *RunCommand(char *str)
{
    const char delim[] = " ";
    char *firstWord = strtok(str, delim);
    char *secondWord = strtok(NULL, delim);

    char *firstWordCpy;

    if (strlen(firstWord) > 0)
    {

        // Remove leading and trailing whitespaces
        trim(firstWord);
        trim(secondWord);

        lastCommand = firstWord;

        // add if else ladder here with command checks
        if (strcmp(lastCommand, COMMAND_LD) == 0)
        {
            return LD(secondWord);
        }
        else if (strcmp(lastCommand, COMMAND_SW) == 0)
        {
            return (SW());
        }
        else if (strcmp(lastCommand, COMMAND_SI) == 0)
        {
            // PrintConsoleMenu( SI(atoi(secondWord)));
        }
        else if (strcmp(lastCommand, COMMAND_SR) == 0)
        {
            return (SR());
        }
        else if (strcmp(lastCommand, COMMAND_SD) == 0)
        {
            return (SD(secondWord));
        }
        else if (strcmp(lastCommand, COMMAND_P) == 0)
        {
            return (P());
        }
        else if (strcmp(lastCommand, COMMAND_QQ) == 0)
        {
            return (QQ());
        }
        else if (strcmp(lastCommand, COMMAND_Q) == 0)
        {
            return (Q());
        }
        else
        {
            return ("The command was not found! Try again...");
        }
    }
    else
    {
        return ("You have to write a command!");
    }
}

