#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * get_max - return maximum value from array
 * @array: input array
 * @size: number of elements
 *
 * Return: maximum integer found
 */
static int get_max(int *array, size_t size)
{
	int max = 0;
	size_t i;

	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * counting_sort - sort array according to digit represented by exp
 * @array: input/output array
 * @size: length
 * @exp: current exponent (1, 10, 100...)
 */
static void counting_sort(int *array, size_t size, int exp)
{
	int *output;
	int count[10] = {0};
	size_t i;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	/* count occurrences of digits */
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;
	/* accumulate counts */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	/* build output array backwards for stability */
	for (i = size; i > 0; i--)
	{
		int idx = (array[i - 1] / exp) % 10;
		
		output[--count[idx]] = array[i - 1];
	}
	/* copy back to original */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - sorts an array of integers using LSD radix sort; prints
 *	array at each digit pass
 * @array: pointer to first element
 * @size: number of elements
 */
void radix_sort(int *array, size_t size)
{
	int max;
	int exp;

	if (!array || size < 2)
		return;

	max = get_max(array, size);
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort(array, size, exp);
		print_array(array, size);
	}
}
