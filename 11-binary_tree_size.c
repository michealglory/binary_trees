#include "binary_trees.h"

/**
 * binary_tree_size - Measure the size of a binary tree.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Return: The number of nodes in the tree, or 0 if the tree is empty.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t tree_size = 0;

	if (tree)
	{
		tree_size += 1;
		tree_size += binary_tree_size(tree->left);
		tree_size += binary_tree_size(tree->right);
	}
	return (tree_size);
}
