#include "sort.h"

/**
 * selection_sort - sorts an array of integers using a selction sort
 * algorithm
 * @array: array of integers to be sorted
 * @size: amount of elements in array
 */
void selection_sort(int *array, size_t size)
 {
    if (!array || size < 2)
        return;

    int currentIndex, scanIndex, minIndex, temp, n = static_cast<int>(size);

    // At every position in the n-member array
    for (currentIndex = 0; currentIndex < n - 1; currentIndex++) {
        // Scan from that position to the end
        minIndex = currentIndex;
        for (scanIndex = currentIndex + 1; scanIndex < n; scanIndex++) {
            // Determine the minimum value in that range
            if (array[scanIndex] < array[minIndex]) {
                minIndex = scanIndex;
            }
        }
        // If the minimum value is lower than the value at the start of the range, swap them
        if (minIndex != currentIndex) {
            temp = array[currentIndex];
            array[currentIndex] = array[minIndex];
            array[minIndex] = temp;
            printArray(array, size);
        }
    }
}
