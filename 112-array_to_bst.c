#include "binary_trees.h"

/**
 * array_to_bst - a func that builds a Binary Search Tree from an array
 * @array: the ptr to the 1st elem of the array to be converted
 * @size: the no of elems in the array argument
 * Return: the ptr to the root node of the bst
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;

	size_t nm, jj;

	if (array == NULL)
		return (NULL);

	for (nm = 0; nm < size; nm++)
	{
		for (jj = 0; jj < nm; jj++)
		{
			if (array[jj] == array[nm])
				break;
		}
		if (jj == nm)
		{
			if (bst_insert(&tree, array[nm]) == NULL)
				return (NULL);
		}
	}
	return (tree);
}
