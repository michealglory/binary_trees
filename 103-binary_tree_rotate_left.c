#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left rotation on a binary tree.
 *
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: Pointer to the new root node after the rotation, or NULL if
 * invalid.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *middle, *temp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	middle = tree->right;
	temp = middle->left;
	middle->left = tree;
	tree->right = temp;
	if (temp != NULL)
		temp->parent = tree;
	temp = tree->parent;
	tree->parent = middle;
	middle->parent = temp;
	if (temp != NULL)
	{
		if (temp->left == tree)
			temp->left = middle;
		else
			temp->right = middle;
	}

	return (middle);
}
