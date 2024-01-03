#include "binary_trees.h"

/**
 * binary_tree_preorder - a func that goes through a binary
 * tree using pre-order traversal
 * @tree: the addrs to the root node of the tree to traverse
 * @func: the addrs to a func to call for individual node
 * Return: void(nothing)
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
