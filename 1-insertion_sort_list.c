#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A doubly-linked list' head pointer.
 * @n1: A pointer to the first node to swap.
 * @n2: The second node to be swapped.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A doubly-linked list of integers head pointer.
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iterat, *algo, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iterat = (*list)->next; iterat != NULL; iterat = tmp)
	{
		tmp = iterat->next;
		algo = iterat->prev;
		while (algo != NULL && iterat->n < algo->n)
		{
			swap_nodes(list, &algo, iterat);
			print_list((const listint_t *)*list);
		}
	}
}
