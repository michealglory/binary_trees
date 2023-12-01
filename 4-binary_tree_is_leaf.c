#include "binary_trees.h"

/**
 * binary_tree_is_leaf - determines if a node is a leaf of a binary tree.
 * @node: A pointer to the node to check.
 *
 * Return:  - 1 if it's a node of a binary tree, else returns 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
	{
		return (0);
	}

	return (1);
}
