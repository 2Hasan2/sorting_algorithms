#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the cocktail shaker sort algorithm
 * @list: The list to be sorted
 * Return: void
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = *list;
	while (swapped)
	{
		swapped = 0;
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				if (current->prev != NULL)
					current->prev->next = current->next;
				else
					*list = current->next;
				current->next->prev = current->prev;
				current->prev = current->next;
				current->next = current->next->next;
				current->prev->next = current;
				if (current->next != NULL)
					current->next->prev = current;
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				if (current->prev->prev != NULL)
					current->prev->prev->next = current;
				else
					*list = current;
				current->prev->next = current->next;
				current->next = current->prev;
				current->prev = current->next->prev;
				current->next->prev = current;
				if (current->prev != NULL)
					current->prev->next = current;
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->prev;
		}
	}
}
