#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - sorts an array of integers in ascending order using a
 * counting sort algorithm
 * @array: array of integers to be sorted
 * @size: amount of elements in array
 */
void counting_sort(int *array, size_t size)
{
    int i, index, max;
    int *arg_c, *output;

    if (!array || size < 2)
        return;

    max = array[0];
    for (i = 0; i < (int)size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    arg_c = calloc((max + 1), sizeof(int));
    if (!arg_c)
        return;

    for (i = 0; i < (int)size; i++)
        arg_c[array[i]]++;

    for (i = 0, index = 0; i < max + 1; i++)
    {
        index = arg_c[i] + index;
        arg_c[i] = index;
    }
    print_array(arg_c, max + 1);

    output = malloc(sizeof(int) * size);
    if (!output)
        return;

    for (i = (int)size - 1; i >= 0; i--)
    {
        output[arg_c[array[i]] - 1] = array[i];
        arg_c[array[i]]--;
    }

    for (i = 0; i < (int)size; i++)
        array[i] = output[i];

    free(arg_c);
    free(output);
}
