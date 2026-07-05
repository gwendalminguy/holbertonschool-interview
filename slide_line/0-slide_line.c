#include "slide_line.h"

/**
 * slide_line - slides a line of numbers
 *
 * @line: array of integers
 * @size: size of array
 * @direction: direction to slide
 *
 * Return: 1 on success ; 0 otherwise
 */
int slide_line(int *line, size_t size, int direction)
{
	int i = 0, length = (int)size;
	int shift = 0, last = 0;

	if (direction != -1 && direction != 1)
		return (0);

	if (direction > 0)
		reverse(line, length);

	for (i = 0; i < length ; i++)
	{
		/* Counting shift */
		if (line[i] == 0)
			shift++;
		else
		{
			/* Merging numbers */
			if (line[i] == last)
			{
				shift++;
				last = merge(line, i - shift, i);
			}

			/* Moving numbers */
			else if (shift > 0)
				last = move(line, i - shift, i);

			else
				last = line[i];
		}
	}

	if (direction > 0)
		reverse(line, length);

	return (1);
}

/**
 * reverse - reverses an array of integers
 *
 * @line: array of integers
 * @size: size of the array
 */
void reverse(int *line, int size)
{
	int i = 0;
	int temp = 0;

	for (i = 0 ; i < size / 2 ; i++)
	{
		temp = line[size - i - 1];
		line[size - i - 1] = line[i];
		line[i] = temp;
	}
}

/**
 * merge - merges two numbers
 *
 * @line: array of integers
 * @i: final position
 * @j: initial position
 *
 * Return: always 0
 */
int merge(int *line, int i, int j)
{
	int result;

	result = line[i] * 2;

	line[i] = result;
	line[j] = 0;

	return (0);
}

/**
 * move - moves a number
 *
 * @line: array of integers
 * @i: final position
 * @j: initial position
 *
 * Returns: moved number
 */
int move(int *line, int i, int j)
{
	int result;

	result = line[j];

	line[i] = line[j];
	line[j] = 0;

	return (result);
}
