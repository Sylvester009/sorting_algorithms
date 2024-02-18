#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using a shell
 * sort algorithm, with gap sizes determined by a decreasing Knuth seqeuence
 * @array: array of integers to be sorted
 * @size: amount of elements in array
 */
void shell_sort(int *array, size_t size)
{
    int index, j_index, space, num, temp;

    if (!array || size < 2)
        return;

    num = (int)size;
    int K_max = 1;
    while (K_max < num / 3)
    {
        K_max = K_max * 3 + 1;
    }

    for (space = K_max; space > 0; space /= 3)
    {
        for (index = space; index < num; index++)
        {
            temp = array[index];
            for (j_index = index; j_index >= space && array[j_index - space] > temp; j_index -= space)
            {
                array[j_index] = array[j_index - space];
            }
            array[j_index] = temp;
        }
        print_array(array, size);
    }
}
