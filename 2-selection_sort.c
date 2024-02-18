#include "sort.h"

/**
 * selection_sort - it sorts arrays of int type using
 * a selctions of algorithm
 * @array: it is the  array of int to be sorted
 * @size: the amount of elements in an array
 */
void selection_sort(int *array, size_t size)
{
int currentIndex = 0, jIndex, minIndex, temp, num = (int)size;

if (!array || size < 2)
return;

/* Iterate until the current index reaches the end of the array */
while (currentIndex < num - 1)
{
minIndex = currentIndex;
jIndex = currentIndex + 1;

/* Find the index of the min val in the  unsorted part of the array */
while (jIndex < num)
{
if (array[jIndex] < array[minIndex])
{
minIndex = jIndex;
}
jIndex++;
}
/* Swap the current element with the min element if they're not the same */
if (minIndex != currentIndex)
{
temp = array[currentIndex];
array[currentIndex] = array[minIndex];
array[minIndex] = temp;
print_array(array, size);
}

currentIndex++;
}
}
