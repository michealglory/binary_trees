#include "binary_trees.h"

/**
 * array_to_avl - Creates an AVL tree from an array of integers.
 *
 * @array: Pointer to an array of integers.
 * @size: Number of elements in the array.
 *
 * Return: A pointer to the root of the created AVL tree, or NULL on failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *bin_tree = NULL;
	size_t num_i, num_j;

	if (array == NULL)
		return (NULL);

	for (num_i = 0; num_i < size; num_i++)
	{
		for (num_j = 0; num_j < num_i; num_j++)
		{
			if (array[num_j] == array[num_i])
				break;
		}
		if (num_j == num_i)
		{
			if (avl_insert(&bin_tree, array[num_i]) == NULL)
				return (NULL);
		}
	}

	return (bin_tree);
}
