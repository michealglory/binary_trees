#include "binary_trees.h"

/**
 * struct node_s - singly linked list
 * @node: const binary tree node
 * @next: points to the next node
 */
typedef struct node_s
{
	const binary_tree_t *node;
	struct node_s *next;
} ll;

ll *append(ll *head, const binary_tree_t *btnode);
void free_list(ll *head);
ll *get_children(ll *head, const binary_tree_t *parent);
void levels_rec(ll *head, void (*func)(int));

/**
 * binary_tree_levelorder - Traverse a binary tree using level-order traversal
 *                          and apply a function to each node's value.
 *
 * @tree: Pointer to the root node of the tree.
 * @func: Pointer to the function to apply to each node's value.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	ll *child = NULL;

	func(tree->n);
	child = get_children(child, tree);
	levels_rec(child, func);

	free_list(child);
}

/**
 * levels_rec - Recursively traverse the levels of a binary tree and apply
 * a function.
 *
 * @head: Pointer to the head of the linked list representing the current
 * level.
 * @func: Pointer to the function to apply to each node's value.
 */
void levels_rec(ll *head, void (*func)(int))
{
	ll *child = NULL, *pos = NULL;

	if (!head)
		return;
	for (pos = head; pos != NULL; pos = pos->next)
	{
		func(pos->node->n);
		child = get_children(child, pos->node);
	}
	levels_rec(child, func);
	free_list(child);
}

/**
 * get_children - Get the children of a given parent node and append them
 * to a linked list.
 *
 * @head: Pointer to the head of the linked list.
 * @parent: Pointer to the parent node.
 *
 * Return: Pointer to the updated head of the linked list.
 */
ll *get_children(ll *head, const binary_tree_t *parent)
{
	if (parent->left)
		head = append(head, parent->left);
	if (parent->right)
		head = append(head, parent->right);
	return (head);
}

/**
 * append - Append a new node with a binary tree node to the end of
 * a linked list.
 *
 * @head: Pointer to the head of the linked list.
 * @btnode: Pointer to the binary tree node to append.
 *
 * Return: Pointer to the updated head of the linked list.
 */
ll *append(ll *head, const binary_tree_t *btnode)
{
	ll *new_node = NULL, *node_last = NULL;

	new_node = malloc(sizeof(*new_node));
	if (new_node)
	{
		new_node->node = btnode;
		new_node->next = NULL;
		if (!head)
			head = new_node;
		else
		{
			node_last = head;
			while (node_last->next)
				node_last = node_last->next;
			node_last->next = new_node;
		}
	}
	return (head);
}

/**
 * free_list - Free a linked list.
 *
 * @head: Pointer to the head of the linked list.
 */
void free_list(ll *head)
{
	ll *node_ptr = NULL;

	while (head)
	{
		node_ptr = head->next;
		free(head);
		head = node_ptr;
	}
}
