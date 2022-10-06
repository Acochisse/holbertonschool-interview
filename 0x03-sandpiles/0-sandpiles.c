#include "sandpiles.h"

/**
 * sandpiles_sum - adds two sandpiles by the rules of sandpiles
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 *
 * Return: Stable grid1 
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])

{
	grid_add(grid1, grid2);
	while (!eval(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid1);
	}
}
/**
 * eval - determines if a sandpile is stable or not
 * @TempG - the sandpile to be evaled
 * 
 * Return: 1 if the sandpile is good, 0 if not
 */
int eval(int grid1[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++) {
		for (y = 0; y < 3; y++)
		{
			if (grid1[x][y] > 3)
			{	
				return (0);
			}
		}
	}
	return (1);
}
				

/**
 * topple - topples a sandpile
 * @grid1: 3x3 grid
 *
 * Return: Stable grid1 
 */
void topple(int grid1[3][3])
{
	int x, y;
	int TempG[3][3];

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			TempG[x][y] = grid1[x][y];
		}
	}
	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (TempG[x][y] > 3)
			{
				grid1[x][y] -= 4;
				if (x - 1 >= 0)
					grid1[x - 1][y] += 1;
				if (x + 1 < 3)
					grid1[x + 1][y] += 1;
				if (y - 1 >= 0)
					grid1[x][y - 1] += 1;
				if (y + 1 < 3)
					grid1[x][y + 1] += 1;
			}
		}
	}
}

/**
 * print_grid - prints a 3x3 grid
 * @grid: 3x3 grid
 *
 * Return: void
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
 * grid_add - adds two sandpiles by the rules of sandpiles
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 *
 * Return: Stable grid1 
 */

void grid_add(int grid1[3][3], int grid2[3][3])

{
	int x, y;

	for (x = 0; x < 3; x++) {
		for (y = 0; y < 3; y++)
		{
			grid1[x][y] = grid1[x][y] + grid2[x][y];
		}
	}
}