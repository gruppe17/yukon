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


typedef LinkedList Deck;

Deck *newDeck();
Deck *newStandardDeck();
/**
 * Adds one copy of every card to the specified Deck
 * @param deck the Deck to add cards to
 * @return TRUE if the Deck was changed
 */
BOOL fillDeck(Deck* deck);

Deck *loadDeckFromFile(char* fileName);
BOOL SaveDeckToFile(char* fileName);

#endif //YUKON_DECK_H
