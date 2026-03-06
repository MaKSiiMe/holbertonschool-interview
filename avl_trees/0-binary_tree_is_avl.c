#include "binary_trees.h"
#include <limits.h>

/**
 * _bst_check - verify that a tree is a valid BST
 * @tree: pointer to the root node
 * @min: minimum allowed value (exclusive)
 * @max: maximum allowed value (exclusive)
 *
 * Return: 1 if tree respects BST properties, 0 otherwise
 */
static int _bst_check(const binary_tree_t *tree, long min, long max)
{
	if (tree == NULL)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	return (_bst_check(tree->left, min, tree->n) &&
			_bst_check(tree->right, tree->n, max));
}

/**
 * _height_balanced - compute height of tree and ensure balance
 * @tree: pointer to current node
 *
 * Return: height in nodes (0 for NULL) or -1 if unbalanced
 */
static int _height_balanced(const binary_tree_t *tree)
{
	int lh, rh;

	if (tree == NULL)
		return (0);

	lh = _height_balanced(tree->left);
	if (lh == -1)
		return (-1);
	rh = _height_balanced(tree->right);
	if (rh == -1)
		return (-1);

	if (lh - rh > 1 || rh - lh > 1)
		return (-1);

	return (1 + (lh > rh ? lh : rh));
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL tree
 * @tree: pointer to root node of the tree to check
 *
 * Return: 1 if tree is valid AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (!_bst_check(tree, LONG_MIN, LONG_MAX))
		return (0);

	if (_height_balanced(tree) == -1)
		return (0);

	return (1);
}
