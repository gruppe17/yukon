//
// Created by Nylan on 09-04-2021.
//

#ifndef YUKON_PLAYINGCARD_H
#define YUKON_PLAYINGCARD_H

#define NUM_SUITS 4
#define BITS_FOR_SUITS 2
#define NUM_CARDS_IN_SUIT 13
#define BITS_FOR_CARDS_IN_SUIT 4

typedef struct playingCard PlayingCard;

PlayingCard* newCard(unsigned char suit, unsigned char number);



#endif //YUKON_PLAYINGCARD_H
