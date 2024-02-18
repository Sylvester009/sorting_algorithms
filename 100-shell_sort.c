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

	// Generate the sequence of Knuth gaps
	for (space = 1; space < num / 3; space = space * 3 + 1);

	// Start with the largest gap and reduce it until space = 1
	for (; space > 0; space /= 3)
	{
		// Perform insertion sort with the current gap
		for (index = space; index < num; index++)
		{
			temp = array[index];
			for (j_index = index; j_index >= space && array[j_index - space] > temp; j_index -= space)
			{
				array[j_index] = array[j_index - space];
			}
			array[j_index] = temp;
		}

		// Optional: Print the array after each pass
		print_array(array, size);
	}
}
