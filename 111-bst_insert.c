#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a Binary Search Tree (BST).
 *
 * @tree: Pointer to the root of the BST.
 * @value: Value to be inserted into the BST.
 *
 * Return: A pointer to the newly inserted node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current_node, *node_new;

	if (tree != NULL)
	{
		current_node = *tree;

		if (current_node == NULL)
		{
			node_new = binary_tree_node(current_node, value);
			if (node_new == NULL)
				return (NULL);
			return (*tree = node_new);
		}

		if (value < current_node->n) /* insert in left subtree */
		{
			if (current_node->left != NULL)
				return (bst_insert(&current_node->left, value));

			node_new = binary_tree_node(current_node, value);
			if (node_new == NULL)
				return (NULL);
			return (current_node->left = node_new);
		}
		if (value > current_node->n) /* insert in right subtree */
		{
			if (current_node->right != NULL)
				return (bst_insert(&current_node->right, value));

			node_new = binary_tree_node(current_node, value);
			if (node_new == NULL)
				return (NULL);
			return (current_node->right = node_new);
		}
	}
	return (NULL);
}
