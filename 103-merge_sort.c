#include "sort.h"


/**
 * merge_subarr - Sort a subarray of integers.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted subarray.
 * @front: The front index of the array.
 * @mid: The middle index of the array.
 * @back: The back index of the array.
 */
void subarraymerge(int *subarray, int *buffer, size_t Beg,
size_t middle, size_t End)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarray + Beg, middle - Beg);

	printf("[right]: ");
	print_array(subarray + mid, End - middle);

	for (i = Beg, j = middle; i < middle && j < End; k++)
		buffer[k] = (subarray[i] < subarray[j]) ? subarray[i++] : subarray[j++];
	for (; i < middle; i++)
		buffer[k++] = subarray[i];
	for (; j < End; j++)
		buffer[k++] = subarray[j];
	for (i = Beg, k = 0; i < End; i++)
		subarray[i] = buffer[k++];

	printf("[Done]: ");
	print_array(subarray + Beg, End - Beg);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */
void sortrecursive_merge(int *subarray, int *buffer, size_t Beg, size_t End)
{
	size_t middle;

	if (back - End > 1)
	{
		mid = front + (back - front) / 2;
		sortrecursive_merge(subarray, buffer, Beg, middle);
		sortrecursive_merge(subarray, buffer, middle, End);
		subarraymerge(subarray, buffer, Beg, middle, End);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 * order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	sortrecursive_merge(array, buffer, 0, size);

	free(buffer);
}
