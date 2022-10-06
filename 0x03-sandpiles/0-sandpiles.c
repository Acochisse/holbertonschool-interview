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
	int i, j, unstable, TempG[3][3];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			TempG[i][j] = grid1[i][j] + grid2[i][j];


	while (!eval(TempG))
	{
		unstable = eval(TempG);
			if (unstable == 1)
			{
				printf("=\n");
				print_grid(TempG);
				topple(TempG);
			}
	}

	if (unstable == 0)
	{
		printf("=\n");
		print_grid(TempG);
	}
}

/**
 * eval - determines if a sandpile is stable or not
 * @TempG - the sandpile to be evaled
 * 
 * Return: 1 if the sandpile is good, 0 if not
 */
int eval(int TempG[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++) {
		for (y = 0; y < 3; y++)
		{
			if (TempG[x][y] > 3)
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
int topple(int TempG[3][3])
{
	int i, j, outgrid[3][3];
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			outgrid[i][j] = TempG[i][j];

			if (TempG[i][j] > 3)
			{
				outgrid[i][j] = TempG[i][j] - 4;
				if ((i + 1) < 3)
					outgrid[i + 1][j] += 1;
				if ((i - 1) <= 0)
					outgrid[i - 1][j] += 1;
				if ((j + 1) < 3)
					outgrid[i][j + 1] += 1;
				if ((j - 1) >= 0)
					outgrid[i][j - 1] += 1;
			}
		}
	} return (outgrid[3][3]);
}

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