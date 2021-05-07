//
// Created by Nylander on 07-05-2021.
//

#ifndef YUKON_INTEGERUTILS_H
#define YUKON_INTEGERUTILS_H

/**
 * Calculate the number of digits the specified number has
 * when writen in the specified base
 * @param number the number to get the number of digits of
 * @param base the base in which to count the number of digits
 * @return 	an int containing the number of digits of the specified
 * 			number in the specified base
 * @author Rasmus Nylander, s205418
 */
int getNumDigits(int number, int base);

/**
 * Calculate the number of decimal digits the specified number has
 * @param number the number to get the number of decimal digits of
 * @return an int containing the number of decimal digits of the specified number
 * @author Rasmus Nylander, s205418
 */
int getNumDecDigits(int number);

/**
 * Calculates sum of the number of digits of the numbers in the range
 * from the specified start inclusive to the specified end exclusive
 * in the specified base and returns it.
 * @param start the start of the range inclusive
 * @param end the end of the range exclusive
 * @param base the base in which to calculate the number of digits
 * @return an unsigned long containing the number of digits
 * @author Rasmus Nylander, s205418
 */
unsigned long numDigitsInRange(int start, int end, int base);

#endif //YUKON_INTEGERUTILS_H
