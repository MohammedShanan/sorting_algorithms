#include "deck.h"
int __strlen(const char *str)
{
    int i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}
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
int compare_values(const char *v1, const char *v2)
{
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
    if (__strlen(v1) < __strlen(v2))
        return (0);
    else if (__strlen(v1) > __strlen(v2))
        return (1);
    else if (v1[0] < v2[0])
        return (0);
    else
        return (1);
}
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