#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to the doubly linked list of integers
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *node, *tmp;
	int i, listSize;

	node = *list;
	while (node)
	{
		listSize++;
		node = node->next;
	}
	while (i <= listSize * 2)
	{
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
				else if (current->next == NULL)
				{
					current->prev = tmp->prev;
					tmp->prev->next = current;
					tmp->prev = current;
					current->next = tmp;
					tmp->next = NULL;
				}
				else
				{
					current->prev = tmp->prev;
					current->next->prev = tmp;
					tmp->next = current->next;
					tmp->prev->next = current;
					tmp->prev = current;
					current->next = tmp;
				}
				print_list(*list);
				break;	
			}
			current = current->next;
		}
		i++;
	}
}
