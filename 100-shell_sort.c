#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using a shell
 * sort algorithm, with gap sizes determined by a decreasing Knuth seqeuence
 * @array: array of integers to be sorted
 * @size: amount of elements in array
 */
void shell_sort(int *array, size_t size)
{


    int num = static_cast<int>(size);
    int space = 1;
if (!array || size < 2)
return;
    while (space < num / 3)
    {
        space = space * 3 + 1;
    }

    while (space >= 1)
    {
        for (int index = space; index < num; ++index)
        {
            int temp = array[index];
            int j_index = index;
            while (j_index >= space && array[j_index - space] > temp)
            {
                array[j_index] = array[j_index - space];
                j_index -= space;
            }
            array[j_index] = temp;
        }
        print_array(array, size);
        space = (space - 1) / 3;
    }
}
