#include "sort.h"

/**
 * bubble_sort - function to sort an array of integers
 * @array: Array of integers to be sorted
 * @size: Size of the array to be sorted
 * Return: Nothing.
 */

void bubble_sort(int *array, size_t size)
{
	int temp, i, j;


	for (i = 0; i < (int)size; i++)
	{
		for (j = 0; j < (int)size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
