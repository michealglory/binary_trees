#include "binary_trees.h"

/**
 * binary_trees_ancestor - Find the lowest common ancestor of two nodes in a
 * binary tree.
 *
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if either node
 * is NULL.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *ancestor, *dad;

	if (!first || !second)
	{
		return (NULL);
	}
	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	ancestor = first->parent, dad = second->parent;
	if (first == dad || !ancestor || (!ancestor->parent && dad))
	{
		return (binary_trees_ancestor(first, dad));
	}
	else if (ancestor == second || !dad || (!dad->parent && ancestor))
	{
		return (binary_trees_ancestor(ancestor, second));
	}
	return (binary_trees_ancestor(ancestor, dad));
}
