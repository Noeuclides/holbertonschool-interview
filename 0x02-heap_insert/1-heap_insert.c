#include "binary_trees.h"

/**
 * binary_tree_node - function that creates a binary tree node
 *
 *@parent: pointer to the parent node of the node to create
 *
 *@value: value to put in the new node
 *
 * Return: return a pointer to the new node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;

	new = malloc(sizeof(heap_t));
	if (!new)
		return (NULL);
	if (!parent)
	{
		new->n = value;
		new->parent = NULL;
		new->left = NULL;
		new->right = NULL;
		return (new);
	}
	new->parent = parent;
	new->n = value;
	if (value < parent->n)
	{
		parent->left = new;
	}
	else
	{
		parent->right = new;
	}

	return (new);
}
