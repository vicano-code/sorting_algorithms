#include "sort.h"
#include <stdlib.h>

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: array of integers
 * @size: size of array
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;
	int swapped;

	if (size < 2)
		return;
	else
	{
		for (i = 0; i < size; i++)
		{
			swapped = 0;
			for (j = 1; j < size; j++)
			{
				if (array[j - 1] > array[j])
				{
					tmp = array[j - 1];
					array[j - 1] = array[j];
					array[j] = tmp;
					print_array(array, size);
					swapped += 1;
				}
			}
			if (swapped == 0)
				break;
		}
	}
}
