#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using a shell
 * sort algorithm, with gap sizes determined by a decreasing Knuth seqeuence
 * @array: array of integers to be sorted
 * @size: amount of elements in array
 */
void shell_sort(int *array, size_t size)
{
	int index, j_index, space, num, K_max, temp;

	if (!array || size < 2)
		return;

	num = (int)size;
	for (space = 1; space < num; space = (space * 3) + 1)
	{
		K_max = space;
	}
	/* Start with the largest Knuth seq value less than num as space, */
	/* and work down sequence to a space of 1 */
	for (space = K_max; space > 0; space = (space - 1) / 3)
	{
		/* Do a gapped insertion sort for this space size. */
		for (index = space; index < num; index++)
		{
			/* add array[index] to space sorted elements; */
			/* save array[index] in temp in preparation to overwrite */
			temp = array[index];
			/* shift earlier space-sorted elements up until the */
			/* correct location for array[index] is found */
			for (j_index = index; j_index >= space && array[j_index - space] > temp; j_index -= space)
			{
				array[j_index] = array[j_index - space];
			}
			/* move temp (original array[index]) to its correct location */
			array[j_index] = temp;
		}
		print_array(array, size);
	}
}
