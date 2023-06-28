#include <stdio.h>
#include "sort.h"

/**
 * print_array_s - Prints an array of integers
 * @array: Pointer to the array
 * @size: Size of the array
 */
void print_array_s(const int *array, size_t size)
{
size_t i;

for (i = 0; i < size; ++i)
{
printf("%d", array[i]);
if (i != size - 1)
printf(", ");
}
printf("\n");
}

/**
 * bitonic_compare - Merges two subarrays in ascending or descending order
 * @array: Pointer to the array
 * @low: Starting index of the first subarray
 * @count: Number of elements to merge
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_compare(int *array, size_t low, size_t count, int dir)
{
if (count > 1)
{
size_t k = count / 2;
size_t i;

for (i = low; i < low + k; ++i)
{
if ((array[i] > array[i + k]) == dir)
{
int temp = array[i];
array[i] = array[i + k];
array[i + k] = temp;
}
}
}
}

/**
 * bitonic_merge_recursive - Recursively merges two subarrays
 * @array: Pointer to the array
 * @low: Starting index of the sequence
 * @count: Number of elements in the sequence
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_merge_recursive(int *array, size_t low, size_t count, int dir)
{
if (count > 1)
{
size_t k = count / 2;

bitonic_compare(array, low, count, dir);

bitonic_merge_recursive(array, low, k, dir);
bitonic_merge_recursive(array, low + k, k, dir);
}
}

/**
 * bitonic_sort_recursive - Recursively sorts a bitonic sequence
 * @array: Pointer to the array
 * @low: Starting index of the sequence
 * @count: Number of elements in the sequence
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir)
{
if (count > 1)
{
size_t k = count / 2;

bitonic_sort_recursive(array, low, k, 1);
bitonic_sort_recursive(array, low + k, k, 0);

bitonic_merge_recursive(array, low, count, dir);
}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using Bitonic sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

printf("Merging [%lu/%lu] (UP):\n", size, size);
print_array_s(array, size);

bitonic_sort_recursive(array, 0, size, 1);

printf("Result [%lu/%lu] (UP):\n", size, size);
print_array_s(array, size);
}
