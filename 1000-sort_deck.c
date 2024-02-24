#include "deck.h"

/**
 * sort_deck - Sorts a deck of cards
 * @deck: The deck to be sorted
 * Return: void
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *current, *temp;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	current = (*deck)->next;
	while (current)
	{
		temp = current;
		current = current->next;
		while (temp->prev && temp->card->kind < temp->prev->card->kind)
		{
			temp->prev->next = temp->next;
			if (temp->next)
				temp->next->prev = temp->prev;
			temp->next = temp->prev;
			temp->prev = temp->next->prev;
			temp->next->prev = temp;
			if (temp->prev)
				temp->prev->next = temp;
			else
				*deck = temp;
			print_deck(*deck);
		}
	}
}

/**
 * print_deck - Prints a deck of cards
 * @deck: The deck to be printed
 * Return: void
 */
void print_deck(const deck_node_t *deck)
{
	const deck_node_t *current = deck;

	while (current)
	{
		printf("%d of %s", current->card->value, current->card->kind);
		if (current->next)
			printf(", ");
		else
			printf("\n");
		current = current->next;
	}
}
