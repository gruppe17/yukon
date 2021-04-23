//
// Created by Tobias Maneschijn on 23/04/2021.
//

#include <string.h>
#include <ctype.h>

void trim(char * string) {
    char *p = string;

    if(!p)
        return;

    int l = strlen(p);

    while (isspace(p[l - 1])) p[--l] = 0;
    while (*p && isspace(*p)) ++p, --l;

    memmove(string, p, l + 1);
}