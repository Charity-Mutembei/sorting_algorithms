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
 * swap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/**
 * sift_down - Performs the sift-down operation on a binary heap
 * @array: Pointer to the array representing the binary heap
 * @start: Index of the root node of the subtree to sift down
 * @end: Index of the last node in the heap
 * @size: Size of the array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
size_t root = start;
size_t child, swap_index;

while (2 * root + 1 <= end)
{
child = 2 * root + 1;
swap_index = root;

if (array[swap_index] < array[child])
swap_index = child;
if (child + 1 <= end && array[swap_index] < array[child + 1])
swap_index = child + 1;

if (swap_index == root)
return;

swap(&array[root], &array[swap_index]);
print_array_s(array, size);

root = swap_index;
}
}

/**
 * heap_sort - Sorts an array of integers in
 * ascending order using Heap sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
int i;

if (array == NULL || size < 2)
return;

/* Build max heap */
for (i = size / 2 - 1; i >= 0; --i)
sift_down(array, i, size - 1, size);

/* Heap sort */
for (i = size - 1; i > 0; --i)
{
swap(&array[0], &array[i]);
print_array_s(array, size);
sift_down(array, 0, i - 1, size);
}
}

