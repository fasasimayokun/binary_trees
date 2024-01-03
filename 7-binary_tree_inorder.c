#include "binary_trees.h"

/**
 * binary_tree_inorder - a func that goes through a binary
 * tree using in-order traversal
 * @tree: the addrs to the root node of the tree to traverse
 * @func: the addrs to a func to call for individual node
 * Return: void(nothing)
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
