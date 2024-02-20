#ifndef SORT_H
#define SORT_H
#include <stddef.h>


/**
 * enum bool_e - this is the manual definition of booleans
 * in case C99 stdbool.h not available
 * @false: the logical is 0
 * @true: the logical is 1
 */
typedef enum bool_e
{
	false = 0,
	true
} bool;

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

/* helpers */
int partitionArray(int *array, int left, int right, size_t size);
void quicksortArray(int *array, int left, int right, size_t size);
void integerswapping(int *previous, int *current);
void swap_adjacent(listint_t **list, listint_t *tail, listint_t *head);
void sortrecursive_merge(int *subarray, int *buffer, size_t Beg, size_t End);
void subarraymerge(int *subarray, int *buffer, size_t Beg,
size_t middle, size_t End);
int getmaximum_s(int *array, int size);
void counting_radix(int *array, size_t size, int digit, int *buffer);
void bitoniComp(bool boolean, int *subarray, size_t size);
void merge_bitonic(bool boolean, int *subarray, size_t size,
size_t first_size);
void bitonic_sort_r(bool boolean, int *subarray, size_t size,
size_t first_size);
void ints_swapping(int *previous, int *current);
void ConvertToHeap(int *array, size_t size, size_t end, size_t start);
int p_hoare(int *array, size_t size, int start, int end);
void sorthoare(int *array, size_t size, int start, int end);
void integer_swapping(int *previous, int *current);


#endif /* SORT_H */
