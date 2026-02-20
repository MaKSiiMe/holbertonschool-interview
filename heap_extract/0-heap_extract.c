#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the tree, or 0 if tree is NULL
 */
size_t heap_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + heap_size(tree->left) + heap_size(tree->right));
}

/**
 * heap_to_array - Goes through a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @array: Pointer to store the array
 * @size: Size of the tree
 * @i: Index
 *
 * Return: No return
 */
void heap_to_array(binary_tree_t *tree, binary_tree_t **array, size_t size,
		   size_t i)
{
	if (!tree || i >= size)
		return;

	array[i] = tree;
	heap_to_array(tree->left, array, size, (2 * i) + 1);
	heap_to_array(tree->right, array, size, (2 * i) + 2);
}

/**
 * heapify_down - Restores the Max Heap property by sifting down
 * @node: Pointer to the node to heapify down from
 *
 * Return: Pointer to the final node (not used)
 */
heap_t *heapify_down(heap_t *node)
{
	heap_t *largest;
	int tmp;

	while (node)
	{
		largest = node;
		if (node->left && node->left->n > largest->n)
			largest = node->left;
		if (node->right && node->right->n > largest->n)
			largest = node->right;
		if (largest == node)
			break;
		tmp = node->n;
		node->n = largest->n;
		largest->n = tmp;
		node = largest;
	}

	return (node);
}

/**
 * pop_last_and_get_value - Remove the last level-order node and return its
 *                          stored value via out_val.
 * @root: Pointer to the heap root
 * @size: Number of nodes in the heap
 * @out_val: Pointer to store the last node's integer value
 *
 * Return: 1 on success, 0 on failure
 */
static int pop_last_and_get_value(const binary_tree_t *root, size_t size,
					 int *out_val)
{
	binary_tree_t **array;
	binary_tree_t *last;

	array = malloc(sizeof(binary_tree_t *) * size);
	if (!array)
		return (0);

	heap_to_array((binary_tree_t *)root, array, size, 0);
	last = array[size - 1];
	*out_val = last->n;
	if (last->parent)
	{
		if (last->parent->left == last)
			last->parent->left = NULL;
		else if (last->parent->right == last)
			last->parent->right = NULL;
	}
	free(last);
	free(array);
	return (1);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 *
 * Return: The value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	size_t size;
	int last_val;
	int ret;

	if (!root || !(*root))
		return (0);

	size = heap_size(*root);
	if (size == 0)
		return (0);

	if (size == 1)
	{
		ret = (*root)->n;
		free(*root);
		*root = NULL;
		return (ret);
	}

	if (!pop_last_and_get_value(*root, size, &last_val))
		return (0);

	/* Save root value and replace with last node's value */
	ret = (*root)->n;
	(*root)->n = last_val;

	/* Restore heap property */
	heapify_down(*root);

	return (ret);
}
