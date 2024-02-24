#include "sort.h"

/**
 * get_max - Finds the maximum element in an array
 * @array: The array
 * @size: The size of the array
 * Return: The maximum element
 */
int get_max(int *array, size_t size)
{
	int max = 0;
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return max;
}

/**
 * count_elements - Counts the occurrences of each element in an array
 * @array: The array
 * @size: The size of the array
 * @max: The maximum element in the array
 * Return: An array containing the counts of each element
 */
int *count_elements(int *array, size_t size, int max)
{
	int *count;
	size_t i;

	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return NULL;

	for (i = 0; i <= max; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[array[i]]++;

	return count;
}

/**
 * cumulative_sum - Computes the cumulative sum of an array
 * @count: The array
 * @max: The maximum element in the array
 * Return: void
 */
void cumulative_sum(int *count, int max)
{
	size_t i;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
}

/**
 * rearrange_elements - Rearranges the elements in the original array
 * @array: The array
 * @output: The output array
 * @count: The array containing the counts of each element
 * @size: The size of the array
 * Return: void
 */
void rearrange_elements(int *array, int *output, int *count, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];
}

/**
 * counting_sort - Sorts an array of integers in ascending order using the
 * counting sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output;
	int max;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);

	count = count_elements(array, size, max);
	if (count == NULL)
		return;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(count);
		return;
	}

	cumulative_sum(count, max);

	print_array(count, max + 1);

	rearrange_elements(array, output, count, size);

	free(count);
	free(output);
}
