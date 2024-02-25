#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending
 * order using the Counting sort algorithm
 * @array: array of integers
 * @size: size of array
 * Return: Nothing
 */
void counting_sort(int *array, size_t size)
{
	int *countArray, *outArray;
	size_t i;
	int max;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	countArray = (int *)malloc(sizeof(int) * (max + 1));
	if (countArray == NULL)
		return;
	for (i = 0; (int)i < max; i++) /*initialize with zeros*/
		countArray[i] = 0;
	for (i = 0; i < size; i++)
		countArray[i] += 1;
	countArray[array[i]] += 1;
	for (i = 1; (int)i < max; i++)
		countArray[i] += countArray[i - 1];
	outArray = (int *)malloc(sizeof(int) * size);
	if (outArray == NULL)
	{
		free(countArray);
		return;
	}
	for (i = size - 1; (int)i >= 0; i--)
	{
		outArray[countArray[array[i]] - 1] = array[i];
		countArray[array[i]]--;
	}
	print_array(array, size);
}
