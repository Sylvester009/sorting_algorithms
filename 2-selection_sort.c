#include "sort.h"

/**
 * selection_sort - sorts an array of integers using a selction sort
 * algorithm
 * @array: array of integers to be sorted
 * @size: amount of elements in array
 */
void selection_sort(int *array, size_t size)
{
int index_i = 0, index_j, min_index_j, temp, array_size = (int)size;

if (!array || size < 2)
    return;

/* At every position in the n-member array */
while (index_i < array_size - 1)
{
    /* Scan from that position to the end */
    min_index_j = index_i;
    index_j = index_i + 1;
    while (index_j < array_size)
    {
        /* Determine the minimum value in that range */
        if (array[index_j] < array[min_index_j])
        {
            min_index_j = index_j;
        }
        index_j++;
    }
    if (min_index_j != index_i)
    {
        temp = array[index_i];
        array[index_i] = array[min_index_j];
        array[min_index_j] = temp;
        print_array(array, size);
    }
    index_i++;
}
