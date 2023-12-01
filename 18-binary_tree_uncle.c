#include "binary_trees.h"

/**
 * binary_tree_uncle - Find the uncle of a given node in a binary tree.
 *
 * @node: Pointer to the node for which to find the uncle.
 *
 * Return: Pointer to the uncle node, or NULL if the node is NULL,
 *         has no parent, or the parent has no grandparent.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL ||
	    node->parent == NULL ||
	    node->parent->parent == NULL)
		return (NULL);
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	return (node->parent->parent->left);
}
