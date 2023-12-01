#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a new_node node as the right child of
 * a given node in a binary tree.
 *
 * @parent: Pointer to the parent node where the new_node node will be
 * inserted as the right child.
 * @value: Value to be stored in the new_node node.
 *
 * Return: Pointer to the newly created node, or NULL on failure or if the
 * parent is NULL.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
	{
		return (NULL);
	}

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
	{
		return (NULL);
	}

	if (parent->right != NULL)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}
	parent->right = new_node;

	return (new_node);
}
