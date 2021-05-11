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
 * Writes the specified Deck arrays as columns to the specified string
 * @param columns the columns of a game to be written to the string
 * @param numColumns the number of elements in the columns array
 * @param finishedDecks the finished decks of the game
 * @param numFinishedDecks the number of elements in the finished decks array
 * @param str the string to write the columns to
 * @return 	an unsigned long long representing the number of characters
 * 			written to the string, excluding the ending null character
 * @author Rasmus Nylander, s205418
 */
unsigned long long writeColumns(Deck *columns, int numColumns, Deck *finishedDecks, int numFinishedDecks, char* str);
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
/**
 * Returns a new string containing the row text for the specified
 * row of the specified columns
 * @param row the row which to create the text for
 * @param columns 	the columns which of the table which the row
 * 					text is desired
 * @param numColumns the number of elements in the column array
 * @return 	a new string containing the row text for the specified
 * 			row of the specified columns
 */
char* getRowText(int row, Deck *columns, int numColumns);
/**
 * Returns the display text for the specified card
 * @param card the card to generate the display text for
 * @return 	a new string containing the display text for
 * 			the specified card
 * @author Rasmus Nylander, s205418
 */
char *getCardText(PlayingCard card);
/**
 * Writes the specified finished deck to the specified string
 * @param finished the deck to write to the string
 * @param str the string to write the deck to
 * @param number the number to write next to the deck
 * @return 	the number of characters written, excluding the terminating
 * 			null character
 */
unsigned long long writeFinishedDeck(Deck finished, char *str, int number);
/**
 * Returns a string representation of the top card in the specified deck
 * if it is not empty, otherwise returns a string containing the hiddenCardText
 * @param deck the deck to return the top card if
 * @return 	a string representation of the top card in the specified deck
 * 			if it is not empty, otherwise returns a string containing the
 * 			hiddenCardText
 */
char* getFinishedDeckText(Deck deck);

#endif //YUKON_GAMEVIEWINTERNALFUNCTIONS_H
