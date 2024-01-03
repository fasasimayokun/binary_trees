#include "binary_trees.h"

/**
 * binary_tree_sibling - a func that finds the sibling of a node
 * @node: the addrs to the node to find its sibling
 * Return: if node is  NULL return NULL else the addrs to the sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
	{
		return (NULL);
	}
	if (node->parent->left == node)
	{
		return (node->parent->right);
	}
	return (node->parent->left);
}
