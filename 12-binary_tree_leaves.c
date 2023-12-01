#include "binary_trees.h"

/**
 * binary_tree_leaves - Count the number of leaves in a binary tree.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Return: The number of leaf nodes in the tree, or 0 if the tree is empty.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t num_leaves = 0;

	if (tree)
	{
		num_leaves += (!tree->left && !tree->right) ? 1 : 0;
		num_leaves += binary_tree_leaves(tree->left);
		num_leaves += binary_tree_leaves(tree->right);
	}
	return (num_leaves);
}
