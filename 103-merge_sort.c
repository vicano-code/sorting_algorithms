#include "sort.h"

/**
 * merge - sub func of the mergeSort array to sort and merge two arrays
 * @arr: the array of integers
 * @left: leftmost index of an array
 * @mid: mid index of an array
 * @right: rightmost index of an array
 * Return: Nothing
 */
void merge(int *arr, size_t left, size_t mid, size_t right)
{
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int leftArr[256];
	int rightArr[256];
	int *mergedArr;

	printf("Merging...\n");
	for (i = 0; i < n1; i++)
		leftArr[i] = arr[left + i];
	printf("[left]: ");
        print_array(leftArr, n1);
	for (j = 0; j < n2; j++)
		rightArr[j] = arr[mid + 1 + j];
	printf("[right]: ");
        print_array(rightArr, n2);

	i = 0, j = 0, k = left;

	mergedArr = malloc(n1 + n2);
	while (i < n1 && j < n2)
	{
		if (leftArr[i] <= rightArr[j])
		{
			mergedArr[k] = leftArr[i];
			arr[k] = leftArr[i];
			i++;
		}
		else
		{
			mergedArr[k] = rightArr[j];
			arr[k] = rightArr[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		mergedArr[k] = leftArr[i];
		arr[k] = leftArr[i];
		i++, k++;
	}
	while (j < n2)
	{
		mergedArr[k] = rightArr[j];
		arr[k] = rightArr[j];
		j++, k++;
	}
	printf("[Done]: ");
	print_array(mergedArr, n1 + n2);
	free(mergedArr);
}
/**
 * mergeSort - sub function of the merge_sort function
 * @arr: the array of integers
 * @left: leftmost index of an array
 * @right: rightmost index of an array
 * Return: Nothing
 */
void mergeSort(int *arr, size_t left, size_t right)
{
	size_t mid;

	if (left < right)
	{
		mid = left + (right - left) / 2;

		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		merge(arr, left, mid, right);
	}
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: array of integers
 * @size: size of array
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	size_t left, right;

	if (size < 2)
		return;

	left = 0;
	right = size - 1;

	mergeSort(array, left, right);
}
