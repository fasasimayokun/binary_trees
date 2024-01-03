#include "binary_trees.h"

/**
 * is_tree_full_recursive - a func that checks if a
 * binary tree is full recursively
 * @tree: the pointer to the root node of the tree to check
 * Return: if tree is NULL it returns 0
 */
int is_tree_full_recursive(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL && tree->right == NULL)
				|| (tree->left == NULL && tree->right != NULL)
				|| is_tree_full_recursive(tree->left) == 0 ||
				is_tree_full_recursive(tree->right) == 0)
		{
			return (0);
		}
	}
	return (1);
}

/**
 * binary_tree_is_full - a func that Checks if a binary tree is full.
 * @tree: A pointer to the root node of the tree to check.
 * Return: If tree is NULL or is not full (0) else (1)
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (is_tree_full_recursive(tree));
}
