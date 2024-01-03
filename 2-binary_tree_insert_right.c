#include "binary_trees.h"

/**
 * binary_tree_insert_right - a func that inserts a node
 * as the right-child of another node
 * @parent: the addrs to the node to put the right child into
 * @value: the data to store in the new node.
 * Return: the addrs to the new node of type binary_tree_t
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
	{
		return (NULL);
	}
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}
	parent->right = new_node;

	return (new_node);
}
