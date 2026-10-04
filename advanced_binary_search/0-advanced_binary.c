#include "search_algos.h"

/**
 * advanced_binary - finds a value in an array using advanced binary search
 * @array: the array
 * @size: the size of the array
 * @value: the value to search for
 *
 * Return: the index if value find ; -1 otherwise
 */
int advanced_binary(int *array, size_t size, int value)
{
	int half = (int)size / 2;
	int left_index;
	int index = half;

	if (!array)
		return (-1);

	/* Compensate odd size */
	if ((int)size % 2 == 1)
		half++;

	if (value == array[index])
	{
		if ((int)size > 1)
		{
			print_array(array, size);
			left_index = advanced_binary(&array[0], (size_t)half, value);

			if (left_index >= 0)
				return (left_index);
		}

		return (index);
	}
	else if (value < array[index] && (int)size > 1)
	{
		print_array(array, size);
		index = advanced_binary(&array[0], (size_t)half, value);

		if (index >= 0)
			return (index);

		return (-1);
	}
	else if (value > array[index] && (int)size > 1)
	{
		print_array(array, size);
		index = advanced_binary(&array[half], size - (size_t)half, value);

		if (index >= 0)
			return (half + index);

		return (-1);
	}

	print_array(array, size);
	return (-1);
}

/**
 * print_array - prints a given array
 * @array: the array
 * @size: the size of the array
 */
void print_array(int *array, size_t size)
{
	int i = 0;

	printf("Searching in array: ");

	for (i = 0 ; i < (int)size ; i++)
	{
		printf("%d", array[i]);

		if (i + 1 != (int)size)
			printf(", ");
		else
			printf("\n");
	}
}
