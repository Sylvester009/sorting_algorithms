#include "sort.h"

/**
 * selection_sort - sorts an array of integers using a selction sort
 * algorithm
 * @array: array of integers to be sorted
 * @size: amount of elements in array
 */
void selection_sort(int *array, size_t size)
{
	int index, j_index, min_j_dex, temp, num = (int)size;

	if (!array || size < 2)
		return;

	/* at every position in the n-member array */
	for (index = 0; index < num - 1; index++)
	{
		/* scan from that position to the end */
		min_j_dex = index;
		for (j_index = index + 1; j_index < num; j_index++)
		{
			/* determine the minimum value in that range */
			if (array[j_index] < array[min_j_dex])
			{
				min_j_dex = j_index;
			}
		}
		/* and if it is lower than the value at start of range, */
		/* swap them */
		if (min_j_dex != index)
		{
			temp = array[index];
			array[index] = array[min_j_dex];
			array[min_j_dex] = temp;
			print_array(array, size);
		}
	}
}
