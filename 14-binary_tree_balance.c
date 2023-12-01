#include "binary_trees.h"

/**
 * binary_tree_balance - Measure the balance factor of a binary tree.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Return: The balance factor (height difference between left and right
 * subtrees),
 *         or 0 if the tree is empty.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 * binary_tree_height - Measure the height of a binary tree.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Return: The height of the tree, or 0 if the tree is empty.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left = 0, right = 0;

		left = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		right = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((left > right) ? left : right);
	}
	return (0);
}
