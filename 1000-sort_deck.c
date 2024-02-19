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
 * @card: A pointer to a deck_node_t card.
 *
 * Return: The numerical value of the card.
 */
char gettervalues(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertion_by_sorting - it Sorts by  spading to diamonds.
 * @deck: this is a pointer thst points to  the head of
 * a deck_node_t doubly-linked list.
 */
void insertion_by_sorting(deck_node_t **deck)
{
	deck_node_t *iteration, *insert, *tmp;

	for (iteration = (*deck)->next; iteration != NULL; iteration = tmp)
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
				*deck = iteration;
			insert->prev = iteration;
			insert = iteration->prev;
		}
	}
}

/**
 * sorting_value - it is Sorts  sorted from
 * spades to diamonds.
 * @deck: this is a  pointer that points to the
 * head of a deck_node_t doubly-linked list.
 */
void sorting_value(deck_node_t **deck)
{
	deck_node_t *iteration, *insert, *tmp;

	for (iteration = (*head)->next; iteration != NULL; iteration = tmp)
	{
		tmp = iteration->next;
		insert = iteration->prev;
		while (insert != NULL &&
		       insert->card->kind == iteration->card->kind &&
		       gettervalues(insert) > gettervalues(iteration))
		{
			insert->next = iteration->next;
			if (iteration->next != NULL)
				iteration->next->prev = insert;
			iteration->prev = insert->prev;
			iteration->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iteration;
			else
				*deck = iteration;
			insert->prev = iteration;
			insert = iteration->prev;
		}
	}
}

/**
 * sort_deck - its Sorts from spades to diamonds.
 * @deck: this is a  pointer that points to the
 * head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_by_sorting(deck);
	sorting_value(deck);
}
