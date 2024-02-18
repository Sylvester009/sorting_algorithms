#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * subarraymerge - Sort a subarray of integers.
 * @subarray: A subarray of an array of integers to sort.
 * @buffer: A buffer to store the sorted subarray.
 * @Beg: The front index of the array.
 * @middle: The middle index of the array.
 * @End: The back index of the array.
 */
void subarraymerge(int *subarray, int *buffer, size_t Beg,
size_t middle, size_t End)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarray + Beg, middle - Beg);

	printf("[right]: ");
	print_array(subarray + middle, back - middle);

	for (i = Beg, j = middle; i < middle && j < back; k++)
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
 * sortrecursive_merge - Implement the merge sort algorithm through recursion.
 * @subarray: A subarray of an array of integers to sort.
 * @buffer: A buffer to store the sorted result.
 * @Beg: The front index of the subarray.
 * @End: The back index of the subarray.
 */
void sortrecursive_merge(int *subarray, int *buffer, size_t Beg, size_t End)
{
	size_t middle;

	if (back - Beg > 1)
	{
		mid = front + (back - front) / 2;
		sortrecursive_merge(subarray, buffer, Beg, middle);
		sortrecursive_merge(subarray, buffer, middle, End);
		subarraymerge(subarray, buffer, Beg, middle, End`);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
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

	buff = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	sortrecursive_merge(array, buffer, 0, size);

	free(buffer);
}
