#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - it sorts arrays of int type in an ascending
 * order using a  sort algorithm method
 * @array: it is the array of int type to be sorted
 * @size: the amount of elements in an array
 */
void counting_sort(int *array, size_t size)
{
int index, sum, max, *arg_c, *output;
if (!array || size < 2)
return;
max = array[0];
for (index = 0; index < (int)size; index++)
{
if (array[index] > max)
max = array[index];
}
arg_c = calloc((max + 1), sizeof(int));
if (!arg_c)
return;
for (index = 0; index < (int)size; index++)
arg_c[array[index]]++;
index = 0;
sum = 0;
while (index < max + 1)
{
sum = arg_c[index] + sum;
arg_c[index] = sum;
index++;
}
print_array(arg_c, max + 1);
output = malloc(sizeof(int) * size);
if (!output)
return;
index = 0;
while (index < (int)size)
{
output[arg_c[array[index]] - 1] = array[index];
arg_c[array[index]]--;
index++;
}
index = 0;
while (index < (int)size)
{
array[index] = output[index];
index++;
}
free(arg_c);
free(output);
}
