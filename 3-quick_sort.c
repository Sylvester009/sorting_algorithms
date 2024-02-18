#include "sort.h"

/**
 * partitionArray - it scans a partition of arrays of int type for vals
 * less than pivot value, and swaps them with first value in partition.
 * @array: it array of int type to be sorted
 * @left: this is the index in the array that begins partition
 * @right: this is the index in the array that ends partition
 * @size: the amount of elements in an array
 * Return: it returns new index to which it start new
 * recursive partition
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
 * quicksortArray - it is the recursively sorts of an array of
 * int type which separating into two partitions using quick sort
 * @array: it array of int type to be sorted
 * @left: this is the index in the array that begins partition
 * @right: this is the index in the array that ends partition
 * @size: the amount of elements in an array
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
 * quick_sort - it sorts an array of int type in an ascending order
 * this uses a quick sort algorithm methode
 * @array: it array of int type to be sorted
 * @size: the amount of elements in an array
 */
void quick_sort(int *array, size_t size)
{
	while (!array || size < 2)
		return;
	quicksortArray(array, 0, (int)size - 1, size);
}
