#include "sort.h"

/**
 * selection_sort -  sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array of integers
 * @size: size of array
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, lowest_val_idx;
	int tmp;

	if (size < 2)
		print_array(array, size);
	else
	{
		for (i = 0; i < size; i++)
		{
			lowest_val_idx = i;
			for (j = i + 1; j < size; j++)
			{
				if (array[j] < array[lowest_val_idx])
					lowest_val_idx = j;
			}
			if (lowest_val_idx != i)
			{
				tmp = array[i];
				array[i] = array[lowest_val_idx];
				array[lowest_val_idx] = tmp;
				print_array(array, size);
			}
		}
	}
}
