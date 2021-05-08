//
// Created by Tobias Maneschijn on 23/04/2021.
//

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 16384

void trim(char * string) {
    char *p = string;

    if(!p)
        return;

    int l = strlen(p);

    while (isspace(p[l - 1])) p[--l] = 0;
    while (*p && isspace(*p)) ++p, --l;

    memmove(string, p, l + 1);
}

char readStringBuffer[MAX_STRING_LENGTH];
char *ReadString() {
	fgets(readStringBuffer, sizeof(readStringBuffer), stdin);
	unsigned int stringLength = strlen(readStringBuffer);
	char* string = (char*) malloc((stringLength + 1) * sizeof(char));
	strcpy(string, readStringBuffer);
	return string;
}

char* newString(unsigned long long length){
	char *string = NULL;
	while (string == NULL) string = calloc(length + 1, sizeof(char));
	return string;
}