#include "binary_trees.h"

/**
 * binary_tree_nodes - a func that counts the nodes
 * with at least 1 child in a binary tree
 * @tree: the pointer to the root node of the tree to count the leaves
 * Return: f tree is NULL it returns 0
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodess = 0;

	if (tree)
	{
		nodess += (tree->left || tree->right) ? 1 : 0;
		nodess += binary_tree_nodes(tree->left);
		nodess += binary_tree_nodes(tree->right);
	}
	return (nodess);
}
