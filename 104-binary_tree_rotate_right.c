#include "binary_trees.h"

/**
 * binary_tree_rotate_right - a func that performs a
 * right-rotation on a binary tree
 * @tree: the addrs to the root node of the tree to rotate
 * Return: the pointer to the new root node after rotation
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivt, *aux;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	pivt = tree->left;
	aux = pivt->right;
	pivt->right = tree;
	tree->left = aux;

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
