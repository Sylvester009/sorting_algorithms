#include "sort.h"

/**
 * partitionArray - scans a partition of an array of integers for values less than
 * pivot value, and swaps them with first value in partition, then swaps pivot
 * value with first value in partition
 * @array: array of integers to be sorted
 * @left: index in array that begins partition
 * @right: index in array that ends partition
 * @size: amount of elements in array
 * Return: new index at which to start new recursive partition
 */
int partitionArray(int *array, int left, int right, size_t size)
{
int index, j_index, piv, temp;
piv = array[right];
index = left;
j_index = left;
while (j_index < right)
{
if (array[j_index] < piv)
{
temp = array[index];
array[index] = array[j_index];
array[j_index] = temp;
if (array[index] != array[j_index])
print_array(array, size);
index++;
}
j_index++;
}

temp = array[index];
array[index] = array[right];
array[right] = temp;
if (array[index] != array[right])
print_array(array, size);
return (index);
}

/**
 * quicksort - recursively sorts array of integers by separating into two
 * partitions, using Lomuto quick sort
 * @array: array of integers to be sorted
 * @left: index in array that begins partition
 * @right: index in array that ends partition
 * @size: amount of elements in array
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = partition(array, low, high, size);
		quicksort(array, low, p - 1, size);
		quicksort(array, p + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using a quick
 * sort algorithm, with Lomuto partition scheme
 * @array: array of integers to be sorted
 * @size: amount of elements in array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, 0, (int)size - 1, size);
}
