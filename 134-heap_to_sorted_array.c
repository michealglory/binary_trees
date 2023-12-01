#include "binary_trees.h"

/**
 * tree_size - measures the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t bin_height_l = 0;
	size_t bin_height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		bin_height_l = 1 + tree_size(tree->left);

	if (tree->right)
		bin_height_r = 1 + tree_size(tree->right);

	return (bin_height_l + bin_height_r);
}

/**
 * heap_to_sorted_array - converts a Binary Max Heap
 * to a sorted array of integers
 *
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 *
 * Return: pointer to array sorted in descending order
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int num_i, *num_a = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	num_a = malloc(sizeof(int) * (*size));

	if (!num_a)
		return (NULL);

	for (num_i = 0; heap; num_i++)
		num_a[num_i] = heap_extract(&heap);

	return (num_a);
}
