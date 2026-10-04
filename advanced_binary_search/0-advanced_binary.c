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
	size_t pivot;
	int index;

	if (!array || size == 0)
		return (-1);

	print_array(array, size);

	if (size == 1)
	{
		if (array[0] == value)
			return (0);

		return (-1);
	}

	pivot = (size - 1) / 2;

	/* Right Half Case */
	if (value > array[pivot])
	{
		index = advanced_binary(array + pivot + 1, size - pivot - 1, value);

		if (index < 0)
			return (-1);

		return (index + (int)pivot + 1);
	}

	/* Left Half Case */
	if (value == array[pivot] && (pivot == 0 || value != array[pivot - 1]))
		return ((int)pivot);

	return (advanced_binary(array, pivot + 1, value));
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
