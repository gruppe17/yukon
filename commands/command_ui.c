//
// Created by Tobias Maneschijn, on 16/04/2021.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "command_ui.h"
#include "../utils/strutils.h"
#include "commands.h"


#define MAX_STRING_LENGTH 16384

#define COMMAND_LD "LD"
#define COMMAND_SW "SW"
#define COMMAND_SI "SI"
#define COMMAND_SR "SR"
#define COMMAND_SD "SD"
#define COMMAND_P  "P"
#define COMMAND_Q  "Q"
#define COMMAND_QQ "QQ"



void GetCommandFromString(char* str) {
  const char delim[] = " ";
  const char* firstWord = strtok(str, delim);
  const char* secondWord =strtok(str, delim);

  char* firstWordCpy;


    if(strlen(firstWord) > 0){

        // Remove leading and trailing whitespaces
        trim(firstWord);
        trim(secondWord);

        lastCommand = firstWord;

        // add if else ladder here with command checks
        if(strcmp(lastCommand, COMMAND_LD) == 0){
            PrintConsoleMenu(LD(secondWord));
        }
        else if(strcmp(lastCommand, COMMAND_SW) == 0){
            PrintConsoleMenu( SW());
        }
        else if(strcmp(lastCommand, COMMAND_SI) == 0){
            PrintConsoleMenu( SI(atoi(secondWord)));
        }
        else if(strcmp(lastCommand, COMMAND_SR) == 0){
            PrintConsoleMenu( SR());
        }
        else if(strcmp(lastCommand, COMMAND_SD) == 0){
            PrintConsoleMenu(  SD(secondWord));
        }
        else if(strcmp(lastCommand, COMMAND_P) == 0){
            PrintConsoleMenu(  P());
        }
        else if(strcmp(lastCommand, COMMAND_QQ) == 0){
            PrintConsoleMenu( QQ());
        }
        else if(strcmp(lastCommand, COMMAND_Q) == 0){
            PrintConsoleMenu( Q());
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




