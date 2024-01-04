#include "binary_trees.h"

/**
 * binary_trees_ancestor - a func that finds the lowest
 * common ancestor of two nodes
 * @first: the addrs to the 1st node
 * @second: the addrs to the 2nd node
 * Return: If no common ancestor was found it returns NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *fathr, *mothr;

	if (!first || !second)
	{
		return (NULL);
	}
	if (first == second)
		return ((binary_tree_t *)first);

	mothr = first->parent;
	fathr = second->parent;
	if (first == fathr || !mothr || (!mothr->parent && fathr))
	{
		return (binary_trees_ancestor(first, fathr));
	}
	else if (mothr == second || !fathr || (!fathr->parent && mothr))
	{
		return (binary_trees_ancestor(mothr, second));
	}
	return (binary_trees_ancestor(mothr, fathr));
}
