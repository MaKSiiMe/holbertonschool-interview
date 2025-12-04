#include "binary_trees.h"

/**
 * create_node - Creates a binary tree node
 * @parent: Pointer to the parent node
 * @value: Value to put in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
avl_t *create_node(avl_t *parent, int value)
{
	avl_t *new_node;

	new_node = malloc(sizeof(avl_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

/**
 * build_avl - Recursively builds an AVL tree from a sorted array
 * @array: Pointer to the array
 * @parent: Pointer to the parent node
 * @start: Start index of the subarray
 * @end: End index of the subarray
 *
 * Return: Pointer to the root node of the subtree, or NULL on failure
 */
avl_t *build_avl(int *array, avl_t *parent, size_t start, size_t end)
{
	size_t mid;
	avl_t *node;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	node = create_node(parent, array[mid]);
	if (node == NULL)
		return (NULL);

	if (mid > start)
		node->left = build_avl(array, node, start, mid - 1);
	if (mid < end)
		node->right = build_avl(array, node, mid + 1, end);

	return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (build_avl(array, NULL, 0, size - 1));
}
