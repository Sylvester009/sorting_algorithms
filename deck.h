#ifndef DECK_H
#define DECK_H


typedef enum kind_e
{
SPADE = 0,
HEART,
CLUB,
DIAMOND
} kind_t;

/**
 * struct card_s - this Plays as a card
 *
 * @value: it is the Value of the card
 * From "Ace" to "King"
 * @kind: this is Kind of the card
 */
typedef struct card_s
{
const char *value;
const kind_t kind;
} card_t;

/**
 * struct deck_node_s - this is the Deck of card
 *
 * @card: it Points  to the card of the node
 * @prev:this will  Point to the previous node of the list
 * @next: Points to the next node of the list
 */
typedef struct deck_node_s
{
const card_t *card;
struct deck_node_s *prev;
struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);
int _strcmp(const char *str1, const char *str2);
char gettervalues(deck_node_t *card);
void insertion_by_sorting(deck_node_t **deck);
void sorting_value(deck_node_t **deck);
int getCardValue(deck_node_t *card);
#endif /* DECK_H */
