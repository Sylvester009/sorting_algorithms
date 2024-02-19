#include "sort.h"
/**
 * ConvertToHeap - this will Turn a binarytree into  binary heap.
 * @array: this is the  array of int type that represents a binary tree.
 * @size: This is the  size of the array.
 * @end: This is the index of the end of the tree.
 * @start: The start node of the binary tree.
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
if (large != start)
{
ints_swapping(array + start, array + large);
print_array(array, size);
ConvertToHeap(array, size, end, large);
}
}

/**
 * heap_sort - it will Sort out arrays of int type in an
 * ascending order using the heap sort algorithm method.
 * @array: this is an  array of int type.
 * @size: This is the size of the array.
 *
 * Description: it will Implements the sift-down heap sort
 * algorithm.
 */
void heap_sort(int *array, size_t size)
{
int i;
while (array == NULL || size < 2)
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
