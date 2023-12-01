#include "binary_trees.h"

/**
 * array_to_heap - builds a Max Binary Heap tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size: the number of element in the array
 *
 * Return: a pointer to the node_root node of the created Binary Heap
 *         NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int num_i;
	heap_t *node_root = NULL;

	for (num_i = 0; num_i < size; num_i++)
		heap_insert(&node_root, array[num_i]);

	return (node_root);
}
