#include "sort.h"

/**
 * swap_head - swap head node and another node
 * @list: pointer to pointer to list
 * @current: current node to swap
 * @tmp: previous node to swap
 * Return: Nothing
 */
void swap_head(listint_t **list, listint_t *current, listint_t *tmp)
{
	if (current->next != NULL)
		current->next->prev = tmp;

	tmp->next = current->next;
	current->prev = NULL;
	tmp->prev = current;
	current->next = tmp;
	*list = current;
}

/**
 * swap_tail - swap tail node and another node
 * @current: current node to swap
 * @tmp: previous node to swap
 * Return: Nothing
 */
void swap_tail(listint_t *current, listint_t *tmp)
{
		tmp->next = NULL;
		current->prev = tmp->prev;
		tmp->prev->next = current;
		tmp->prev = current;
		current->next = tmp;
}
/**
 * swap_mid - swap two middle nodes in a list
 * @current: current node to swap
 * @tmp: previous node to swap
 * Return: Nothing
 */
void swap_mid(listint_t *current, listint_t *tmp)
{
	current->next->prev = tmp;
	tmp->next = current->next;
	current->prev = tmp->prev;
	tmp->prev->next = current;
	tmp->prev = current;
	current->next = tmp;
}

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

	if (&*list == NULL || *list == NULL || (*list)->next == NULL)
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
					swap_head(list, current, tmp);
				else if (current->next == NULL)
					swap_tail(current, tmp);
				else /*swap between middle nodes*/
					swap_mid(current, tmp);
				print_list(*list);
				j++;
				break;
			}
			current = current->next;
		}
	}
}
