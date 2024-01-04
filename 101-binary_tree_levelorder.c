#include "binary_trees.h"

/**
 * make_node - a func that creates a new levelorder_queue_t node
 * @node: the treenode for the newly created node to contain
 * Return: an addrs to the newly created node else NULL
 */
levelorder_queue_t *make_node(binary_tree_t *node)
{
	levelorder_queue_t *new_node;

	new_node = malloc(sizeof(levelorder_queue_t));
	if (new_node == NULL)
		return (NULL);
	new_node->node = node;
	new_node->next = NULL;

	return (new_node);
}

/**
 * delete_queue - a func that frees a levelorder_queue_t queue
 * @head: the addrs to the head of the queue
 * Return: void(nothing)
 */
void delete_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *aux;

	while (head != NULL)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}

/**
 * child_push - a func that runs a func on a given binary tree node and
 * pushes its children into a levelorder_queue_t queue
 * @node: the tree node to print and push
 * @head: the addrs to the addrs to the head of the queue
 * @tail: the double pointer to the tail of the queue
 * @funct: the pointer to the func to call on the node parameter
 * Return: void(nothing)
 */
void child_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void(*funct)(int))
{
	levelorder_queue_t *new_node;

	funct(node->n);
	if (node->left != NULL)
	{
		new_node = make_node(node->left);
		if (new_node == NULL)
		{
			delete_queue(head);
			exit(1);
		}
		(*tail)->next = new_node;
		*tail = new_node;
	}
	if (node->right != NULL)
	{
		new_node = make_node(node->right);
		if (new_node == NULL)
		{
			delete_queue(head);
			exit(1);
		}
		(*tail)->next = new_node;
		*tail = new_node;
	}
}

/**
 * pop_head - a func that pops the head of the levelorder_queue_t queue
 * @head: the double ptr to the head of the queue
 * Return: void(nothing)
 */
void pop_head(levelorder_queue_t **head)
{
	levelorder_queue_t *aux;

	aux = (*head)->next;
	free(*head);
	*head = aux;
}

/**
 * binary_tree_levelorder - a func that traverses a binary tree using level
 * order traversal
 * @tree: the ptr to the root node of the tree to traverse
 * @func: the ptr to the function to call for individual nodes
 * Return: void(nothing)
 */
void binary_tree_levelorder(const binary_tree_t *tree, void(*func)(int))
{
	levelorder_queue_t *top, *bottom;

	if (tree == NULL || func == NULL)
		return;

	top = bottom = make_node((binary_tree_t *)tree);
	if (top == NULL)
		return;

	while (top != NULL)
	{
		child_push(top->node, top, &bottom, func);
		pop_head(&top);
	}
}
