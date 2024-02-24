#include "sort.h"

/**
 * heap_sort - Sorts an array of integers in ascending order using the
 * heap sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 * Return: void
 */

void heap_sort(int *array, size_t size)
{
	size_t i;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2; i > 0; i--)
		heapify(array, size, i - 1, size);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		heapify(array, i, 0, size);
	}
}
