#include "sort.h"

/**
 * shell_sort -  sorts an array of integers in ascending order using
 *  the Shell sort algorithm, using the Knuth sequence
 * @array: array of integers
 * @size: size of array
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t gap;
	int i, j, n;
	int tmp;

	n = size - 1;
	gap = n * 3 + 1;
	while (gap > 0 && gap < size)
	{
		j = n;
		for (i = gap; i >= 0; i -= gap)
		{
			if (array[j] > array[i])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j -= gap;
		}
		n--;
		gap = n * 3 + 1;
		print_array(array, size);
	}
}
