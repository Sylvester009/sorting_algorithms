#include "sort.h"
#include <stack>

/**
 * ConvertToHeap - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @end: The index of the base row of the tree.
 * @start: The root node of the binary tree.
 */

void ConvertToHeap(int *array, size_t size, size_t end, size_t start)
{
    std::stack<size_t> stack;
    stack.push(start);

    while (!stack.empty())
    {
        size_t current = stack.top();
        stack.pop();

        size_t left = 2 * current + 1;
        size_t right = 2 * current + 2;
        size_t largest = current;

        if (left < end && array[left] > array[largest])
            largest = left;
        if (right < end && array[right] > array[largest])
            largest = right;

        if (largest != current)
        {
            std::swap(array[current], array[largest]);
            print_array(array, size);
            stack.push(largest);
        }
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
