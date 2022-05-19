#include "sandpiles.h"

/**
 * is_stable - checks if a matrix is already stable
 *
 * @matrix: Matrix to compute
 * Return: 1 if is stable, otherwise 0
 */
int is_stable(int matrix[3][3])
{

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (matrix[i][j] > 3)
				return (0);
	return (1);
}

/**
 * setting_zeros - Set a 3x3 matrix with all zeros
 *
 * @matrix: Matrix to compute
 * Return: Nothing
 */
void setting_zeros(int matrix[3][3])
{

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			matrix[i][j] = 0;
}

/**
 * duplicate - Duplicate a 3x3 matrix into another
 * @objective: objective matrix
 * @origin: origin matrix
 * Return: Nothing
 */
void duplicate(int objective[3][3], int origin[3][3])
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			objective[i][j] = origin[i][j];
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

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
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: matrix1
 * @grid2: matrix2
 * Return: Nothing
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	(void)grid1;
	(void)grid2;

	while (!is_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		setting_zeros(grid2);
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (grid1[i][j] <= 3)
					grid2[i][j] = grid1[i][j];
				else
				{
					if (i - 1 >= 0)
						grid2[i - 1][j] += 1;
					if (j - 1 >= 0)
						grid2[i][j - 1] += 1;
					if (i + 1 <= 2)
						grid2[i + 1][j] += 1;
					if (j + 1 <= 2)
						grid2[i][j + 1] += 1;
				}
		duplicate(grid1, grid2);
	}
}
