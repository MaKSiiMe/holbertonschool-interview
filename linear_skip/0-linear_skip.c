#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list to search in
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current, *prev;

	if (list == NULL)
		return (NULL);

	current = list;
	prev = NULL;

	/* Use express lane to find the range */
	while (current->express != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       current->express->index, current->express->n);

		if (current->express->n >= value)
			break;

		prev = current;
		current = current->express;
	}

	/* Handle case when we reach end of express lane */
	if (current->express == NULL)
	{
		prev = current;
		while (current->next != NULL)
			current = current->next;
	}
	else
	{
		prev = current;
		current = current->express;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
	       prev->index, current->index);

	/* Linear search in the range */
	while (prev != NULL && prev->index <= current->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       prev->index, prev->n);

		if (prev->n == value)
			return (prev);

		prev = prev->next;
	}

	return (NULL);
}
