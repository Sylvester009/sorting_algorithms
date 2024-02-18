#include "sort.h"

/**
 * shell_sort - this will sort arrays of int type
 * in an ascending order using a shell sort algorithm methode ,
 * with space sizes determined by a decreasing of Knuth seqeuence
 * @array: this is the array of integers to be sorted
 * @size: the amount of elements in  an array
 */

void shell_sort(int *array, size_t size)
{
int index, j_index, space, num, K_max, temp;

while (!array || size < 2)
return;

num = (int)size;
for (space = 1; space < num; space = (space * 3) + 1)
{
K_max = space;
}
for (space = K_max; space > 0; space = (space - 1) / 3)
{
for (index = space; index < num; index++)
{
temp = array[index];
for (j_index = index; j_index >= space && array[j_index - space] >
temp; j_index -= space)
{
array[j_index] = array[j_index - space];
}
array[j_index] = temp;
}
print_array(array, size);
}
}
