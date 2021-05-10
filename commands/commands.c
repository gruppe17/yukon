//
// Created by Tobias Maneschijn on 23/04/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"
#include "command_utils.h"
#include "../utils/strutils.h"


char* LD(Game game, char* filename){


    if(!filename || strlen(filename) < 0)
        return "You need to specify a filename";

    char out[255] = "Loading deck from file ";
    return strcat(out, filename) ;
}

char* SW(Game game) {

    return "SW was called";

}

char* SI(Game game, char *parameters) {
	char *output = newString(256);

	if (game == NULL || getDeck(game) == NULL) {
		sprintf(output, "SI was called but game has no deck");
		return output;
	}

	int split = size(getDeck(game))/2;
	trim(parameters);
	int length = strlen(parameters);
	if (length > 0){
		int parameter = atoi(parameters);
		if (parameter < 0 || parameter > size(getDeck(game))) {
			sprintf(output,
		   "SI was called with parameter %s, which resulted in an error. SI must be provided with an integer in the range 0 - %d",
		   parameters, size(getDeck(game)));
			return output;
		}
		split = parameter;
	}

	interweaveLinkedList(getDeck(game), cutEnd(getDeck(game), split));
    sprintf(output, "SI was called with parameter %i", split); //No parameter is the same as half the deck size
    return output;
}

char* SR(Game game) {
	char* output = newString(256);

	if (game == NULL || getDeck(game) == NULL) {
		sprintf(output, "SR was called but game has no deck");
		return output;
	}
	sprintf(output, "SR was called and deck was shuffled");
	return output;
}

char* SD(Game game, char *filename) {
    char* output = newString(256);
    sprintf(output, "Saving deck to file %s", filename);
    return output;
}

char* QQ() {
    shouldExit = true;
    return "Stopping program";
}

char* P() {

    return "Starting game";
}

char* Q(Game game)  {

    return "Stopping current game";
}