#include "binary_trees.h"

bst_t *inorder_successor(bst_t *root);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);

/**
 * inorder_successor - Finds the inorder successor in a Binary Search
 * Tree (BST).
 *
 * @root: Pointer to the root of the BST.
 *
 * Return: A pointer to the inorder successor node, or NULL if not found.
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_delete - Deletes a node from a Binary Search Tree (BST).
 *
 * @root: Pointer to the root of the BST.
 * @node: Pointer to the node to be deleted.
 *
 * Return: A pointer to the root of the modified BST.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *node_parent = node->parent, *node_successor = NULL;

	/* No children or right-child only */
	if (node->left == NULL)
	{
		if (node_parent != NULL && node_parent->left == node)
			node_parent->left = node->right;
		else if (node_parent != NULL)
			node_parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = node_parent;
		free(node);
		return (node_parent == NULL ? node->right : root);
	}

	/* Left-child only */
	if (node->right == NULL)
	{
		if (node_parent != NULL && node_parent->left == node)
			node_parent->left = node->left;
		else if (node_parent != NULL)
			node_parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = node_parent;
		free(node);
		return (node_parent == NULL ? node->left : root);
	}

	/* Two children */
	node_successor = inorder_successor(node->right);
	node->n = node_successor->n;

	return (bst_delete(root, node_successor));
}

/**
 * bst_remove_recursive - Removes a node with a specific value from a
 * Binary Search
 * Tree (BST) recursively.
 *
 * @root: Pointer to the root of the BST.
 * @node: Pointer to the current node being considered.
 * @value: Value to be removed from the BST.
 *
 * Return: A pointer to the root of the modified BST after removal, or
 * NULL if the
 * value is not found.
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));
		return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - Removes a node with a specific value from a Binary
 * Search Tree (BST).
 *
 * @root: Pointer to the root of the BST.
 * @value: Value to be removed from the BST.
 *
 * Return: A pointer to the root of the modified BST after removal,
 * or NULL if the value is not found.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}
