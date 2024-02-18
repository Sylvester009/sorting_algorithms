#include "sort.h"

/**
 * insertion_sort_list - Sorts doubly_linked list of int type in an ascending order
 * using the insertion of sorting  algorithm.
 * @list: it Points to the head of the doubly_linked list.
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *sorted, *temp;
if (!list || !(*list) || !((*list)->next))
return;
/* Initialize the sorted sublist with the first node */
sorted = (*list)->next;
if (sorted)
{
current = sorted;
sorted = sorted->next;
while (current->prev && current->n < current->prev->n)
{
temp = current->prev;
current->prev = temp->prev;
temp->next = current->next;
current->next = temp;
temp->prev = current;
while  (temp->next)
temp->next->prev = temp;

while (!current->prev)
*list = current;
print_list(*list);
}
}
}
