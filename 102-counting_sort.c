#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

void count_array_helper(int *array, size_t size, int max_value);

/**
 * counting_sort - Sorts an array of integers in
 * ascending order using the Counting sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 **/
void counting_sort(int *array, size_t size)
{
int max_value;
size_t i;

if (!array || size < 2)
return;

max_value = array[0];
for (i = 0; i < size; i++)
{
if (array[i] > max_value)
max_value = array[i];
}

count_array_helper(array, size, max_value);
}
/**
 * count_array_helper - Helper function for counting sort
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 * @max_value: Maximum value in the array
 **/
void count_array_helper(int *array, size_t size, int max_value)
{
int *count_array, *sorted_array;
size_t i;

count_array = calloc((max_value + 1), sizeof(int));
if (!count_array)
return;

for (i = 0; i < size; i++)
{
count_array[array[i]]++;
}

for (i = 1; i <= (size_t)max_value; i++)
{
count_array[i] += count_array[i - 1];
}

print_array(count_array, max_value + 1);

sorted_array = malloc(size * sizeof(int));
if (!sorted_array)
{
free(count_array);
return;
}

for (i = 0; i < size; i++)
{
count_array[array[i]]--;
sorted_array[count_array[array[i]]] = array[i];
}

for (i = 0; i < size; i++)
{
array[i] = sorted_array[i];
}

free(sorted_array);
free(count_array);
}
