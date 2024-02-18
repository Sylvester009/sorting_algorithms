#include "sort.h"

/**
 * selection_sort - sorts an array of integers using a selction sort
 * algorithm
 * @array: array of integers to be sorted
 * @size: amount of elements in array
 */
void selection_sort(int *array, size_t size)
{
int index_i, index_j, min_index_j, temp, array_size = (int)size;

if (!array || size < 2)
    return;

/* at every position in the n-member array */
for (index_i = 0; index_i < array_size - 1; index_i++)
{
    /* scan from that position to the end */
    min_index_j = index_i;
    for (index_j = index_i + 1; index_j < array_size; index_j++)
    {
        /* determine the minimum value in that range */
        if (array[index_j] < array[min_index_j])
        {
            min_index_j = index_j;
        }
    }
    /* and if it is lower than the value at the start of the range, */
    /* swap them */
    if (min_index_j != index_i)
    {
        temp = array[index_i];
        array[index_i] = array[min_index_j];
        array[min_index_j] = temp;
        print_array(array, size);
    }
}
