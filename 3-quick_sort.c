#include "sort.h"

/**
 * quick_sort - Function to sort an array of integers
 * using the quick sort algorithm.
 * @array: array of integers to be sorted.
 * @size: size fo array to be sorted.
 * Return: Nothing.
 */

void quick_sort(int *array, size_t size)
{
	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - Function to recursively sort sub arrays
 * using the quick sort algorithm.
 * @array: array to be sorted.
 * @low: lower index of array to be sorted (for sub arrays)
 * @high: higher index of array to be sorted (for sub arrays)
 * @size: size of array to be sorted.
 * Return: Nothing.
 */

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quick_sort_recursive(array, pivot + 1, high, size);
		quick_sort_recursive(array, low, pivot - 1, size);
	}
}

/**
 * partition - Function to partition a given array to sub arrays
 * of higher and lower value.
 * @array: array to be sorted.
 * @low: lower index of array to be sorted (for sub arrays)
 * @high: higher index of array to be sorted (for sub arrays)
 * @size: size of array to be sorted.
 * Return: the index of the pivot used to separate the lower and
 * higher values.
 */

int  partition(int *array, int low, int high, size_t size)
{
	int temp, i, j;

	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] < array[high])
		{
			if (i < j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] > array[high])
	{
		temp = array[i];
		array[i] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i);
}
