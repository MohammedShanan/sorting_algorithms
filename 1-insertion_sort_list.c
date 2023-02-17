#include "sort.h"
/**
 * insertion_sort_list - inserts right unsorted side into left sorted side
 * @list: doubly linked list to sort
 *
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *tmp;
if (list == NULL || !(*list) || (*list)->next == NULL)
return;
current = *list;
while (current->next)
{
if (current->n > current->next->n)
{
tmp = current->next;
while (tmp->prev && tmp->n < tmp->prev->n)
{
tmp->prev->next = tmp->next;
if (tmp->next != NULL)
tmp->next->prev = tmp->prev;
tmp->prev = tmp->prev->prev;
if (tmp->prev != NULL)
{
tmp->next = tmp->prev->next;
tmp->prev->next = tmp;
}
else
{
tmp->next = (*list);
*list = tmp;
}
tmp->next->prev = tmp;
print_list(*list);
}
}
else
current = current->next;
}
}
