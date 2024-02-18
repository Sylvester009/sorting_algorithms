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
 * quicksortArray - recursively sorts array of integers by separating into two
 * partitions, using Lomuto quick sort
 * @array: array of integers to be sorted
 * @left: index in array that begins partition
 * @right: index in array that ends partition
 * @size: amount of elements in array
 */
void quicksortArray(int *array, int left, int right, size_t size)
{
	int point;
	while (left < right)
	{
		point = partitionArray(array, left, right, size);
		quicksortArray(array, left, point - 1, size);
		quicksortArray(array, point + 1, right, size);
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
	while (!array || size < 2)
		return;
	quicksortArray(array, 0, (int)size - 1, size);
}
