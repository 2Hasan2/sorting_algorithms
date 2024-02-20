#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * @array: The array to be printed
 * @size: Number of elements in @array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
    int minIdx;
    size_t i, j;
    int n;

    for (i = 0; i < n-1; i++)
    {
        minIdx = i;

        for(j = i+1; j < n; j++){
            if (array[j] < array[minIdx])
            minIdx = j;
            swap(array[minIdx], array[i]);
        }
    }

}
