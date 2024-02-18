#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using a shell
 * sort algorithm, with gap sizes determined by a decreasing Knuth seqeuence
 * @array: array of integers to be sorted
 * @size: amount of elements in array
 */
void shell_sort(int *array, size_t size)
{
  

    int num , space, index, j_index, temp;
  if (!array || size < 2)
        return;
    // Calculate initial gap value
    for (space = 1; space < num; space = (space * 3) + 1)
    {
    }

    // Start shell sort loop
    while (space > 0)
    {
        // Perform insertion sort with current gap value
        for (index = space; index < num; index++)
        {
            temp = array[index];
            for (j_index = index; j_index >= space && array[j_index - space] > temp; j_index -= space)
            {
                array[j_index] = array[j_index - space];
            }
            array[j_index] = temp;
        }

        // Update gap value
        space = (space - 1) / 3;

        // Print array after each iteration
        print_array(array, size);
    }
}
