//
// Created by Tobias Maneschijn, on 16/04/2021.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "command.h"


#define MAX_STRING_LENGTH 16384

#define COMMAND_LD "LD"




void GetCommandFromString(char* str) {
  const char delim[] = " ";
  const char* firstWord = strtok(str, delim);

  char* firstWordCpy;

    if(firstWord && strlen(firstWord) > 1){
        trim(firstWord);
        lastCommand = firstWord;
        // add if else ladder here with command checks
        if(strcmp(lastCommand, COMMAND_LD) == 0){
            PrintConsoleMenu("LD was called");
        }
        else{
            PrintConsoleMenu("The command was not found! Try again...");
        }
    }
    else{
        PrintConsoleMenu("You have to write a command!");
    }
}



char *ReadString() {
    char str[MAX_STRING_LENGTH];
    fgets(str, sizeof(str), stdin);
    return &str;
}

char *PrintConsoleMenu(char *message) {
    printf("LAST Command: %s \n", lastCommand);
    printf("Message: %s \n", message);
    printf("Input:> ");
}




