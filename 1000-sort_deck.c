#include "deck.h"
/**
 * split_list - split the linked list in two
 * @head: head node of linked list
 * @a: pointer to store the first half of the list
 * @b: pointer to store the second half of the list
 */
void split_list(deck_node_t *head, deck_node_t **a, deck_node_t **b)
{
deck_node_t *fast, *slow;
slow = head;
fast = head->next;
while (fast != NULL)
{
fast = fast->next;
if (fast != NULL)
{
slow = slow->next;
fast = fast->next;
}
}
*a = head;
*b = slow->next;
slow->next = NULL;
}
/**
 * compare_values - compare the values of the cards
 * @v1: value for first card
 * @v2: value for second card
 * Return: 0 if v1 if smaller than v2 else 1
 **/
int compare_values(const char *v1, const char *v2)
{
int len_v1 = 0, len_v2 = 0;
while (v1[len_v1] || v2[len_v2])
{
if (v1[len_v1])
len_v1++;
if (v2[len_v2])
len_v2++;
}
if (v1[0] == 'A')
return (0);
else if (v2[0] == 'A')
return (1);
if (v1[0] > '9' && v2[0] > '9')
{
if (v1[0] == 'J' && (v2[0] == 'Q' || v2[0] == 'K'))
return (0);
else if (v1[0] == 'Q' && v2[0] == 'K')
return (0);
else
return (1);
}
if (len_v1 < len_v2)
return (0);
else if (len_v1 > len_v2)
return (1);
else if (v1[0] < v2[0])
return (0);
else
return (1);
}
/**
 * compare_cards - compare the cards
 * @card1:first card
 * @card2:second card
 * Return: 0 if v1 if smaller than v2 else 1
 **/
int compare_cards(const card_t *card1, const card_t *card2)
{
if (card1->kind == card2->kind)
{
return (compare_values(card1->value, card2->value));
}
else if (card1->kind < card2->kind)
{
return (0);
}
else
{
return (1);
}
}
/**
 * merge_sorted_lists - merge the two sorted lists
 * @a: pointer to the first list
 * @b: pointer to the second list
 * Return: a sorted list
 */
deck_node_t *merge_sorted_lists(deck_node_t *a, deck_node_t *b)
{
deck_node_t *sorted_list;
if (a == NULL)
{
return (b);
}
else if (b == NULL)
{
return (a);
}
if (compare_cards(a->card, b->card) == 0)
{
sorted_list = a;
sorted_list->next = merge_sorted_lists(a->next, b);
}
else
{
sorted_list = b;
sorted_list->next = merge_sorted_lists(a, b->next);
}

return (sorted_list);
}
/**
 * sort_deck - merge the two sorted lists
 * @deck: deack to be sorted
 **/
void sort_deck(deck_node_t **deck)
{
deck_node_t *head, *list_1, *list_2;
head = *deck;
list_1 = list_2 = NULL;
if (head == NULL || head->next == NULL)
{
return;
}
split_list(head, &list_1, &list_2);
sort_deck(&list_1);
sort_deck(&list_2);
*deck = merge_sorted_lists(list_1, list_2);
}
