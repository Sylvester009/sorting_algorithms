#include "sort.h"
#include <stdio.h>

/**
 * bitoniComp - this is a helper, and it sorts contents of current
 * subarray
 * @boolean: if true, sort in ascending order, false, descending
 * @subarray: subarray in current frame of recursion
 * @size: number of elements in `x`
 */
void bitoniComp(bool boolean, int *subarray, size_t size)
{
size_t dist = size / 2;
size_t index = 0;

while (index < dist)
{
if ((subarray[index] > subarray[index + dist]) == boolean)
{
int temp = subarray[index];
subarray[index] = subarray[index + dist];
subarray[index + dist] = temp;
}
index++;
}
}

/**
 * merge_bitonic - this is the second recursive function,that sorts subarrays
 * through bitonic_compare, and merges
 * @boolean: when a statement true, it sort in ascending order
 * and when false descending order
 * @subarray: this is the subarray in previous frame of recursion
 * @size: the number of elements in 'x'(subarray)
 * @first_size: the number of elements in source array being sorted
 */
void merge_bitonic(bool boolean, int *subarray, size_t size, size_t first_size)
{
int *st, *nd;

while (size > 1)
{
st = subarray;
nd = subarray + (size / 2);
bitoniComp(boolean, subarray, size);
merge_bitonic(boolean, st, size / 2, first_size);
merge_bitonic(boolean, nd, size / 2, first_size);
}
}

/**
 * sortbitonic - this is the first recursive valve
 * of bitonic_sort that is  divided into a binary tree of
 * subarrays the  assigns sorting order.
 * @boolean:  when a statement true, it sort in ascending
 *  and when false descending order
 * @subarray: this is the subarray in previous frame of recursion
 * @size: the number of elements in 'x'(subarray)
 * @first_size: the number of elements in source array being sorted
 */
void sortbitonic(bool boolean, int *subarray, size_t size, size_t first_size)
{
int *st, *nd;
if (size <= 1)
return;
st = subarray;
nd = subarray + (size / 2);
printf("Merging [%lu/%lu] (%s):\n", size, first_size,
(boolean ? "UP" : "DOWN"));
print_array(subarray, size);
sortbitonic(true, st, size / 2, first_size);
sortbitonic(false, nd, size / 2, first_size);
merge_bitonic(boolean, st, size, first_size);
printf("Result [%lu/%lu] (%s):\n", size, first_size,
(boolean ? "UP" : "DOWN"));
print_array(subarray, size);
}

/**
 * bitonic_sort - it sorts arrays of int type
 * in ascending order using a bitonic sort alogrithm method
 * @array: this is the array values to be printed
 * @size: this is the number of elements in array
 */
void bitonic_sort(int *array, size_t size)
{
if (!array || size == 0)
return;
sortbitonic(true, array, size, size);
}
