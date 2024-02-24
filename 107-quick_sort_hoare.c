#include "sort.h"

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using the
 * quick sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 * Return: void
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_hoare_recursive(array, size, 0, size - 1);
}

/**
 * quick_sort_hoare_recursive - Sorts an array of integers in ascending order
 * using the quick sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 * @low: The lowest index of the partition to be sorted
 * @high: The highest index of the partition to be sorted
 * Return: void
 */

void quick_sort_hoare_recursive(int *array, size_t size, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, size, low, high);
		quick_sort_hoare_recursive(array, size, low, pivot);
		quick_sort_hoare_recursive(array, size, pivot + 1, high);
	}
}

/**
 * partition - Partitions an array of integers using the quick sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 * @low: The lowest index of the partition to be sorted
 * @high: The highest index of the partition to be sorted
 * Return: The index of the pivot
 */

int partition(int *array, size_t size, int low, int high)
{
	int pivot = array[low], temp;
	int i = low - 1, j = high + 1;

	while (1)
	{
		do
			i++;
		while (array[i] < pivot);
		do
			j--;
		while (array[j] > pivot);
		if (i >= j)
			return (j);
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
}
