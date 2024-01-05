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
 * push_node - a func that pushes a node to the
 * back of the levelorder_queue_t queue
 * @node: the tree node to print and push
 * @head: the addrs to the addrs to the head of the queue
 * @tail: the double pointer to the tail of the queue
 * Return: void(nothing)
 */
void push_node(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *new_node;

	new_node = make_node(node);
	if (new_node == NULL)
	{
		delete_queue(head);
		exit(1);
	}
	(*tail)->next = new_node;
	*tail = new_node;
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
 * binary_tree_is_complete - a func that check a binary tree is complete
 * @tree: the ptr to the root node of the tree to traverse
 * Return: int type if tree is NULL return 0 else 1
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *top, *bottom;
	unsigned char flg = 0;

	if (tree == NULL)
		return (0);

	top = bottom = make_node((binary_tree_t *)tree);
	if (top == NULL)
		exit(1);
	while (top != NULL)
	{
		if (top->node->left != NULL)
		{
			if (flg == 1)
			{
				delete_queue(top);
				return (0);
			}
			push_node(top->node->left, top, &bottom);
		}
		else
			flg = 1;
		if (top->node->right != NULL)
		{
			if (flg == 1)
			{
				delete_queue(top);
				return (0);
			}
			push_node(top->node->right, top, &bottom);
		}
		else
			flg = 1;
		pop_head(&top);
	}
	return (1);
}
