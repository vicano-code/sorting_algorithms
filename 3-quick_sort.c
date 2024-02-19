#include "sort.h"

/**
 * swap - swap two array index values
 * @array: array of integers
 * @a: first index to swap
 * @b: second index to swap
 * Return: nothing
 */
void swap(int *array, size_t a, size_t b)
{
	int tmp;

	tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
}

/**
 * lomuto_partition - Lomuto partitioning scheme for quicksort
 * @array: array of integers
 * @size: size of array
 * @low: moving index starting from lowest index
 * @high: moving index starting from highest index
 * Return: Nothing
 */
size_t lomuto_partition(int *array, size_t size, size_t low, size_t high)
{
	int pivot;
	size_t i, j;

	pivot = array[high];
	i = low - 1;
	for (j = low; j <= high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(array, i, j);
		}
	}
	swap(array, i + 1, high);
	print_array(array, size);
	return (i + 1);

}

/**
 * apply_sort - sort the array
 * @array: the array of integers
 * @size: array size
 * @low: the lowest index of an array partition
 * @high: the highest index of an array partition
 * Return: nothing
 */
void apply_sort(int *array, size_t size, int low, int high)
{
	int piv;

	if (low < high)
	{
		piv = lomuto_partition(array, size, low, high);
		apply_sort(array, size, low, piv - 1);
		apply_sort(array, size, piv + 1, high);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array of integers
 * @size: size of array
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	size_t low;
	size_t high;

	if (size < 2)
		return;
	low = 0;
	high = size - 1;
	apply_sort(array, size, low, high);
}
