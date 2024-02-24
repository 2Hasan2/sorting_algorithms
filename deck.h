#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * enum kind_e - Typedef for enum kind_e
 * @SPADE: Spade kind
 * @HEART: Heart kind
 * @CLUB: Club kind
 * @DIAMOND: Diamond kind
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Typedef for struct card_s
 * @value: Value of the card
 * @kind: Kind of the card
 * Description: Define a new type struct card_s
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Doubly-linked list node
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void print_deck(const deck_node_t *deck);
void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
