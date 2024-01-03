#include "binary_trees.h"

/**
 * is_node_leaf - a func that checks if a node is a leaf of a binary tree.
 * @node: the addrs to the node to check.
 * Return: If the node is a leaf (1) else (0).
 */
unsigned char is_node_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * node_depth - a func that returns the depth of a given node in a binary tree
 * @tree: the addrs to the node to measure the depth of.
 * Return: unsigned int of the depth of node.
 */
size_t node_depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + node_depth(tree->parent) : 0);
}

/**
 * get_tree_leaf - a func that returns a leaf of a binary tree.
 * @tree: the addrs to the root node of the tree to find a leaf in.
 * Return: the pointer to the first leaf encountered
 */
const binary_tree_t *get_tree_leaf(const binary_tree_t *tree)
{
	if (is_node_leaf(tree) == 1)
	{
		return (tree);
	}
	return (tree->left ? get_tree_leaf(tree->left) : get_tree_leaf(tree->right));
}

/**
 * is_tree_perfect_recursive - a func that checks if a
 * binary tree is perfect recursively.
 * @tree: A pointer to the root node of the tree to check.
 * @leaf_depth: The depth of a leaf in the binary tree.
 * @level: Level/position of current node.
 * Return: If the tree is perfect (1) else (0)
 */
int is_tree_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (is_node_leaf(tree))
	{
		return (level == leaf_depth ? 1 : 0);
	}
	if (tree->left == NULL || tree->right == NULL)
	{
		return (0);
	}
	return (is_tree_perfect_recursive(tree->left, leaf_depth, level + 1) &&
		is_tree_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - a func that checks if a binary tree is perfect
 * @tree: A pointer to the root node of the tree to check.
 * Return: If tree is NULL or not perfect (0) else (1)
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (is_tree_perfect_recursive(tree, node_depth(get_tree_leaf(tree)), 0));
}
