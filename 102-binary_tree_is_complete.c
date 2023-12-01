#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);
void pop(levelorder_queue_t **head);
int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * create_node - Create a new node for the level-order traversal queue.
 *
 * @node: Pointer to the binary tree node.
 *
 * Return: Pointer to the newly created node, or NULL if allocation fails.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new_node;

	new_node = malloc(sizeof(levelorder_queue_t));
	if (new_node == NULL)
		return (NULL);

	new_node->node = node;
	new_node->next = NULL;

	return (new_node);
}

/**
 * binary_tree_levelorder - Traverse a binary tree using level-order traversal
 *                          and apply a function to each node's value.
 *
 * @tree: Pointer to the root node of the tree.
 * @func: Pointer to the function to apply to each node's value.
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
 * enqueue - Enqueue a binary tree node into the level-order traversal
 * queue.
 *
 * @node: Pointer to the binary tree node to enqueue.
 * @head: Pointer to the head of the queue.
 * @tail: Pointer to the tail of the queue.
 */
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *new_node;

	new_node = create_node(node);
	if (new_node == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = new_node;
	*tail = new_node;
}

/**
 * pop - Dequeue the front node from the level-order traversal queue.
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
 * binary_tree_is_complete - Checks if a binary tree is complete.
 *
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: 1 if the binary tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *ptr_head, *ptr_tail;
	unsigned char mark = 0;

	if (tree == NULL)
		return (0);

	ptr_head = ptr_tail = create_node((binary_tree_t *)tree);
	if (ptr_head == NULL)
		exit(1);

	while (ptr_head != NULL)
	{
		if (ptr_head->node->left != NULL)
		{
			if (mark == 1)
			{
				free_queue(ptr_head);
				return (0);
			}
			push(ptr_head->node->left, ptr_head, &ptr_tail);
		}
		else
			mark = 1;
		if (ptr_head->node->right != NULL)
		{
			if (mark == 1)
			{
				free_queue(ptr_head);
				return (0);
			}
			push(ptr_head->node->right, ptr_head, &ptr_tail);
		}
		else
			mark = 1;
		pop(&ptr_head);
	}
	return (1);
}
