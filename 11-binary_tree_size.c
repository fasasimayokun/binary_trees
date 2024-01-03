#include "binary_trees.h"

/**
 * binary_tree_size - a func that measures the size
 * of a node in a binary tree
 * @tree: the addrs to the root node of the tree
 * to measure the size
 * Return: unsiggned int the size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t sz = 0;

	if (tree)
	{
		sz = sz + 1;
		sz = sz + binary_tree_size(tree->left);
		sz = sz + binary_tree_size(tree->right);
	}
	return (sz);
}
