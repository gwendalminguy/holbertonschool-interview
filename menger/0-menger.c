#include "menger.h"

/**
 * menger - draws atwo-dimensional Menger Sponge
 * @level: level of the Menger Sponge
 */
void menger(int level)
{
	int i, j;
	int raised = pow(3, level);

	for (i = 0 ; i < raised ; i++)
	{
		for (j = 0 ; j < raised ; j++)
		{
			/* Check if the cell should be left blank */
			if (is_blank(i, j, level))
				printf(" ");
			else
				printf("#");
		}

		printf("\n");
	}
}

/**
 * is_blank - determines if the cell should be left blank
 * @i: X axis coordinate
 * @j: Y axis coordinate
 * @level: level of the Menger Sponge
 *
 * Return: true if it should be left blank ; false otherwise
 */
bool is_blank(int i, int j, int level)
{
	int l, modulo, lower, upper;

	/* Check each level */
	for (l = 0 ; l < level ; l++)
	{
		modulo = (int)pow(3, l + 1);
		lower = pow(3, l + 1) / 3;
		upper = lower * 2 - 1;

		/* Check if cell is in the center of its level */
		if (((i % modulo) >= lower && (i % modulo) <= upper)
			&& ((j % modulo) >= lower && (j % modulo) <= upper))
			return (true);
	}

	return (false);
}
