#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * enum kind_e - Card suit enumeration.
 * @SPADE: Spades suit.
 * @HEART: Hearts suit.
 * @CLUB: Clubs suit.
 * @DIAMOND: Diamonds suit.
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Play card
 * @value: the card's value
 * From "Ace" to "King"
 * @kind: type of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - The Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the list's previous node
 * @next: Pointer to the list's next node
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* DECK_H */

