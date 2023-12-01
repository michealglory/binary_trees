#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree (BST).
 *
 * @tree: Pointer to the root of the BST.
 * @value: Value to search for in the BST.
 *
 * Return: A pointer to the node containing the value, or NULL if not found.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
