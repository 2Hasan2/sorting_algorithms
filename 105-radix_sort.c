#include "sort.h"

/**
 * radix_sort - Sorts an array of integers in ascending order using the
 * radix sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 * Return: void
 */

void radix_sort(int *array, size_t size)
{
	int *count, *output;
	size_t i, max = 0, exp = 1;

	if (array == NULL || size < 2)
		return;
	count = malloc(sizeof(int) * 10);
	if (count == NULL)
		return;
	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(count);
		return;
	}
	for (i = 0; i < size; i++)
	{
		if (array[i] > (int)max)
			max = array[i];
	}
	while (max / exp > 0)
	{
		for (i = 0; i < 10; i++)
			count[i] = 0;
		for (i = 0; i < size; i++)
			count[(array[i] / exp) % 10]++;
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];
		for (i = size - 1; (int)i >= 0; i--)
		{
			output[count[(array[i] / exp) % 10] - 1] = array[i];
			count[(array[i] / exp) % 10]--;
		}
		for (i = 0; i < size; i++)
			array[i] = output[i];
		print_array(array, size);
		exp *= 10;
	}
	free(count);
	free(output);
}
