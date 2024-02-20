#include "sort.h"

/**
 * counting_sort - Function to sort an array of integers
 * using the counting sort algoritm
 * @array: array to be sorted.
 * @size: Size of the array to be sorted.
 * Return: Nothing.
 */

void counting_sort(int *array, size_t size)
{
	int *res_array, array_max, i, j, now_at;

	array_max = get_array_max(array, size);
	res_array = malloc(sizeof(int) * (array_max + 1));

	if (!res_array)
		return;

	for (i = 0; i <= array_max; i++)
	{
		res_array[i] = 0;
	}

	for (i = 0; i < (int)size; i++)
	{
		for (now_at = array[i]; now_at <= array_max; now_at++)
			res_array[now_at]++;
	}

	j = 0;

	for (i = 1; i <= array_max; i++)
	{
		if (res_array[i] != res_array[i - 1])
		{
			now_at = res_array[i] - res_array[i - 1];
			while (now_at && res_array[i] != res_array[i - 1])
			{
				array[j] = i;
				now_at--;
				j++;
			}
		}
	}

	print_array(res_array, array_max + 1);
	free(res_array);
}

/**
 * get_array_max - Function to get the maximum integer in an
 * array of integers.
 * @array: array to be checked.
 * @size: size fo the array to be checked.
 * Return: the maximum number in the array.
 */

int get_array_max(int *array, size_t size)
{
	int max, i;

	max = array[0];

	for (i = 1; i < (int)size; i++)
	{
		if (max < array[i])
			max = array[i];
	}

	return (max);
}
