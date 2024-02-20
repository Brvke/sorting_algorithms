#include "sort.h"

/**
 * shell_sort - Function to sort an array of integers
 * using the sell sort algorithm.
 * @array: The array to be sorted.
 * @size: Size of the array to be sorted.
 * Return: Nothing.
 */

void shell_sort(int *array, size_t size)
{
	int interval, i, j, temp;

	interval = 1;


	while (interval <= (int)(size / 3))
		interval = (interval * 3) + 1;

	while (interval > 0)
	{
		for (i = interval; i < (int)size; i++)
		{
			j = i;

			while (j > interval - 1 && array[j - interval] > array[j])
			{
				temp = array[j];
				array[j] = array[j - interval];
				array[j - interval] = temp;
				j -= interval;
			}
		}
		print_array(array, size);
		interval = (interval - 1) / 3;
	}
}
