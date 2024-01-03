#include "binary_trees.h"

/**
 * binary_tree_postorder - a func that goes through a binary
 * tree using post-order traversal
 * @tree: the addrs to the root node of the tree to traverse
 * @func: the addrs to a func to call for individual node
 * Return: void(nothing)
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
