#include "binary_trees.h"

/**
 * binary_tree_uncle - a func that finds the uncle of a node in the tree
 * @node: the addrs to the node to find its uncle
 * Return: if node is  NULL return NULL else the addrs to the sibling
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent == NULL ||
			node->parent->parent == NULL)
	{
		return (NULL);
	}
	if (node->parent->parent->left == node->parent)
	{
		return (node->parent->parent->right);
	}
	return (node->parent->parent->left);
}
