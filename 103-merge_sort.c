#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void merge(int *array, int *left, size_t left_s, int *right, size_t right_s);
void merge_sort_recursive(int *array, size_t size);
void merge_sort(int *array, size_t size);

/**
 * merge - Merges two subarrays into a sorted array
 * @array: Pointer to the original array
 * @left: Pointer to the left subarray
 * @left_s: Size of the left subarray
 * @right: Pointer to the right subarray
 * @right_s: Size of the right subarray
 **/
void merge(int *array, int *left, size_t left_s, int *right, size_t right_s)
{
size_t i = 0, j = 0, k = 0;
size_t m;
int *merged = malloc((left_s + right_s) * sizeof(int));

if (merged == NULL)
{
printf("Failed to allocate memory for merging.\n");
return;
}

printf("Merging...\n[left]: ");
print_array(left, left_s);
printf("[right]: ");
print_array(right, right_s);

while (i < left_s && j < right_s)
{
if (left[i] <= right[j])
{
merged[k] = left[i];
i++;
}
else
{
merged[k] = right[j];
j++;
}
k++;
}

while (i < left_s)
{
merged[k] = left[i];
i++;
k++;
}

while (j < right_s)
{
merged[k] = right[j];
j++;
k++;
}

for (m = 0; m < left_s + right_s; m++)
{
array[m] = merged[m];
}

printf("[Done]: ");
print_array(array, left_s + right_s);

free(merged);
}

/**
 * _merge_sort - Recursive function for Merge sort
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 * @temp: ****
 **/
void _merge_sort(int *array, int *temp, size_t size)
{
size_t half = size / 2, i = 0, j = 0, k;

if (size < 2)
return;

_merge_sort(array, temp, half);
_merge_sort(array + half, temp + half, size - half);

printf("Merging...\n");
printf("[left]: ");
print_array(array, half);
printf("[right]: ");
print_array(array + half, size - half);

for (k = 0; k < size; k++)
{
if (j >= size - half || (i < half && array[i] < (array + half)[j]))
{
temp[k] = array[i];
i++;
}
else
{
temp[k] = (array + half)[j];
j++;
}
}

for (k = 0; k < size; k++)
array[k] = temp[k];

printf("[Done]: ");
print_array(array, size);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge sort
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 **/
void merge_sort(int *array, size_t size)
{
int *temp;

if (!array || size < 2)
return;

temp = malloc(sizeof(*temp) * size);
if (!temp)
return;

_merge_sort(array, temp, size);
free(temp);
}

