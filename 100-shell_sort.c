#include "sort.h"

/**
 * swap_ints - this is the Swap between two int in an array.
 * @current: The first int to be swap.
 * @previous: The second int to be swap.
 */
void integerswapping(int *previous, int *current)
{
	int tmp;

	tmp = *previous;
	*previous = *current;
	*current = tmp;
}

/**
 * shell_sort - this will sort arrays of int type
 * in an ascending order using a shell sort algorithm methode ,
 * with space sizes determined by a decreasing of Knuth seqeuence
 * @array: this is the array of integers to be sorted
 * @size: the amount of elements in  an array
 * Description: while i am  the Knuth interval sequence.
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
while (j_index >= space && array[j_index - space] > array[j_index])
{
integerswapping(array + j_index, array + (j_index - space));
j_index -= space;
}
}
print_array(array, size);
}
}
