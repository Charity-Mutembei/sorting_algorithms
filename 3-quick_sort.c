#include "sort.h"

/**
 * swap - Swaps the positions of two elements in an array
 * @arr: The array
 * @idx1: Index of the first element
 * @idx2: Index of the second element
 */
void swap(int *arr, int idx1, int idx2)
{
int temp = arr[idx1];
arr[idx1] = arr[idx2];
arr[idx2] = temp;
}

/**
 * lomuto_partition - Lomuto partition sorting scheme implementation
 * @arr: The array
 * @start: Index of the first element
 * @end: Index of the last element
 * @size: Size of the array
 *
 * Return: The position of the last element sorted
 */
int lomuto_partition(int *arr, int start, int end, size_t size)
{
int pivot = arr[end];
int i = start - 1;
int j;

for (j = start; j <= end - 1; j++)
{
if (arr[j] < pivot)
{
i++;
if (arr[i] != arr[j])
{
swap(arr, i, j);
print_array(arr, size);
}
}
}
if (arr[i + 1] != arr[end])
{
swap(arr, i + 1, end);
print_array(arr, size);
}
return (i + 1);
}

/**
 * quicksort_recursive - Recursive implementation of the quicksort algorithm
 * @arr: The array
 * @start: Index of the first element
 * @end: Index of the last element
 * @size: Size of the array
 */
void quicksort_recursive(int *arr, int start, int end, int size)
{
int pivot_pos = 0;

if (start < end)
{
pivot_pos = lomuto_partition(arr, start, end, size);

quicksort_recursive(arr, start, pivot_pos - 1, size);
quicksort_recursive(arr, pivot_pos + 1, end, size);
}
}

/**
 * quick_sort - Sorts an array of integers in ascending
 * order using Quick sort algorithm
 * @array: The array
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
if (!array || size < 2)
return;
quicksort_recursive(array, 0, size - 1, size);
}
