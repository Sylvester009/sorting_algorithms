#include "sort.h"
/**
 * ConvertToHeap - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @end: The index of the base row of the tree.
 * @start: The root node of the binary tree.
 */
void ConvertToHeap(int *array, size_t size, size_t end, size_t start)
{
	size_t left, right, large;

	left = 2 * start + 1;
	right = 2 * start + 2;
	large = start;

	while (left < end && array[left] > array[large])
		large = left;
	if (right < end && array[right] > array[large])
		large = right;

	while (large != start)
	{
		ints_swapping(array + start, array + large);
		print_array(array, size);
		ConvertToHeap(array, size, end, large);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		ConvertToHeap(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		ints_swapping(array, array + i);
		print_array(array, size);
		ConvertToHeap(array, size, i, 0);
	}
}
/**
 * ints_swapping - this is the Swap between two int in an array.
 * @current: The first int to be swap.
 * @previous: The second int to be swap.
 */
void ints_swapping(int *previous, int *current)
{
	int tmp;
	tmp = *previous;
	*previous = *current;
	*current = tmp;
}
