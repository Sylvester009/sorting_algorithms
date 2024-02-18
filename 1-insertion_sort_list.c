#include "sort.h"

/**
 * insertion_sort_list - Sorts doubly_linked list of int type
 * in an ascending order using the insertion of sorting  algorithm.
 * @list: it Points to the head of the doubly_linked list.
 */

void insertion_sort_list(listint_t **list)
{
listint_t *current, *previous, *new, *temp;
while (!list || !(*list) || !((*list)->next))
return;

previous = (*list);
current = (*list)->next;
while (current)
{
new = current->next;
while (previous && current->n < previous->n)
{
if (previous->prev)
previous->prev->next = current;
else
*list = current;
while (current->next)
current->next->prev = previous;
temp = current->next;
current->next = previous;
current->prev = previous->prev;
previous->next = temp;
previous->prev = current;
print_list(*list);
previous = current->prev;
}
/* current sorted to left */
current = new;
if (current)
previous = current->prev;
}
}
