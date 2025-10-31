#include "slide_line.h"

/**
 * slide_left - Slides and merges an array to the left
 * @line: Pointer to array of integers
 * @size: Number of elements in the array
 */
void slide_left(int *line, size_t size)
{
	size_t i, j, k;

	/* Slide all non-zero values to the left */
	for (i = 0, j = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			line[j] = line[i];
			if (i != j)
				line[i] = 0;
			j++;
		}
	}

	/* Merge adjacent identical values */
	for (i = 0; i < size - 1; i++)
	{
		if (line[i] != 0 && line[i] == line[i + 1])
		{
			line[i] *= 2;
			line[i + 1] = 0;
		}
	}

	/* Slide again to remove zeros created by merging */
	for (i = 0, j = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			line[j] = line[i];
			if (i != j)
				line[i] = 0;
			j++;
		}
	}

	/* Fill remaining positions with zeros */
	for (k = j; k < size; k++)
		line[k] = 0;
}

/**
 * slide_right - Slides and merges an array to the right
 * @line: Pointer to array of integers
 * @size: Number of elements in the array
 */
void slide_right(int *line, size_t size)
{
	size_t i, j, k;
	int temp;

	/* Slide all non-zero values to the right */
	for (i = size, j = size; i > 0; i--)
	{
		if (line[i - 1] != 0)
		{
			j--;
			temp = line[i - 1];
			line[i - 1] = 0;
			line[j] = temp;
		}
	}

	/* Merge adjacent identical values from right to left */
	for (i = size - 1; i > 0; i--)
	{
		if (line[i] != 0 && line[i] == line[i - 1])
		{
			line[i] *= 2;
			line[i - 1] = 0;
		}
	}

	/* Slide again to remove zeros created by merging */
	for (i = size, j = size; i > 0; i--)
	{
		if (line[i - 1] != 0)
		{
			j--;
			temp = line[i - 1];
			line[i - 1] = 0;
			line[j] = temp;
		}
	}

	/* Fill remaining positions with zeros */
	for (k = 0; k < j; k++)
		line[k] = 0;
}

/**
 * slide_line - Slides and merges an array of integers
 * @line: Pointer to array of integers
 * @size: Number of elements in the array
 * @direction: Direction to slide (SLIDE_LEFT or SLIDE_RIGHT)
 *
 * Return: 1 upon success, 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);

	if (direction == SLIDE_LEFT)
		slide_left(line, size);
	else
		slide_right(line, size);

	return (1);
}
