#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverse a binary tree using post-order traversal
 *                         and apply a function to each node's value.
 *
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to the function to apply to each node's value.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
