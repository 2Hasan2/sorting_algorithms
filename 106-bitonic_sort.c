#include "sort.h"
/**
 * swap_ints - Swap two integers.
 * @a: The first integer.
 * @b: The second integer.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bitonic_merge - Merge two subarrays of integers in a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the subarrays to merge.
 * @seq: The size of the subarrays to merge.
 * @flow: The direction to sort the subarrays in.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
				   char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == 0 && array[i] > array[i + jump]) ||
				(flow == 1 && array[i] < array[i + jump]))
				swap_ints(array + i, array + i + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - Recursively sorts an array of integers in a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the subarray to sort.
 * @seq: The size of the subarray to sort.
 * @flow: The direction to sort the subarray in.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == 0) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, 0);
		bitonic_seq(array, size, start + cut, cut, 1);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using the
 * bitonic sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, 0);
}