#include "sort.h"
/**
 * swap - swaps both
 * @p: first node to swap
 * @c: second node to swap
 * @list: list to set null or not
 */
void swap(listint_t *node1, listint_t *node2, listint_t **list)
{
    node1->next = node2->next;
    node2->prev = node1->prev;
    if (node2->next)
    {
        node2->next->prev = node1;
    }
    if (node1->prev)
    {
        node1->prev->next = node2;
    }
    else
    {
        *list = node2;
    }
    node1->prev = node2;
    node2->next = node1;
}
/**
 * cocktail_sort_list - inserts right unsorted side into left sorted side
 * @list: doubly linked list to sort
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *current;
    int swapped = 1;
    current = *list;
    while (swapped)
    {
        swapped = 0;
        while (current->next)
        {
            if (current->n > current->next->n)
            {
                swap(current, current->next, list);
                print_list(*list);
                swapped = 1;
            }
            else
            {
                current = current->next;
            }
        }
        current = current->prev;
        while (current->prev)
        {
            if (current->n < current->prev->n)
            {
                swap(current->prev, current, list);
                print_list(*list);
                swapped = 1;
            }
            else
            {
                current = current->prev;
            }
        }
        current = current->next;
    }
}
