//
// Created by Nylan on 09-04-2021.
//

#ifndef YUKON_PLAYINGCARD_H
#define YUKON_PLAYINGCARD_H

#define PLAYING_CARD_NUM_SUITS 4
#define PLAYING_CARD_NUM_CARDS_IN_SUIT 13

/**
 * Represents a standard playing card
 * @author Rasmus Nylander, s205418
 */
typedef struct playingCard* PlayingCard;

/**
 * Creates a new PlayingCard with the specified suit and
 * number and returns a pointer to it or NULL if memory
 * allocation fails.
 * @param suit the suit of the playing card
 * @param number the number of the playing card
 * @return	A pointer to a new PlayingCard or NULL if
 * 			memory allocation fails
 * @author Rasmus Nylander, s205418
 */
PlayingCard newCard(unsigned char suit, unsigned char number);

/**
 * Returns a string representation of the specified PlayingCard.
 * @param card the PlayingCard to be represented as a string
 * @return A new string representing the card or null if memory can't be allocated
 * @author Rasmus Nylander, s205418
 */
char* playingCardToString(PlayingCard card);

/**
 * Returns a string representation of the specified PlayingCard's suit
 * @param card the PlayingCard whose suit it to be represented as a string
 * @return a char representing the card's suit or null if memory can't be allocated
 * @author Rasmus Nylander, s205418
 */
char* playingCardSuitToString(PlayingCard card);

/**
 * Returns a string representation of the specified PlayingCard's number
 * @param card the PlayingCard whose number it to be represented as a string
 * @return a new string representing the card's number or null if memory can't be allocated
 * @author Rasmus Nylander, s205418
 */
char* playingCardNumberToString(PlayingCard card);



#endif //YUKON_PLAYINGCARD_H
