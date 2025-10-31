#include "menger.h"

/**
 * is_menger_pixel - Determines if a pixel should be drawn
 * @row: Row position
 * @col: Column position
 *
 * Return: 1 if pixel should be drawn, 0 otherwise
 */
int is_menger_pixel(int row, int col)
{
	while (row > 0 || col > 0)
	{
		/* Check if in the center of a 3x3 block */
		if (row % 3 == 1 && col % 3 == 1)
			return (0);

		row /= 3;
		col /= 3;
	}

	return (1);
}

/**
 * menger - Draws a 2D Menger Sponge
 * @level: Level of the Menger Sponge to draw
 */
void menger(int level)
{
	int size, row, col;

	if (level < 0)
		return;

	/* Calculate size: 3^level */
	size = (int)pow(3, level);

	/* Draw the sponge */
	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			if (is_menger_pixel(row, col))
				printf("#");
			else
				printf(" ");
		}
		printf("\n");
	}
}
