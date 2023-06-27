#include <stdio.h>
#include "sort.h"

/**
 * swap - Swaps two integers
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
 * partition - Partitions the array and returns the pivot index
 * @array: The array to be partitioned
 * @low: The low index of the partition
 * @high: The high index of the partition
 *
 * Return: The pivot index
 */
int partition(int *array, int low, int high)
{
int pivot = array[high];
int i = low - 1;
int j;

for (j = low; j < high; j++)
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
 * quicksort - Sorts the array using the Quick sort algorithm
 * @array: The array to be sorted
 * @low: The low index of the partition
 * @high: The high index of the partition
 */
void quicksort(int *array, int low, int high)
{
if (low < high)
{
int pi = partition(array, low, high);
quicksort(array, low, pi - 1);
quicksort(array, pi + 1, high);
}
}

/**
 * quick_sort - Sorts an array of integers
 * in ascending order using Quick sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size <= 1)
return;

quicksort(array, 0, size - 1);
}
