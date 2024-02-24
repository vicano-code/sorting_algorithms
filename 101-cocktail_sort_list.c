#include "sort.h"

/**
 * cocktail_sort_list -  sorts a doubly linked list of integers in
 * ascending order using the Cocktail shaker sort algorithm
 * @array: array of integers
 * @size: size of array
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start, *end, *tmp1, *tmp2;

	if (*list == NULL || *(*list) == NULL || (*list)->next == NULL)
		return;
	while (swapped > 0)
	{
		start = *list;
		while (start)
		{
			swapped = 0;
			if (start->n > start->next->n)
			{
				swapped++;
				tmp1 = start->next;
				if (start->prev == NULL)
					swap_head(list, tmp1, start);
				else if (start->next == NULL)
					swap_tail(tmp1, start);
				else
					swap_mid(tmp1, start);
				print_list(*list);
			}
			if (swapped == 0)
				start = start->next;
		}
		end = *list;
		while (end->next != NULL)
			end = end->next;
		/*end = start->prev;*/
		while (end->prev != NULL)
		{
			swapped = 0;
			if (end->n < end->prev->n)
			{
				swapped++;
				tmp2 = end->prev;
				if (tmp2 == NULL)
					swap_head(list, end, tmp2);
				else
					swap_mid(end, tmp2);
				print_list(*list);
			}
			if (swapped == 0)
				end = end->prev;
		}

	}
}
