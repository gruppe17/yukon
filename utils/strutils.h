//
// Created by Tobias Maneschijn on 23/04/2021.
//

#ifndef YUKON_STRUTILS_H
#define YUKON_STRUTILS_H

/**
 * Removes trailing and leading whitespace from a string
 * @param string
 * @author Tobias Maneschijn, s205422
 */
void trim(char *string);

/**
 * Reads a string from the console and returns it
 * @author Tobias Maneschijn, s205422
 * @author Rasmus Nylander, s205418
 */
char* ReadString();

/**
 * Allocates memory for a new string of the specified length
 * and returns a pointer to it
 * @param length the length of the string excluding the terminating null character
 * @return a char* pointer to the string
 * @author Rasmus Nylander, s205418
 */
char* newString(unsigned long long length);

#endif //YUKON_STRUTILS_H
