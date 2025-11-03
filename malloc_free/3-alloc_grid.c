#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - allocates a 2D array of ints and initializes all to 0
 * @width:  number of columns
 * @height: number of rows
 *
 * Return: pointer to the 2D array on success,
 *         or NULL if width/height <= 0 or on allocation failure.
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int i, j;

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = malloc(sizeof(int *) * height);
	if (grid == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		grid[i] = malloc(sizeof(int) * width);
		if (grid[i] == NULL)
		{
			/* free previously allocated rows then the grid itself */
			while (i > 0)
			{
				i--;
				free(grid[i]);
			}
			free(grid);
			return (NULL);
		}

		for (j = 0; j < width; j++)
			grid[i][j] = 0;
	}

	return (grid);
}
