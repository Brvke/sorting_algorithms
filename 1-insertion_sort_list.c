#include "sort.h"

/**
 * insertion_sort_list - Function to sort a doubly linked list
 * containting integer using insertion sort algorithm.
 * @list: list to be sorted.
 * Return: Nothing.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *curr, *sorted_iter;

	if (!list || !(*list)->next)
		return;
	curr = (*list)->next;
	while (curr)
	{
		sorted_iter = curr->prev;
		temp = curr->next;
		if (curr->n > sorted_iter->n)
		{
			curr = curr->next;
			continue;
		}
		while (sorted_iter->n > curr->n)
		{
			sorted_iter->next = curr->next;
			if (curr->next)
				curr->next->prev = sorted_iter;
			curr->next = sorted_iter;
			if (sorted_iter->prev)
				sorted_iter->prev->next = curr;
			else
				*list = curr;
			curr->prev = sorted_iter->prev;
			sorted_iter->prev = curr;
			print_list(*list);
			if (!(sorted_iter->prev->prev))
				break;
			sorted_iter = sorted_iter->prev->prev;
		}
		curr = temp;
	}
}
