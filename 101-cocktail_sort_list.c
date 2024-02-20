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

if (tail->prev != NULL) {
tail->prev->next = head;
}
else
{
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
 * forward_pass - Perform the forward pass of the cocktail sort
 * @list: doubly_linked list of int type to be sorted
 * @temp: pointer to the current node
 * @forwardSwapped: pointer to a boolean indicating if a forward swap occurred
 * @s_Range: the range of elements to check
 * @return: pointer to the current node after the forward pass
 */
listint_t* forward_pass(listint_t **list, listint_t *temp, bool *forwardSwapped, int s_Range)
{
int checks;
for (checks = 0; temp->next && checks < s_Range; checks++) {
if (temp->next->n < temp->n)
{
swap_adjacent(list, temp, temp->next);
*forwardSwapped = true;
}
else
{
temp = temp->next;
}
}
return (temp);
}

/**
 * backward_pass - Perform the backward pass of the cocktail sort
 * @list: doubly_linked list of int type to be sorted
 * @temp: pointer to the current node
 * @backwardSwapped: pointer to a boolean indicating if a backward swap occurred
 * @s_Range: the range of elements to check
 * @return: pointer to the current node after the backward pass
 */
listint_t* backward_pass(listint_t **list, listint_t *temp, bool *backwardSwapped, int s_Range)
{
int checks;
for (checks = 0; temp->prev && checks < s_Range; checks++)
{
if (temp->n < temp->prev->n) {
swap_adjacent(list, temp->prev, temp);
*backwardSwapped = true;
} else {
temp = temp->prev;
}
}
return (temp);
}

/**
 * cocktail_sort_list - it is sorts a doubly_linked list of int type
 * in ascending order
 * @list: doubly_linked list of int type to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
int s_Range = 1000000;
listint_t *temp;
bool forwardSwapped, backwardSwapped;
if (!list || !(*list) || !(*list)->next)
return;
temp = *list;
while (1)
{
forwardSwapped = backwardSwapped = false;

temp = forward_pass(list, temp, &forwardSwapped, s_Range);

if (!temp->next)
s_Range = count_remaining_nodes(temp, s_Range);

temp = backward_pass(list, temp, &backwardSwapped, s_Range);

if (!forwardSwapped && !backwardSwapped)
break;
}
}
