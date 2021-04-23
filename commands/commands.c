//
// Created by Tobias Maneschijn on 23/04/2021.
//

#include <stdio.h>
#include <string.h>
#include "commands.h"


char* LD(char* filename){


    if(!filename)
        return "You need to specify a filename";

    if(strlen(filename) < 0)
        return "You need to specify a filename";

    char* out;
    sprintf(out, "Loading deck from file %s", filename);
    return out;
}

char* SW() {

    return "SW was called";

}

char* SI(int split) {


    char* out;
    sprintf(out, "SI was called with split %i", split);
    return out;

}

char* SR() {

    return "SR was called";
}

char* SD(char *filename) {

    char* out;
    sprintf(out, "Saving deck to file %s", filename);
    return out;
}

char* QQ() {

    return "Stopping program";
}

char* P() {

    return "Starting game";
}

char* Q()  {

    return "Stopping current game";
}

