#include <stdio.h>
#include "sort.h"

/**
 * swap - Swaps two integer values
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme to determine the position of the pivot
 * @array: Array of integers
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 *
 * Return: Position of the pivot element after partitioning
 */
int lomuto_partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    int j;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
            print_array(array, high + 1);
        }
    }

    swap(&array[i + 1], &array[high]);
    print_array(array, high + 1);

    return (i + 1);
}

/**
 * quick_sort_recursive - Recursively performs quick sort on the array
 * @array: Array of integers
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 */
void quick_sort_recursive(int *array, int low, int high)
{
    if (low < high)
    {
        int pivot = lomuto_partition(array, low, high);

        quick_sort_recursive(array, low, pivot - 1);
        quick_sort_recursive(array, pivot + 1, high);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort algorithm
 * @array: Array of integers
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1);
}
