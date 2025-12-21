#include <stdio.h>
#include <stddef.h>

/**
 * print_subarray - Affiche le sous-tableau actuellement recherché
 * @array: tableau d'entiers
 * @left: index de début
 * @right: index de fin
 */
void print_subarray(int *array, size_t left, size_t right)
{
	size_t i;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		if (i > left)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * recursive_search - Recherche binaire récursive pour la première occurrence
 * @array: tableau d'entiers
 * @left: index de début
 * @right: index de fin
 * @value: valeur recherchée
 * Return: index de la première occurrence ou -1
 */
int recursive_search(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	if (left > right)
		return (-1);

	print_subarray(array, left, right);

	mid = left + (right - left) / 2;

	if (array[mid] == value)
	{
		if (mid == left || array[mid - 1] != value)
			return ((int)mid);
		return (recursive_search(array, left, mid, value));
	}
	else if (array[mid] > value)
	{
		if (mid == 0)
			return (-1);
		return (recursive_search(array, left, mid - 1, value));
	}
	else
	{
		return (recursive_search(array, mid + 1, right, value));
	}
}

/**
 * advanced_binary - Recherche la première occurrence d'une valeur dans un tableau trié
 * @array: tableau d'entiers trié
 * @size: taille du tableau
 * @value: valeur recherchée
 * Return: index de la première occurrence ou -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1);
	return (recursive_search(array, 0, size - 1, value));
}
