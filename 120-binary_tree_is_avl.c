#include "binary_trees.h"
#include <limits.h>

/**
 * tree_height - a func that measures the height of a binary tree.
 * @tree: the addrs to the root node of the tree to measure the height.
 * Return: If tree is NULL it returns 0 else height.
 */
size_t tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lft = 0, rgt = 0;

		lft = tree->left ? 1 + tree_height(tree->left) : 1;
		rgt = tree->right ? 1 + tree_height(tree->right) : 1;
		return ((lft > rgt) ? lft : rgt);
	}
	return (0);
}

/**
 * is_avl_helper_func - a func that checks if a binary tree
 * is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @low: The value of the smallest node visited thus far.
 * @hig: The value of the largest node visited this far.
 * Return: If the tree is a valid AVL tree 1 else 0.
 */
int is_avl_helper_func(const binary_tree_t *tree, int low, int hig)
{
	size_t l_hgt, r_hgt, dif;

	if (tree != NULL)
	{
		if (tree->n < low || tree->n > hig)
			return (0);
		l_hgt = tree_height(tree->left);
		r_hgt = tree_height(tree->right);
		dif = l_hgt > r_hgt ? l_hgt - r_hgt : r_hgt - l_hgt;
		if (dif > 1)
			return (0);
		return (is_avl_helper_func(tree->left, low, tree->n - 1) &&
			is_avl_helper_func(tree->right, tree->n + 1, hig));
	}
	return (1);
}

/**
 * binary_tree_is_avl - a func that checks if a binary tree is
 * a valid AVL tree.
 * @tree: the ptr to the root node of the tree to check.
 * Return: 1 if tree is a valid AVL tree else 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper_func(tree, INT_MIN, INT_MAX));
}
