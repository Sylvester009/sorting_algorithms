#include "sort.h"

/**
 * swap_ints - this is the Swap between two int in an array.
 * @current: The first int to be swap.
 * @previous: The second int to be swap.
 */
void swap_ints(int *previous, int *current)
{
	int tmp;

	tmp = *previous;
	*previous = *current;
	*current = tmp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
size_t space, index, j_index;

while (array == NULL || size < 2)
return;

for (space = 1; space < (size / 3);)
space = space * 3 + 1;

for (; space >= 1; space /= 3)
{
for (index = space; index < size; index++)
{
j_index = index;
if (j_index >= space && array[j_index - space] > array[j_index])
{
swap_ints(array + j_index, array + (j_index - space));
j_index -= space;
}
}
print_array(array, size);
}
}
