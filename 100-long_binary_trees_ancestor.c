#include "binary_trees.h"

size_t depth(const binary_tree_t *tree);

/**
 * binary_trees_ancestor - Find the lowest common ancestor of two nodes
 * in a binary tree.
 *
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if either
 * node is NULL.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t depth_first, depth_second;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);
	if (first->parent == second->parent)
		return ((binary_tree_t *)first->parent);
	if (first == second->parent)
		return ((binary_tree_t *)first);
	if (first->parent == second)
		return ((binary_tree_t *)second);

	for (depth_first = depth(first); depth_first > 1; depth_first--)
		first = first->parent;
	for (depth_second = depth(second); depth_second > 1; depth_second--)
		second = second->parent;

	if (first == second)
		return ((binary_tree_t *)first);
	if (first->parent == second->parent)
		return ((binary_tree_t *)first->parent);
	if (first == second->parent)
		return ((binary_tree_t *)first);
	if (first->parent == second)
		return ((binary_tree_t *)second);
	else
		return (NULL);
}

/**
 * depth - Calculate the depth of a node in a binary tree.
 *
 * @tree: Pointer to the node for which to determine the depth.
 *
 * Return: The depth of the node, or 0 if the node is NULL or the root.
 */
size_t depth(const binary_tree_t *tree)
{
	return ((tree->parent != NULL) ? 1 + depth(tree->parent) : 0);
}
