#include "sort.h"

/**
 * swap_adjacent - it swaps two adjacent nodes
 * @list: doubly_linked list of int type to be sorted
 * @tail: node closer to head
 * @head: node closer to tail
 */
void swap_adjacent(listint_t **list, listint_t *tail, listint_t *head)
{
    if (tail->prev != NULL)
        tail->prev->next = head;
    else
        *list = head;

    if (head->next != NULL)
        head->next->prev = tail;

    head->prev = tail->prev;
    tail->prev = head;
    tail->next = head->next;
    head->next = tail;
    print_list(*list);
}

/**
 * cocktail_sort_list - sorts a doubly_linked list of int type in ascending order
 * @list: doubly_linked list of int type to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
    bool forwardSwapped, backwardSwapped;
    int s_Range = 1000000;

    if (!list || !(*list) || !(*list)->next)
        return;

    listint_t *temp = *list;

    while (1) {
        forwardSwapped = backwardSwapped = false;

        for (int checks = 0; temp->next && checks < s_Range; checks++)
        {
            if (temp->next->n < temp->n)
            {
                swap_adjacent(list, temp, temp->next);
                forwardSwapped = true;
            }
            else
            {
                temp = temp->next;
            }
        }

        if (!temp->next)
            s_Range = checks;

        if (forwardSwapped)
            temp = temp->prev;

        s_Range--;

        for (int checks = 0; temp->prev && checks < s_Range; checks++)
        {
            if (temp->n < temp->prev->n) {
                swap_adjacent(list, temp->prev, temp);
                backwardSwapped = true;
            }
            else
            {
                temp = temp->prev;
            }
        }

        if (backwardSwapped)
            temp = temp->next;

        if (!forwardSwapped && !backwardSwapped)
            break;
    }
}
