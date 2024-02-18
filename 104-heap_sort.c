#include "sort.h"


/**
 * ConvertToHeap - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @start: The index of the base row of the tree.
 * @end: The root node of the binary tree.
 */
void ConvertToHeap(int *array, size_t size, size_t start, size_t end)
{
	size_t left, right, large;

	left = 2 * end + 1;
	right = 2 * end + 2;
	large = end;

	if (left < start && array[left] > array[large])
		large = left;
	if (right < start && array[right] > array[large])
		large = right;

	if (large != end)
	{
		integerswapping(array + end, array + large);
		print_array(array, size);
		ConvertToHeap(array, size, start, large);
	}
}

/**
 * heapsorter - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heapsorter(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		ConvertToHeap(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		integerswapping(array, array + i);
		print_array(array, size);
		ConvertToHeap(array, size, i, 0);
	}
}
