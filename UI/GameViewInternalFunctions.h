//
// Created by Nylan on 08-05-2021.
//

#ifndef YUKON_GAMEVIEWINTERNALFUNCTIONS_H
#define YUKON_GAMEVIEWINTERNALFUNCTIONS_H

/**
 * Writes the column headers for a specified number of
 * columns to the specified string
 * @param numColumns the number of columns
 * @param str 	the string to which the column headers should
 * 				be written
 * @return 		an unsigned long long containing the number of
 * 				characters written to the string excluding the
 * 				terminating null character
 * @author Rasmus Nylander, s205418
 */
unsigned long long writeColumnHeaders(int numColumns, char *str);
/**
 * Creates a string containing column headers for the
 * specified number of columns
 * @param numColumns 	the number of columns to create
 * 						headers for
 * @return 	a string containing the column headers for the
 * 			specified number of columns
 * @author Rasmus Nylander, s205418
 */
char* getHeaderText(int numColumns);
/**
 * Writes the specified Deck array as columns to the specified string
 * @param columns the columns of a game to be written to the string
 * @param numColumns the number of elements in the array
 * @param str the string to write the columns to
 * @return 	an unsigned long long representing the number of characters
 * 			written to the string, excluding the ending null character
 * @author Rasmus Nylander, s205418
 */
unsigned long long writeColumns(Deck *columns, int numColumns, char* str);
/**
 * Returns the size of the biggest deck in the specified
 * array of decks
 * @param columns 	the array in which the size the size
 * 					of the biggest deck should be determined
 * @param numColumns the number of elements in the array
 * @return 	the size of the biggest Deck in the specified
 * 			array
 * @author Rasmus Nylander, s205418
 */
int getTallestColumnHeight(Deck *columns, int numColumns);
/**
 * Writes the specified row of the specified columns to the specified
 * string
 * @param row the number of the row to write where 0 is the first row
 * @param columns a Deck array containing the columns to write
 * @param numColumns the number of elements in the array
 * @param str the string to write the row to
 * @return 	an unsigned long long representing the number of characters
 * 			written to the string, excluding the ending null character
 * @author Rasmus Nylander, s205418
 */
unsigned long long writeRow(int row, Deck *columns, int numColumns, char *str);

char* getRowText(int row, Deck *columns, int numColumns);
char *getCardText(PlayingCard card, int row);
unsigned long long writeFinishedDecks(Deck *finished, int numFinishedDecks, char *str);

#endif //YUKON_GAMEVIEWINTERNALFUNCTIONS_H
