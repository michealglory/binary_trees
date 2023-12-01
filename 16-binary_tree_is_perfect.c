#include "binary_trees.h"

unsigned char is_leaf(const binary_tree_t *node);
size_t depth(const binary_tree_t *tree);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * is_leaf - Check if a given node is a leaf in a binary tree.
 *
 * @node: Pointer to the node to check.
 *
 * Return: 1 if the node is a leaf, 0 otherwise.
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
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
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * get_leaf - Find and return a leaf node in a binary tree.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Return: Pointer to a leaf node, or NULL if the tree is empty.
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect_recursive - Check if a binary tree is perfect (all leaf
 * nodes are at the same level).
 *
 * @tree: Pointer to the root node of the tree.
 * @leaf_depth: Depth of the leaf nodes in the tree.
 * @level: Current level of the tree during recursive traversal.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
		is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Check if a binary tree is perfect (all leaf
 * nodes are at the same level).
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}
