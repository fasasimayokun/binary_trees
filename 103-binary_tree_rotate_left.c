#include "binary_trees.h"

/**
 * binary_tree_rotate_left - a func that performs a
 * left-rotation on a binary tree
 * @tree: the addrs to the root node of the tree to rotate
 * Return: the pointer to the new root node after rotation
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivt, *aux;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	pivt = tree->right;
	aux = pivt->left;
	pivt->left = tree;
	tree->right = aux;

	if (aux != NULL)
	{
		aux->parent = tree;
	}
	aux = tree->parent;
	tree->parent = pivt;
	pivt->parent = aux;

	if (aux != NULL)
	{
		if (aux->left == tree)
			aux->left = pivt;
		else
			aux->right = pivt;
	}
	return (pivt);
}
