#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers
 * in ascending order using Bubble sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bubble_sort(int *array, size_t size)
{
size_t a, b, c;
a = 0;

while (a < size)
{
for (b = 1; b < size - a; b++)
{
if (array[b - 1] > array[b])
{
c = array[b];
array[b] = array [b - 1];
array[b - 1] = c;
print_array(array, size);
}
}

a++;
}
}
