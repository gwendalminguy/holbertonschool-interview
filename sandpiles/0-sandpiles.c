#include "sandpiles.h"

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: first 3x3 grid
 * @grid2: second 3x3 grid
 *
 * Return: 0
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i = 0;
	int j = 0;

	/* Summing both grids into grid1 */
	for (i = 0 ; i < 3 ; i++)
	{
		for (j = 0 ; j < 3 ; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	/* Computing new sandpiles by iteration until stable */
	while (!is_stable(grid1))
	{
		print_sandpiles(grid1);
		update_sandpiles(grid1);
	}
}

/**
 * is_stable - determines if a grid of sandpiles is stable
 * @grid: 3x3 grid
 *
 * Return: true if stable ; false otherwise
 */
bool is_stable(int grid[3][3])
{
	int i = 0;
	int j = 0;

	for (i = 0 ; i < 3 ; i++)
	{
		for (j = 0 ; j < 3 ; j++)
		{
			if (grid[i][j] > 3)
				return (false);
		}
	}

	return (true);
}

/**
 * update_sandpiles - update a grid of sandpiles to its new state
 * @grid1: 3x3 grid
 *
 * Return: 0
 */
void update_sandpiles(int grid1[3][3])
{
	int i = 0;
	int j = 0;
	int grid2[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	/* Transferring unstable piles to a temporary grid */
	for (i = 0 ; i < 3 ; i++)
	{
		for (j = 0 ; j < 3 ; j++)
		{
			while (grid1[i][j] > 3)
			{
				grid1[i][j] -= 4;
				grid2[i][j] += 4;
			}
		}
	}

	/* Spilling temporary grid back into the right piles */
	for (i = 0 ; i < 3 ; i++)
	{
		for (j = 0 ; j < 3 ; j++)
		{
			while (grid2[i][j] > 3)
			{
				grid2[i][j] -= 4;

				if (i >= 1)
					grid1[i - 1][j] += 1;
				if (j >= 1)
					grid1[i][j - 1] += 1;
				if (i <= 1)
					grid1[i + 1][j] += 1;
				if (j <= 1)
					grid1[i][j + 1] += 1;
			}
		}
	}
}

/**
 * print_sandpiles - print a grid of sandpiles
 * @grid: 3x3 grid
 *
 */
void print_sandpiles(int grid[3][3])
{
	int i, j;

	printf("=\n");

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
