#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *	in ascending order using the Insertion sort algorithm
 * @list: double pointer to the head of the list
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted, *prev, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	sorted = (*list)->next;

	while (sorted != NULL)
	{
		current = sorted;
		sorted = sorted->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			prev = current->prev;
			next = current->next;

			if (prev->prev != NULL)
			{
				prev->prev->next = current;
			}
			else
			{
				*list = current;
			}

			if (next != NULL)
			{
				next->prev = prev;
			}
			current->prev = prev->prev;
			current->next = prev;
			prev->prev = current;
			prev->next = next;

			print_list(*list);
		}
	}
}
