//
// Created by Tobias Maneschijn, on 16/04/2021.
//
#include <stdio.h>
#include <string.h>
#include "command.h"


#define MAX_STRING_LENGTH 16384

#define COMMAND_LD "LD"


void GetCommandFromString(char* str) {



    char delim[] = " ";

    char* firstWord = strtok(str, delim);

    char* firstWordCpy;


    if(firstWord && strlen(firstWord) > 1){
        printf("%s", firstWord);
        // add if else ladder here with command checks
        if(strcmp(firstWord, COMMAND_LD) == 0){
            PrintString("LD was called");
        }
        else{
            PrintString("The command was not found! Try again...");
        }

    }
    else{
        PrintString("You have to write a command!");
    }
}



char *ReadString() {
    char str[MAX_STRING_LENGTH];
    fgets(str, sizeof(str), stdin);
    return &str;
}

char *PrintString(char *in) {
    printf("LAST Command: %s \n", "TEMPORARY");
    printf("Message: %s \n", in);
    printf("Input:> ");
}




