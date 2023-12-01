#include "binary_trees.h"
#include "limits.h"

/**
 * is_bst_helper - Helper function to check if a binary tree is a Binary
 * Search Tree (BST).
 *
 * @tree: Pointer to the root of the binary tree.
 * @lo: The minimum allowed value for a node in the BST (inclusive).
 * @hi: The maximum allowed value for a node in the BST (inclusive).
 *
 * Return: 1 if the tree is a BST within the given range, 0 otherwise.
 */
int is_bst_helper(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		return (is_bst_helper(tree->left, lo, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a Binary Search
 * Tree (BST).
 *
 * @tree: Pointer to the root of the binary tree.
 *
 * Return: 1 if the tree is a BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
