#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list
 * of integers in ascending order using Insertion sort
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current = (*list)->next;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

while (current != NULL)
{
listint_t *key = current;
listint_t *prev = current->prev;

while (prev != NULL && prev->n > key->n)
{
prev->next = key->next;
if (key->next != NULL)
key->next->prev = prev;

key->next = prev;
key->prev = prev->prev;

if (prev->prev != NULL)
prev->prev->next = key;
else
*list = key;

prev->prev = key;
prev = key->prev;

print_list(*list);
}

current = current->next;
}
}
