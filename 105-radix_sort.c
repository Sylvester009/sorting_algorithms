#include "sort.h"
#include <stdlib.h>
/**
 * getmaximum_s - it definitely  Get the max value in an
 * array of int type.
 * @array: this is an array of int type.
 * @size: This the size of the array.
 *
 * Return: Returns the max int type in the array.
 */
int getmaximum_s(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_radix - it will Sort the significant digits of
 * arrays of integers using the counting sort algorithm method.
 * @array: this is an array of int type.
 * @size: This is the size of the array.
 * @digit: This is the significant digit to be sorted.
 * @buffer: this is a buffer that store the sorted array.
 */

void counting_radix(int *array, size_t size, int digit, int *buffer) {
int arg_c[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
size_t index = 0;

while (index < size)
{
arg_c[(array[index] / digit) % 10] += 1;
index++;
}

index = 0;
while (index < 10)
{
arg_c[index] += arg_c[index - 1];
index++;
}
index = size - 1;
while ((int)index >= 0)
{
buffer[arg_c[(array[index] / digit) % 10] - 1] = array[index];
arg_c[(array[index] / digit) % 10] -= 1;
index--;
}
index = 0;
while (index < size)
{
array[index] = buffer[index];
index++;
}
}

/**
 * radix_sort - it will Sort arrays of int type
 * using the radix sort algorithm methode.
 * @array: this is an array of int type.
 * @size: This is the size of the array.
 *
 * Description: it will definitely Implements the LSD
 * radix sort algorithm methode.
 */
void radix_sort(int *array, size_t size)
{
int maximum, digit, *buffer;
if (array == NULL || size < 2)
return;

buffer = malloc(sizeof(int) * size);
if (buffer == NULL)
return;

maximum = getmaximum_s(array, size);
digit = 1;
while (maximum / digit > 0)
{
counting_radix(array, size, digit, buffer);
print_array(array, size);
digit *= 10;
}

free(buffer);
}
