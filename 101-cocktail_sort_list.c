#include "sort.h"

/**
 * swap_adjacent - it swaps two adjacent nodes
 * @list: doubly_linked list of int type to be sorted
 * @tail: it is node closer to head
 * @head: this is node closer to tail
 */
void swap_adjacent(listint_t **list, listint_t *tail, listint_t *head)
{
	listint_t *swap;

	if (tail->prev != NULL)
		tail->prev->next = head;
	else
		*list = head;

	if (head->next != NULL)
		head->next->prev = tail;

	head->prev = tail->prev;
	tail->prev = head;
	swap = head;
	tail->next = head->next;
	swap->next = tail;
	print_list(*list);
}

/**
 * forward_pass - performs forward passes of cocktail sort
 * @list: doubly linked list of int type to be sorted
 * @temp: current node pointer
 * @s_Range: range to be checked
 * @fowardswapped: boolean indicating if a forward swap occurred
 */
void forward_pass(listint_t **list, listint_t *temp,
int *s_Range, bool *fowardswapped)
{
	int checks;

	for (checks = 0; temp->next && checks < *s_Range; checks++)
	{
		if (temp->next->n < temp->n)
		{
			swap_adjacent(list, temp, temp->next);
			*fowardswapped = true;
		}
		else
		{
			temp = temp->next;
		}
	}
	if (!temp->next)
		*s_Range = checks;
}

/**
 * backward_pass - performs backward passes of cocktail sort
 * @list: doubly linked list of int type to be sorted
 * @temp: current node pointer
 * @s_Range: range to be checked
 * @backwardSwapped: pointer indicating if a backward swap occurred
 */
void backward_pass(listint_t **list, listint_t *temp,
int *s_Range, bool *backwardSwapped)
{
	int checks;

	for (checks = 0; temp->prev && checks < *s_Range; checks++)
	{
		if (temp->n < temp->prev->n)
		{
			swap_adjacent(list, temp->prev, temp);
			*backwardSwapped = true;
		}
		else
		{
			temp = temp->prev;
		}
	}
}

/**
 * cocktail_sort_list - sorts alist of integers in ascending order
 * @list: pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	bool fowardswapped, backwardSwapped;
	int s_Range = 1000000;
	listint_t *temp;

	if (!list || !(*list) || !(*list)->next)
		return;

	temp = *list;
	while (1)
	{
		fowardswapped = backwardSwapped = false;

		forward_pass(list, temp, &s_Range, &fowardswapped);

		if (fowardswapped)
			temp = temp->prev;

		s_Range--;

		backward_pass(list, temp, &s_Range, &backwardSwapped);

		if (backwardSwapped)
			temp = temp->next;

		if (!fowardswapped && !backwardSwapped)
			break;
	}
}
