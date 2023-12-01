#include "binary_trees.h"

/**
 * binary_tree_node - Creates a new_node node for a binary tree.
 *
 * @node_parent: Pointer to the parent node. Set to NULL if the new_node node is
 * the root.
 * @node_value: Integer node to be assigned to the new_node node.
 *
 * Return: Pointer to the newly created node, or NULL on failure.
 */
binary_tree_t *binary_tree_node(binary_tree_t *node_parent, int node_value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = node_value;
	new_node->parent = node_parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
