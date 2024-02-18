#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using a shell
 * sort algorithm, with gap sizes determined by a decreasing Knuth seqeuence
 * @array: array of integers to be sorted
 * @size: amount of elements in array
 */
void shell_sort(int *array, size_t size)
{
if (!array || size < 2)
return;

int num = (int)size;
int space, index, j_index, temp;
int K_max = 1;

/* Calculate the largest Knuth sequence value less than num as space *?
while (K_max < num / 3)
{
K_max = K_max * 3 + 1;
}

/* Start with the largest space and work down to space 1 */
for (space = K_max; space > 0; space = (space - 1) / 3)
{
/* Perform insertion sort for the current space size */
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

/* Print the array after each pass (optional) */
print_array(array, size);
}
}
