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
}

/**
 * merge_sort_recursive - Recursive function for Merge sort
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 **/
void merge_sort_recursive(int *array, size_t size)
{
size_t mid;
int *left, *right;

if (size < 2)
return;

mid = size / 2;

left = array;
right = array + mid;

merge_sort_recursive(left, mid);
merge_sort_recursive(right, size - mid);

printf("Left array: ");
print_array(left, mid);
printf("Right array: ");
print_array(right, size - mid);

merge(array, left, mid, right, size - mid);

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
if (!array || size < 2)
return;

merge_sort_recursive(array, size);
}
