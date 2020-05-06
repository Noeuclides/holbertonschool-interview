#include "binary_trees.h"

/**
 * nodes_number - function that count the number of nodes in a bt
 *
 *@root: pointer to the parent node
 *
 * Return: return the number of nodes of the bt
 */
unsigned int nodes_number(heap_t *root)
{
	if (root == NULL)
		return (0);
	return (1 + nodes_number(root->left) + nodes_number(root->right));
}


/**
 * insert - function that creates a binary tree node
 *
 *@root: pointer to a node in the bt
 *
 *@index: index of the node
 *
 *@nodes_number: number of nodes in the bt
 *
 *@value: value to put in the new node
 *
 * Return: return a pointer to the new node, or NULL on failure
 */

heap_t *insert(heap_t *root, int index, int nodes_number, int value)
{
	heap_t *new;

	if (root == NULL)
		return (NULL);

	if (index + 1 == nodes_number / 2)
	{
		if (nodes_number % 2 == 0)
		{
			root->left = binary_tree_node(root, value);
			return (root->left);
		}
		else
		{
			root->right = binary_tree_node(root, value);
			return (root->right);
		}
	}
	new = insert(root->left, 2 * index + 1, nodes_number, value);
	if (new)
		return (new);
	return (insert(root->right, 2 * index + 2, nodes_number, value));
}


/**
 * heap_insert - function that inserts in a max heap
 *
 *@root: pointer to the parent node of the bt
 *
 *@value: value to put in the new node
 *
 * Return: return a pointer to the new node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;
	int index = 0, nodes_num = 0;

	if (!(*root))
	{
		*root = (binary_tree_node(NULL, value));
		return (*root);
	}
	nodes_num = nodes_number(*root);
	new = insert(*root, index, nodes_num + 1, value);
	while (new->parent != NULL && new->n > new->parent->n)
	{
		new->n = new->parent->n;
		new->parent->n = value;
		new = new->parent;
	}
	return (new);
}
