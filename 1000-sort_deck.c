#include "deck.h"
#include <stddef.h>
/**
 * _strcmp - This Compares two strings.
 * @str1: This the  first string to be compared.
 * @str2: This the second string to be compared.
 *
 * Return: return Positive byte difference if str1 > str2
 *         0 if str1 == str2
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	if (*str1 != *str2)
		return (*str1 - *str2);
	return (0);
}

/**
 * gettervalues - Get the numerical value of a card.
 * @point: A pointer to a deck_node_t card.
 *
 * Return: The numerical value of the card.
 */
char gettervalues(deck_node_t *point)
{
	if (_strcmp(point->point->value, "Ace") == 0)
		return (0);
	if (_strcmp(point->point->value, "1") == 0)
		return (1);
	if (_strcmp(point->point->value, "2") == 0)
		return (2);
	if (_strcmp(point->point->value, "3") == 0)
		return (3);
	if (_strcmp(point->point->value, "4") == 0)
		return (4);
	if (_strcmp(point->point->value, "5") == 0)
		return (5);
	if (_strcmp(point->point->value, "6") == 0)
		return (6);
	if (_strcmp(point->point->value, "7") == 0)
		return (7);
	if (_strcmp(point->point->value, "8") == 0)
		return (8);
	if (_strcmp(point->point->value, "9") == 0)
		return (9);
	if (_strcmp(point->point->value, "10") == 0)
		return (10);
	if (_strcmp(point->point->value, "Jack") == 0)
		return (11);
	if (_strcmp(point->point->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertion_by_sorting - it Sorts by  spading to diamonds.
 * @head: this is a pointer thst points to  the head of
 * a deck_node_t doubly-linked list.
 */
void insertion_by_sorting(deck_node_t **head)
{
	deck_node_t *iteration, *insert, *tmp;

	for (iteration = (*deck)->next; iteration != NULL; iter = tmp)
	{
		tmp = iteration->next;
		insert = iteration->prev;
		while (insert != NULL && insert->card->kind > iteration->card->kind)
		{
			insert->next = iteration->next;
			if (iteration->next != NULL)
				iteration->next->prev = insert;
			iteration->prev = insert->prev;
			iteration->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iteration;
			else
				*head = iteration;
			insert->prev = iteration;
			insert = iteration->prev;
		}
	}
}

/**
 * sorting_value - it is Sorts  sorted from
 * spades to diamonds.
 * @head: this is a  pointer that points to the
 * head of a deck_node_t doubly-linked list.
 */
void sorting_value(deck_node_t **head)
{
	deck_node_t *iteration, *insert, *tmp;

	for (iteration = (*head)->next; iteration != NULL; iteration = tmp)
	{
		tmp = iteration->next;
		insert = iteration->prev;
		while (insert != NULL &&
		       insert->card->kind == iteration->card->kind &&
		       get_value(insert) > get_value(iteration))
		{
			insert->next = iteration->next;
			if (iteration->next != NULL)
				iteration->next->prev = insert;
			iteration->prev = insert->prev;
			iteration->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iteration;
			else
				*head = iteration;
			insert->prev = iteration;
			insert = iteration->prev;
		}
	}
}

/**
 * sort_deck - its Sorts from spades to diamonds.
 * @head: this is a  pointer that points to the
 * head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **head)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deck_kind(deck);
	insertion_sort_deck_value(deck);
}
