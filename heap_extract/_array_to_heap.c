#include <stdlib.h>
#include "binary_trees.h"

/* forward declaration of helper defined in 0-heap_extract.c */
heap_t *heapify_down(heap_t *node);

/**
 * _array_to_heap - Builds a max heap from an array of integers
 * @array: The integer array
 * @size: Number of elements
 *
 * Return: Pointer to the heap root, or NULL on failure
 */
heap_t *_array_to_heap(int *array, size_t size)
{
    heap_t **nodes;
    heap_t *root = NULL;
    size_t i;

    if (!array || size == 0)
        return (NULL);

    nodes = malloc(sizeof(heap_t *) * size);
    if (!nodes)
        return (NULL);

    /* create nodes */
    for (i = 0; i < size; i++)
    {
        nodes[i] = binary_tree_node(NULL, array[i]);
        if (!nodes[i])
        {
            /* cleanup on failure */
            while (i > 0)
                free(nodes[--i]);
            free(nodes);
            return (NULL);
        }
    }

    /* link children / parents to form a complete binary tree */
    for (i = 0; i < size; i++)
    {
        if ((2 * i) + 1 < size)
        {
            nodes[i]->left = nodes[(2 * i) + 1];
            nodes[(2 * i) + 1]->parent = nodes[i];
        }
        if ((2 * i) + 2 < size)
        {
            nodes[i]->right = nodes[(2 * i) + 2];
            nodes[(2 * i) + 2]->parent = nodes[i];
        }
    }

    /* heapify bottom-up to satisfy max-heap property */
    for (i = (size / 2); i > 0; i--)
    {
        heapify_down(nodes[i - 1]);
    }

    root = nodes[0];
    free(nodes);
    return (root);
}
