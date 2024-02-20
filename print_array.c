#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}

/**
 * check_array_is_sorted - Function to check if an array
 * of integers is sorted in an ascending order.
 *
 * @array: Array to be checked
 * @size: Size of the array to be checked.
 *
 * Return: 0 if not sorted, 1 otherwise.
 */

int check_array_is_sorted(int *array, size_t size)
{
	int i;

	for (i = 1; i < (int) size; i++)
	{
		if (array[i] < array[i -1])
			return (0);
	}

	return (1);
}
