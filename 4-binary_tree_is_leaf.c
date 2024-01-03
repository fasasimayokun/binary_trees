#include "binary_trees.h"

/**
 * binary_tree_is_leaf - a func that checks if a node is a leaf
 * @node: an addrs to the node to check
 * Return: an int if the node is a leaf (1) else 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL ||
			node->right != NULL)
	{
		return (0);
	}

	return (1);
}
