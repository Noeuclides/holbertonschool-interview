#include "sandpiles.h"

/**
 * print_grid - print the sandpile
 *
 * @grid: sandpile
 *
 * Return: void
 **/
static void print_grid(int grid[3][3])
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

/**
 * sandpile_distribution - sandpile distribution
 *
 * @grid1: sandpile
 *
 * Return: void
 **/
void sandpile_distribution(int grid1[3][3])
{
	int i, j, zero_grid[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			zero_grid[i][j] = 0;
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] -= 4;

				if (i >= 1 && i <= 3)
					zero_grid[i - 1][j] += 1;
				if (j >= 1 && j <= 3)
					zero_grid[i][j - 1] += 1;
				if (i >= 0 && i < 2)
					zero_grid[i + 1][j] += 1;
				if (j >= 0 && j < 2)
					zero_grid[i][j + 1] += 1;
			}
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + zero_grid[i][j];
	}

}

/**
 * evaluate - evaluate if sandpile is stable
 *
 * @grid1: sandpile
 *
 * Return: one if it's not stable, 0 otherwise
 **/
int evaluate(int grid1[3][3])
{
	int i, j, flag = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
				flag = 1;
		}
	}
	return (flag);
}

/**
 * sandpiles_sum - computes the sum of two sandpiles
 *
 *@grid1: first sandpile
 *
 *@grid2: secondsandpile
 *
 * Return: void
 **/

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, flag = 1;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];
	}

	flag = evaluate(grid1);
	while (flag == 1)
	{
		print_grid(grid1);
		sandpile_distribution(grid1);
		flag = evaluate(grid1);
	}
}

