#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst_helper_func - a func that checks if a binary tree is
 * a valid Binary Search Tree
 * @tree: the pointer to the root node of the the tree to check
 * @low: the value of the smallest node visited
 * @hig: the value of the biggest node visited
 * Return: 1 if the tree is a valid bst else 0
 */
int is_bst_helper_func(const binary_tree_t *tree, int low, int hig)
{
	if (tree != NULL)
	{
		if (tree->n < low || tree->n > hig)
			return (0);
		return (is_bst_helper_func(tree->left, low, tree->n - 1)
				&& is_bst_helper_func(tree->right,
					tree->n + 1, hig));
	}
	return (1);
}

/**
 * binary_tree_is_bst - a func that checks if a binary tree is a
 * valid Binary Search Tree
 * @tree: the ptr to the root node of the tree to check
 * Return: if the tree is valid bst (1) else (0)
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_helper_func(tree, INT_MIN, INT_MAX));
}
