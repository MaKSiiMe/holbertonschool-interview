#include "../search.h"

/**
 * create_skiplist - Creates a skip list from an array of integers
 * @array: Pointer to the array
 * @size: Size of the array
 *
 * Return: Pointer to the head of the skip list
 */
skiplist_t *create_skiplist(int *array, size_t size)
{
	skiplist_t *head = NULL, *tail = NULL, *express = NULL, *node;
	size_t i;
	size_t step;

	if (array == NULL || size == 0)
		return (NULL);

	step = (size_t)sqrt((double)size);

	for (i = 0; i < size; i++)
	{
		node = malloc(sizeof(skiplist_t));
		if (node == NULL)
			return (NULL);

		node->n = array[i];
		node->index = i;
		node->next = NULL;
		node->express = NULL;

		if (head == NULL)
		{
			head = node;
			tail = node;
			express = node;
		}
		else
		{
			tail->next = node;
			tail = node;
		}

		if (i > 0 && i % step == 0)
		{
			express->express = node;
			express = node;
		}
	}

	return (head);
}

/**
 * print_skiplist - Prints a skip list
 * @list: Pointer to the head of the skip list
 */
void print_skiplist(const skiplist_t *list)
{
	const skiplist_t *node;

	printf("List :\n");
	node = list;
	while (node != NULL)
	{
		printf("Index[%lu] = [%d]\n", node->index, node->n);
		node = node->next;
	}

	printf("\nExpress lane :\n");
	node = list;
	while (node != NULL)
	{
		printf("Index[%lu] = [%d]\n", node->index, node->n);
		node = node->express;
	}
	printf("\n");
}

/**
 * free_skiplist - Frees a skip list
 * @list: Pointer to the head of the skip list
 */
void free_skiplist(skiplist_t *list)
{
	skiplist_t *tmp;

	while (list != NULL)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}
