#include "sort.h"
#include <sys/types.h>

/**
 * swap - Échange deux entiers dans un tableau
 * @a: pointeur vers le premier entier
 * @b: pointeur vers le second entier
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * sift_down - Maintient la propriété de tas max à partir d'un index donné
 * @array: tableau d'entiers
 * @size: taille totale du tableau
 * @start: index du noeud à "sift down"
 * @end: index du dernier élément du tas
 */
void sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t root = start, child, swap_idx;

	while ((child = 2 * root + 1) <= end)
	{
		swap_idx = root;
		if (array[swap_idx] < array[child])
			swap_idx = child;
		if (child + 1 <= end && array[swap_idx] < array[child + 1])
			swap_idx = child + 1;
		if (swap_idx == root)
			return;
		swap(&array[root], &array[swap_idx]);
		print_array(array, size);
		root = swap_idx;
	}
}

/**
 * heap_sort - Trie un tableau d'entiers en ordre croissant avec Heap sort
 * @array: tableau d'entiers
 * @size: taille du tableau
 */
void heap_sort(int *array, size_t size)
{
	ssize_t i;


	if (!array || size < 2)
		return;

	/* Construction du tas max */
	i = (ssize_t)(size / 2) - 1;
	while (i >= 0)
	{
		sift_down(array, size, (size_t)i, size - 1);
		i--;
	}

	/* Extraction du max et tri */
	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, size, 0, i - 1);
	}
}
