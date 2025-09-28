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
void heap_to_array(binary_tree_t *tree, binary_tree_t **array, size_t size, size_t i)
{
	if (!tree || i >= size)
		return;

	array[i] = tree;
	heap_to_array(tree->left, array, size, (2 * i) + 1);
	heap_to_array(tree->right, array, size, (2 * i) + 2);
}

/**
 * heapify_up - Heapifies up the tree
 * @new_node: Pointer to the new node
 *
 * Return: Pointer to the new node
 */
heap_t *heapify_up(heap_t *new_node)
{
	heap_t *node = new_node;
	int tmp;

	while (node && node->parent && (node->n > node->parent->n))
	{
		tmp = node->n;
		node->n = node->parent->n;
		node->parent->n = tmp;
		node = node->parent;
	}

	return (new_node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	binary_tree_t **array, *new, *parent;
	size_t size;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));

	size = heap_size(*root);
	array = malloc(sizeof(binary_tree_t *) * size);
	if (!array)
		return (NULL);

	heap_to_array(*root, array, size, 0);

	parent = array[(size - 1) / 2];
	new = binary_tree_node(parent, value);
	if (!new)
	{
		free(array);
		return (NULL);
	}

	if (!(parent->left))
		parent->left = new;
	else
		parent->right = new;

	free(array);
	return (heapify_up(new));
}
