#include "binary_trees.h"
#include "limits.h"

size_t height(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * height - Measures the height of a binary tree.
 *
 * @tree: Pointer to the root of the binary tree.
 *
 * Return: The height of the binary tree, or 0 if the tree is empty.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left = 0, right = 0;

		left = tree->left ? 1 + height(tree->left) : 1;
		right = tree->right ? 1 + height(tree->right) : 1;
		return ((left > right) ? left : right);
	}
	return (0);
}

/**
 * is_avl_helper - Helper function to check if a binary tree is an AVL tree.
 *
 * @tree: Pointer to the root of the binary tree.
 * @lo: The minimum allowed value for a node in the AVL tree (inclusive).
 * @hi: The maximum allowed value for a node in the AVL tree (inclusive).
 *
 * Return: 1 if the tree is an AVL tree within the given range, 0 otherwise.
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t lefthgt, righthgt, diff;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		lefthgt = height(tree->left);
		righthgt = height(tree->right);
		diff = lefthgt > righthgt ? lefthgt - righthgt : righthgt - lefthgt;
		if (diff > 1)
			return (0);
		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is an AVL tree.
 *
 * @tree: Pointer to the root of the binary tree.
 *
 * Return: 1 if the tree is an AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
