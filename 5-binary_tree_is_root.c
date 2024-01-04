#include "binary_trees.h"

/**
 * binary_tree_is_root - a func that checks if a
 * node is a root of a binary tree.
 * @node: the addrs to the node to check
 * Return: an int if the node is a root (1) else 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
	{
		return (0);
	}
	return (1);
}
