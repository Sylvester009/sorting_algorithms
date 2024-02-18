#include "sort.h"

/**
 * selection_sort - sorts an array of integers using a selction sort
 * algorithm
 * @array: array of integers to be sorted
 * @size: amount of elements in array
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

        /* Find the index of the minimum value in the remaining unsorted part of the array */
        while (jIndex < num)
        {
            if (array[jIndex] < array[minIndex])
            {
                minIndex = jIndex;
            }
            jIndex++;
        }

        /* Swap the current element with the minimum element if they are not the same */
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
