#include "binary_trees.h"

/**
 * bst_search - a func that searches for a value in a Binary Search Tree
 * @tree: the addrs to the root node of the bst to search
 * @value: the data to search for in the bst
 * Return: the ptr to the node containing the value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
