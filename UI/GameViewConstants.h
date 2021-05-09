//
// Created by Nylan on 08-05-2021.
//

#ifndef YUKON_GAMEVIEWCONSTANTS_H
#define YUKON_GAMEVIEWCONSTANTS_H

/**
 * The prefix of the header for every column
 * @author Rasmus Nylander, s205418
 */
const char columnPrefix[] = "C";
/**
 * Spacer used to separate different columns
 * @author Rasmus Nylander, s205418
 */
const char columnSpacer[] = "\t";
/**
 * Spacer between the column headers and the rest of the view.
 * Written at the end of the column headers
 * @author Rasmus Nylander, s205418
 */
const char headerSuffix[] = "\n\n";
/**
 * String used instead of card when the card should be
 * hidden/face down.
 * @author Rasmus Nylander, s205418
 */
const char hiddenCardText[] = "[]";
/**
 * Spacer used to separate different columns
 * @author Rasmus Nylander, s205418
 */
const char rowSuffix[] = "\n";
/**
 * Spacer used to separate the columns and the finished decks.
 * @author Rasmus Nylander, s205418
 */
const char finishedColumnSpacer[] = "\t\t";
/**
 * The minimum number of columns to draw. This is required
 * to correctly draw the finished decks.
 * @author Rasmus Nylander, s205418
 */
const int gameViewMinNumColumns = PLAYING_CARD_NUM_SUITS * 2 - 1;

#endif //YUKON_GAMEVIEWCONSTANTS_H