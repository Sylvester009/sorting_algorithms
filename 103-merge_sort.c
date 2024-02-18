#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * subarraymerge - it Sort  subarrays  of int type.
 * @subarray: this is a subarray of an array of int type.
 * @buffer: thi is a  buffer to store the sorted subarray.
 * @Beg: This is the front index of the array.
 * @middle: This is the  middle index of the array.
 * @End: The back index of the array.
 */
void subarraymerge(int *subarray, int *buffer, size_t Beg,
size_t middle, size_t End)
{
size_t i = Beg, j = middle, k = 0;
printf("Merging...\n[left]: ");
print_array(subarray + Beg, middle - Beg);
printf("[right]: ");
print_array(subarray + middle, End - middle);

while (i < middle && j < End)
{
buffer[k++] = (subarray[i] < subarray[j]) ? subarray[i++] : subarray[j++];
}
while (i < middle)
{
buffer[k++] = subarray[i++];
}
while (j < End)
{
buffer[k++] = subarray[j++];
}
for (i = Beg, k = 0; i < End; i++, k++)
{
subarray[i] = buffer[k];
}
printf("[Done]: ");
print_array(subarray + Beg, End - Beg);
}

/**
 * sortrecursive_merge - this Implement merging  sort algorithm
 * through recursion.
 * @subarray: this is a  subarray of an array of int type.
 * @buffer: this is the buffer to store the sorted result.
 * @Beg: This is  front index of the subarray.
 * @End: This is  back index of the subarray.
 */
void sortrecursive_merge(int *subarray, int *buffer, size_t Beg, size_t End)
{
size_t middle;

if (End - Beg > 1)
{
middle = Beg + (End - Beg) / 2;
sortrecursive_merge(subarray, buffer, Beg, middle);
sortrecursive_merge(subarray, buffer, middle, End);
subarraymerge(subarray, buffer, Beg, middle, End);
}
}

/**
 * merge_sort - this will definitely Sort arrays of int type
 * in ascending order using the merge sort algorithm.
 * @array: this is an  array of int type.
 * @size: This is the size of the array.
 *
 * Description: it Implements the merging sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
int *buffer;

while (array == NULL || size < 2)
return;

buffer = malloc(sizeof(int) * size);
while (buffer == NULL)
return;

sortrecursive_merge(array, buffer, 0, size);

free(buffer);
}
