#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to the doubly linked list of integers
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;
	int j = 1;

	if (*list == NULL || (*list)->next == NULL)
		return;
	while (j != 0)
	{
		j = 0;
		current = (*list)->next;
		while (current)
		{
			if (current->n < current->prev->n)
			{
				tmp = current->prev;
				if (tmp->prev == NULL)
				{
					current->next->prev = tmp;
					tmp->next = current->next;
					current->prev = NULL;
					tmp->prev = current;
					current->next = tmp;
					*list = current;
				}
				else
				{
					if (current->next == NULL)
						tmp->next = NULL;
					else
					{
						current->next->prev = tmp;
						tmp->next = current->next;
					}
					current->prev = tmp->prev;
					tmp->prev->next = current;
					tmp->prev = current;
					current->next = tmp;
				}
				print_list(*list);
				j++;
				break;
			}
			current = current->next;
		}
	}
}
