#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending order using the
 * merge sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	merge_sort_recursive(array, temp, 0, size - 1);
	free(temp);
}

/**
 * merge_sort_recursive - Recursively sorts an array of integers in ascending
 * order using the merge sort algorithm
 * @array: The array to be sorted
 * @temp: A temporary array to store the sorted elements
 * @start: The starting index of the array
 * @end: The ending index of the array
 * Return: void
 */
void merge_sort_recursive(int *array, int *temp, size_t start, size_t end)
{
	size_t middle;

	if (start < end)
	{
		middle = (start + end) / 2;
		merge_sort_recursive(array, temp, start, middle);
		merge_sort_recursive(array, temp, middle + 1, end);
		merge_arrays(array, temp, start, middle, end);
	}
}

/**
 * merge_arrays - Merges two arrays of integers into one sorted array
 * @array: The array to be sorted
 * @temp: A temporary array to store the sorted elements
 * @start: The starting index of the array
 * @middle: The middle index of the array
 * @end: The ending index of the array
 * Return: void
 */

void merge_arrays(int *arr, int *temp, size_t start, size_t middle, size_t end)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(arr + start, middle - start + 1);
	printf("[right]: ");
	print_array(arr + middle + 1, end - middle);

	for (i = start, j = middle + 1, k = start; i <= middle && j <= end; k++)
	{
		if (arr[i] <= arr[j])
		{
			temp[k] = arr[i];
			i++;
		}
		else
		{
			temp[k] = arr[j];
			j++;
		}
	}

	while (i <= middle)
	{
		temp[k] = arr[i];
		i++;
		k++;
	}

	while (j <= end)
	{
		temp[k] = arr[j];
		j++;
		k++;
	}

	for (i = start; i <= end; i++)
		arr[i] = temp[i];
	printf("[Done]: ");
	print_array(temp + start, end - start + 1);
}
