//
// Created by Tobias Maneschijn on 23/04/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"
#include "command_ui.h"
#include "../utils/strutils.h"


char* LD(char* filename){


    if(!filename)
        return "You need to specify a filename";

    if(strlen(filename) < 0)
        return "You need to specify a filename";

    char out[255] = "Loading deck from file ";
    return strcat(out, filename) ;
}

char* SW() {

    return "SW was called";

}

char* SI(Game game, char *parameters) {
	char out[256];

	if (game == NULL || getDeck(game) == NULL) {
		sprintf_s(out, 256, "SI was called but game has no deck");
		return out;
	}

	int split = size(getDeck(game))/2;
	trim(parameters);
	int length = strlen(parameters);
	if (length > 0){
		int parameter = atoi(parameters);
		if (parameter < 0 || parameter > size(getDeck(game))) {
			sprintf_s(out, 256, "SI was called with parameter %i, which resulted in an error. SI must be provided with an integer", split);
			return out;
		}
		split = parameter;
	}

	interweaveLinkedList(getDeck(game), cutEnd(getDeck(game), split));
    sprintf_s(out, 256, "SI was called with parameter %i", split);
    return out;
}

char* SR(Game game) {
	char out[256];

	if (game == NULL || getDeck(game) == NULL) {
		sprintf_s(out, 256, "SR was called but game has no deck");
		return out;
	}
	sprintf_s(out, 256, "SR was called and deck was shuffled");
	return out;
}

char* SD(char *filename) {
    char out[255];  
    sprintf(out, "Saving deck to file %s", filename);
    return out;
}

char* QQ() {
    shouldExit = true;
    return "Stopping program";
}

char* P() {

    return "Starting game";
}

char* Q()  {

    return "Stopping current game";
}