#include "binary_trees.h"

/**
 * binary_tree_preorder - Traverse a binary tree using pre-order traversal
 *                        and apply a function to each node's value.
 *
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to the function to apply to each node's value.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
