#include "sort.h"

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list
 * @list: The list containing the nodes
 * @node1: The first node to be swapped
 * @node2: The second node to be swapped
 * Return: void
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;
	if (node2->next != NULL)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node2->next = node1;
	node1->prev = node2;
}

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
				swap_nodes(list, current, current->next);
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
				swap_nodes(list, current->prev, current);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->prev;
		}
	}
}
