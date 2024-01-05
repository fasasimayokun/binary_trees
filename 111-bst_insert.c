#include "binary_trees.h"

/**
 * bst_insert - a func that inserts a value in a Binary Search Tree
 * @tree: the double ptr to the root node of the BST to insert the value
 * @value: the data to store in the node to be inserted
 * Return: the ptr to the created node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *pres, *new_node;

	if (tree != NULL)
	{
		pres = *tree;
		if (pres == NULL)
		{
			new_node = binary_tree_node(pres, value);
			if (new_node == NULL)
				return (NULL);
			return (*tree = new_node);
		}
		if (value < pres->n)
		{
			if (pres->left != NULL)
				return (bst_insert(&pres->left, value));
			new_node = binary_tree_node(pres, value);
			if (new_node == NULL)
				return (NULL);
			return (pres->left = new_node);
		}
		if (value > pres->n)
		{
			if (pres->right != NULL)
				return (bst_insert(&pres->right, value));
			new_node = binary_tree_node(pres, value);
			if (new_node == NULL)
				return (NULL);
			return (pres->right = new_node);
		}
	}
	return (NULL);
}
