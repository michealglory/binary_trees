#include "binary_trees.h"

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
	binary_tree_t *ans_mom, *ans_pop;

	if (!first || !second)
	{
		return (NULL);
	}
	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	ans_mom = first->parent, ans_pop = second->parent;
	if (first == ans_pop || !ans_mom || (!ans_mom->parent && ans_pop))
		return (binary_trees_ancestor(first, ans_pop));
	else if (ans_mom == second || !ans_pop || (!ans_pop->parent && ans_mom))
		return (binary_trees_ancestor(ans_mom, second));
	return (binary_trees_ancestor(ans_mom, ans_pop));
}
