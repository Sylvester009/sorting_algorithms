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

/**
 * cocktail_sort_list - it is sorts a doubly_linked list of int type
 * in ascending order
 * @list: doubly_linked list of intm type to be sorted
 */
void cocktail_sort_list(listint_t **list) {
    if (!list || !(*list) || !(*list)->next)
        return;

    bool forwardSwapped, backwardSwapped;
    int s_Range = 1000000;
    listint_t *temp = *list;

    while (1) {
        forwardSwapped = backwardSwapped = false;

        // Forward pass
        temp = forward_pass(list, temp, &forwardSwapped, &s_Range);

        // Adjust range if needed
        if (!temp->next)
            s_Range = get_remaining_range(temp, s_Range);

        // Backward pass
        temp = backward_pass(list, temp, &backwardSwapped, &s_Range);

        // Check if no swaps occurred, break if so
        if (!forwardSwapped && !backwardSwapped)
            break;
    }
}

listint_t* forward_pass(listint_t **list, listint_t *temp, bool *forwardSwapped, int *s_Range) {
    int checks;

    for (checks = 0; temp->next && checks < *s_Range; checks++) {
        if (temp->next->n < temp->n) {
            swap_adjacent(list, temp, temp->next);
            *forwardSwapped = true;
        } else {
            temp = temp->next;
        }
    }
    return temp;
}

listint_t* backward_pass(listint_t **list, listint_t *temp, bool *backwardSwapped, int *s_Range) {
    int checks;

    for (checks = 0; temp->prev && checks < *s_Range; checks++) {
        if (temp->n < temp->prev->n) {
            swap_adjacent(list, temp->prev, temp);
            *backwardSwapped = true;
        } else {
            temp = temp->prev;
        }
    }
    return temp;
}

int get_remaining_range(listint_t *temp, int s_Range) {
    int count = 0;
    while (temp->next && count < s_Range) {
        temp = temp->next;
        count++;
    }
    return count;
}
