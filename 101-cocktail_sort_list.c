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
{
tail->prev->next = head;
}
else
{
*list = head;
}
if (head->next != NULL)
{
head->next->prev = tail;
}
head->prev = tail->prev;
tail->prev = head;
swap = head;
tail->next = head->next;
swap->next = tail;
print_list(*list);
}

void backward_pass(listint_t **list, listint_t *temp, bool *backwardSwapped, int s_Range)
{
int checks;

for (checks = 0; temp->prev && checks < s_Range; checks++) {
if (temp->n < temp->prev->n) {
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
 * cocktail_sort_list - it is sorts a doubly_linked list of int type
 * in ascending order
 * @list: doubly_linked list of intm type to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
bool fowardswapped, backwardSwapped;
int s_Range = 1000000, checks;
listint_t *temp;
if (!list || !(*list) || !(*list)->next)
return;
temp = *list;
while (1)
{
fowardswapped = backwardSwapped = false;
for (checks = 0; temp->next && checks < s_Range; checks++)
{
if (temp->next->n < temp->n)
{
swap_adjacent(list, temp, temp->next);
fowardswapped = true;
}
else
{
temp = temp->next;
}
}
if (!temp->next)
s_Range = checks;
if (fowardswapped)
temp = temp->prev;
s_Range--;
backward_pass(list, temp, &backwardSwapped, s_Range);
if (backwardSwapped)
temp = temp->next;
if (!fowardswapped && !backwardSwapped)
break;
}
}
