#include "sort.h"

/**
 * lomuto - Lomuto partitionig scheme for quicksort
 * @arr: array of integers
 * @size: size of array
 * @low: moving index starting from lowest index
 * @high moving index starting from highest index
 * Return: Nothing
 */
void lomuto(int *arr, size_t size, size_t low, size_t high)
{
	int pivot, tmp, tmp1;
	size_t i, j;

	if (low >= high)
		return;
	pivot = arr[high];
	j = low;
	for (i = 0; i < size; i++)
	{
		if (arr[i] <= pivot)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			print_array(arr, size);
			j++;
		}
	}
	tmp1 = arr[high];
	arr[high] = arr[j];
	arr[j] = tmp1;

	lomuto(arr, size, low, j - 1);
	lomuto(arr, size, j + 1, high);
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
	size_t low = 0;
	size_t high = size - 1;

	lomuto(array, size, low, high);
}
