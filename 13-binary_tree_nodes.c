#include "binary_trees.h"

/**
 * binary_tree_nodes - Count the number of nodes with at least one child
 *                     in a binary tree.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Return: The number of nodes with at least one child, or 0 if the tree is
 * empty.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t num_nodes = 0;

	if (tree)
	{
		num_nodes += (tree->left || tree->right) ? 1 : 0;
		num_nodes += binary_tree_nodes(tree->left);
		num_nodes += binary_tree_nodes(tree->right);
	}
	return (num_nodes);
}
