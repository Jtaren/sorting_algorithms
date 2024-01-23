#include "sort.h"

/**
 * list_swap - swaps the list elements
 * @head1: first list pointer
 * @head2: second list pointer
 * @n: n = 0 for increase, n = 1 for decrease
 *
 */
void list_swap(listint_t **head1, listint_t **head2, int n)
{
	listint_t *x, *tmp;

	x = *head1;
	tmp = *head2;

	x->next = tmp->next;
	tmp->prev = x->prev;

	if (tmp->next)
		tmp->next->prev = x;

	if (x->prev)
		x->prev->next = tmp;

	x->prev = tmp;
	tmp->next = x;

	if (n == 0)
		*head1 = tmp;
	else
		*head2 = x;
}

/**
 * ascend_sort - moves the bigger numbers to the far right
 * @head: bigger number pointer
 * @limit: list limit
 * @list: list of the doubly linked list
 *
 */
void ascend_sort(listint_t **head, listint_t **limit, listint_t **list)
{
	listint_t *x;

	for (x = *head; x != *limit && x->next != *limit; x = x->next)
	{
		if (x->n > x->next->n)
		{
			list_swap(&x, &(x->next), 0);
			if (x->prev == NULL)
				*list = x;
			print_list(*list);
		}
	}
	*limit = x;
	*head = x;
}

/**
 * descend_sort - moves the smaller numbers to the far left
 * @head: smaller number pointer
 * @limit: list limit
 * @list: list of the doubly linked list
 *
 */
void descend_sort(listint_t **head, listint_t **limit, listint_t **list)
{
	listint_t *x;

	for (x = *head; x != *limit && x->prev != *limit; x = x->prev)
	{
		if (x->n < x->prev->n)
		{
			list_swap(&(x->prev), &x, 1);
			if (x->prev->prev == NULL)
				*list = x->prev;
			print_list(*list);
		}
	}
	*limit = x;
	*head = x;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order
 * @list: list of the doubly linked list
 *
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *limit1, *limit2, *head;

	if (list == NULL)
		return;

	if (*list == NULL)
		return;

	limit1 = limit2 = NULL;
	head = *list;

	do {
		ascend_sort(&head, &limit1, list);
		descend_sort(&head, &limit2, list);
	} while (limit1 != limit2);
}
