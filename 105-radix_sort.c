#include <stdio.h>
#include <stdlib.h>

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
 * get_max - Returns the maximum element in an array
 * @array: Pointer to the array
 * @size: Size of the array
 * Return: The maximum element
 */
int get_max(const int *array, size_t size)
{
int max = array[0];
size_t i;

for (i = 1; i < size; ++i)
{
if (array[i] > max)
max = array[i];
}

return (max);
}

/**
 * counting_sort - Performs the counting
 * sort on the specified digit
 * @array: Pointer to the array
 * @size: Size of the array
 * @exp: The current exponent (significant digit)
 */
void counting_sort(int *array, size_t size, int exp)
{
int *output = malloc(sizeof(int) * size);
int count[10] = {0};
size_t i;

if (output == NULL)
return;

for (i = 0; i < size; ++i)
count[(array[i] / exp) % 10]++;

for (i = 1; i < 10; ++i)
count[i] += count[i - 1];

for (i = size - 1; i > 0; --i)
{
output[count[(array[i] / exp) % 10] - 1] = array[i];
count[(array[i] / exp) % 10]--;
}

output[count[(array[0] / exp) % 10] - 1] = array[0];

for (i = 0; i < size; ++i)
array[i] = output[i];

free(output);
}

/**
 * radix_sort - Sorts an array of integers in
 * ascending order using Radix sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{

int max;
size_t exp;

max = get_max(array, size);

if (array == NULL || size < 2)
return;
for (exp = 1; max / exp > 0; exp *= 10)
{
counting_sort(array, size, exp);
print_array_s(array, size);
}
}
