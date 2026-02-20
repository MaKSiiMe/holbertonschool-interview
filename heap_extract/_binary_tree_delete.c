#include <stdlib.h>
#include "binary_trees.h"

/**
 * _binary_tree_delete - Deallocate a binary tree
 * @tree: Pointer to the root of the tree to delete
 */
void _binary_tree_delete(binary_tree_t *tree)
{
    if (!tree)
        return;

    _binary_tree_delete(tree->left);
    _binary_tree_delete(tree->right);
    free(tree);
}
