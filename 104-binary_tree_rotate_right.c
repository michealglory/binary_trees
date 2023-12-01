#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right rotation on a binary tree.
 *
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: Pointer to the new root node after the rotation, or NULL if
 * invalid.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *fulcrum, *temp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	fulcrum = tree->left;
	temp = fulcrum->right;
	fulcrum->right = tree;
	tree->left = temp;
	if (temp != NULL)
		temp->parent = tree;
	temp = tree->parent;
	tree->parent = fulcrum;
	fulcrum->parent = temp;
	if (temp != NULL)
	{
		if (temp->left == tree)
			temp->left = fulcrum;
		else
			temp->right = fulcrum;
	}

	return (fulcrum);
}
