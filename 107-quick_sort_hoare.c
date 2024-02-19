#include "sort.h"

/**
 * hoare_partition - this is a subset of an array of int type
 * that will  hoare  the partition scheme.
 * @array: This is the array of int type .
 * @size: This is the size of the array.
 * @start: this starts index of the subset.
 * @end: This ends index of the subset.
 *
 * Return: returns valve of The final partition index.
 *
 * Description: it  Uses the end element of the partition
 * to Print arrays after each swap happens.
 */
int p_hoare(int *array, size_t size, int start, int end)
{
    int pivot, up, down;

    pivot = array[end];
    up = start - 1;
    down = end + 1;

    while (up < down)
    {
        do {
            up++;
        } while (array[up] < pivot);

        do {
            down--;
        } while (array[down] > pivot);

        if (up < down)
        {
            integer_swapping(array + up, array + down);
            print_array(array, size);
        }
    }

    return (up);
}

/**
 * sorthoare -this actually Implement quicksort algorithm
 * through recursion method in c.
 * @array: This is the array of int type .
 * @size: This is the size of the array.
 * @start: this starts index of the subset.
 * @end: This ends index of the subset.
 *
 * Description: this Uses the Hoare partition methode to sort.
 */
void sorthoare(int *array, size_t size, int start, int end)
{
	int p;

	while (end - start > 0)
	{
		p = p_hoare(array, size, start, end);
		sorthoare(array, size, start, p - 1);
		sorthoare(array, size, p, end);
	}
}


/**
 * integer_swapping - this is the Swap between two int in an array.
 * @current: The first int to be swap.
 * @previous: The second int to be swap.
 */
void integer_swapping(int *previous, int *current)
{
	int tmp;

	tmp = *previous;
	*previous = *current;
	*current = tmp;
}
/**
 * quick_sort_hoare - it Sorts arrays of int type in an
 *ascending order using the quicksort algorithm method
 * @array: this is an array of int type.
 * @size: This is size of the array.
 *
 * Description: this will Use the Hoare partition method
 * and Prints arrays after each swap happens.
 */
void quick_sort_hoare(int *array, size_t size)
{
	while (array == NULL || size < 2)
		return;

	sorthoare(array, size, 0, size - 1);
}
