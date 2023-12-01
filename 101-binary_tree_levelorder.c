#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int));
void pop(levelorder_queue_t **head);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/**
 * create_node - Create a new node for the level-order traversal queue.
 *
 * @node: Pointer to the binary tree node.
 *
 * Return: Pointer to the newly created node, or NULL if allocation fails.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *node_new;

	node_new = malloc(sizeof(levelorder_queue_t));
	if (node_new == NULL)
		return (NULL);

	node_new->node = node;
	node_new->next = NULL;

	return (node_new);
}

/**
 * free_queue - Free a level-order traversal queue.
 *
 * @head: Pointer to the head of the queue.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * pint_push - Push a binary tree node's children into the level-order
 * traversal queue.
 *
 * @node: Pointer to the binary tree node.
 * @head: Pointer to the head of the queue.
 * @tail: Pointer to the tail of the queue.
 * @func: Pointer to the function to apply to each node's value.
 */
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *node_new;

	func(node->n);
	if (node->left != NULL)
	{
		node_new = create_node(node->left);
		if (node_new == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = node_new;
		*tail = node_new;
	}
	if (node->right != NULL)
	{
		node_new = create_node(node->right);
		if (node_new == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = node_new;
		*tail = node_new;
	}
}

/**
 * pop - Pop the front node from the level-order traversal queue.
 *
 * @head: Pointer to the head of the queue.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *temp;

	temp = (*head)->next;
	free(*head);
	*head = temp;
}

/**
 * binary_tree_levelorder - Traverse a binary tree using level-order traversal
 *                          and apply a function to each node's value.
 *
 * @tree: Pointer to the root node of the tree.
 * @func: Pointer to the function to apply to each node's value.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *ptr_head, *ptr_tail;

	if (tree == NULL || func == NULL)
		return;

	ptr_head = ptr_tail = create_node((binary_tree_t *)tree);
	if (ptr_head == NULL)
		return;

	while (ptr_head != NULL)
	{
		pint_push(ptr_head->node, ptr_head, &ptr_tail, func);
		pop(&ptr_head);
	}
}
