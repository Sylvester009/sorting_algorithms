#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using a shell
 * sort algorithm, with gap sizes determined by a decreasing Knuth seqeuence
 * @array: array of integers to be sorted
 * @size: amount of elements in array
 */

void shell_sort(int *array, size_t size) {
    int temp;
    int j_index = 0;
    int num = (int)size;
    int space = 1;
    int K_max = 1;
    
    if (!array || size < 2)
        return;
    
    while (K_max < num) {
        space = K_max;
        K_max = (K_max * 3) + 1;
    }

    while (space > 0) {
        for (int index = space; index < num; index++) {
            temp = array[index];

            j_index = index;
            while (j_index >= space && array[j_index - space] > temp) {
                array[j_index] = array[j_index - space];
                j_index -= space;
            }

            array[j_index] = temp;
        }

        print_array(array, size);

        space = (space - 1) / 3;
    }
}
