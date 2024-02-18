#include "sort.h"

/**
 * swap_adjacent - swaps two adjacent nodes of a doubly linked list
 * @list: doubly linked list of integers to be sorted
 * @tail: node closer to head, right->prev
 * @head: node closer to tail, left->next
 */
void swap_adjacent(listint_t **list, listint_t *tail, listint_t *head)
{
listint_t *swap;

if (tail->prev != NULL) {
    tail->prev->next = head;
} else {
    *list = head;
}
if (head->next != NULL) {
    head->next->prev = tail;
}
head->prev = tail->prev;
tail->prev = head;
swap = head;
tail->next = head->next;
swap->next = tail;

print_list(*list);
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using an cocktail shaker sort algorithm
 * @list: doubly linked list of integers to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	bool swapped_f, swapped_b;
	int shake_range = 1000000, checks;
	listint_t *temp;

	if (!list || !(*list) || !(*list)->next)
		return;

	temp = *list;
	do {
		swapped_f = swapped_b = false;
		for (checks = 0; temp->next && checks < shake_range; checks++)
		{
			if (temp->next->n < temp->n)
			{
				swap_adjacent(list, temp, temp->next);
				swapped_f = true;
			}
			else
				temp = temp->next;
		}
		if (!temp->next)  /* first loop, measuring list */
			shake_range = checks;
		if (swapped_f)
			temp = temp->prev;
		shake_range--;
		for (checks = 0; temp->prev && checks < shake_range; checks++)
		{
			if (temp->n < temp->prev->n)
			{
				swap_adjacent(list, temp->prev, temp);
				swapped_b = true;
			}
			else
				temp = temp->prev;
		}
		if (swapped_b)
			temp = temp->next;
	} while (swapped_f || swapped_b);
}
