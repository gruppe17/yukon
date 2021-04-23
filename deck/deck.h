//
// Created by Nylander on 09-04-2021.
//

/**
 * This functions as an extension of LinkedList
 */
#ifndef YUKON_DECK_H
#define YUKON_DECK_H

#include "playingCard.h"
#include "../LinkedList/LinkedList.h"

/**
 * Represents a deck of cards
 * @author Rasmus Nylander, s205418
 */
typedef LinkedList Deck;

/**
 * Creates a new, empty deck and returns a pointer to it
 * or NULL if memory allocation fails
 * @return 	a pointer to a new, empty deck or NULL if
 * 			memory allocation fails.
 * @author Rasmus Nylander, s205418
 */
Deck *newDeck();
/**
 * Creates a new standard deck of 52 playing card and
 * returns a pointer to it or NULL if memory allocation
 * fails
 * @return	a pointer too a new standard deck of playing
 * 			card or NULL if memory allocation fails.
 * @author Rasmus Nylander, s205418
 */
Deck *newStandardDeck();
/**
 * Adds one copy of every card to the specified Deck
 * @param deck the Deck to add cards to
 * @return TRUE if the Deck was changed
 * @author Rasmus Nylander, s205418
 */
BOOL fillDeck(Deck* deck);

Deck *loadDeckFromFile(char* fileName);
BOOL saveDeckToFile(char* fileName);

#endif //YUKON_DECK_H
