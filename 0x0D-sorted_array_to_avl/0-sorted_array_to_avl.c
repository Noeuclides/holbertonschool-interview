#include "binary_trees.h"

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 *
 * @array: pointer to the first element of the array to be converted
 *
 * @size: number of element in the array
 *
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *balance_tree = NULL, *node_ref = NULL;
	size_t mid_index;

	if (!array || !size)
		return (NULL);

	balance_tree = malloc(sizeof(avl_t));
	if (!balance_tree)
		return (NULL);

	if (size % 2 == 0)
		mid_index = (size / 2) - 1;
	else
		mid_index = size / 2;

	balance_tree->n = *(array + mid_index);
	balance_tree->parent = NULL;
	balance_tree->left = NULL;
	balance_tree->right = NULL;
	node_ref = balance_tree;
	left_tree_side(balance_tree, node_ref, array, 0, mid_index - 1);
	right_tree_side(balance_tree, node_ref, array, mid_index + 1, size - 1);

	return (balance_tree);
}

/**
 * left_tree_side - builds the left childs of the tree recursively
 *
 * @tree: pointer to the root node of the created AVL tree
 *
 * @node_t: pointer to the last node created in the tree
 *
 * @array: pointer to the first element of the array to be converted
 *
 * @low: low index to evaluate in the array
 *
 * @high: high index to evaluate in the array
 *
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *left_tree_side(avl_t *tree, avl_t *node_t, int *array,
		      size_t low, size_t high)
{
	avl_t *node = NULL;
	size_t mid_index;

	if (low > high)
		return (NULL);

	if (node_t->n == array[low] || node_t->n == array[high])
		return (tree);

	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);
	mid_index = (high + low) / 2;
	if (low == high || *(array + mid_index) == node_t->n)
	{
		node_t->left = node;
		node->n = *(array + low);
		node->parent = node_t;
		node->left = NULL;
		node->right = NULL;
		return (tree);
	}

	node->n = *(array + mid_index);
	node->parent = node_t;
	node_t->left = node;

	left_tree_side(tree, node, array, low, mid_index - 1);
	right_tree_side(tree, node, array, mid_index + 1, high);

	return (tree);
}

/**
 * right_tree_side - builds the right childs of the tree recursively
 *
 * @tree: pointer to the root node of the created AVL tree
 *
 * @node_t: pointer to the last node created in the tree
 *
 * @array: pointer to the first element of the array to be converted
 *
 * @low: low index to evaluate in the array
 *
 * @high: high index to evaluate in the array
 *
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *right_tree_side(avl_t *tree, avl_t *node_t, int *array,
		       size_t low, size_t high)
{
	avl_t *node = NULL;
	size_t mid_index;

	if (low > high)
		return (NULL);

	if (node_t->n == array[low] || node_t->n == array[high])
		return (tree);

	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);
	mid_index = (high + low) / 2;
	if (low == high || *(array + mid_index) == node_t->n)
	{
		node_t->right = node;
		node->n = *(array + low);
		node->parent = node_t;
		node->right = NULL;
		node->left = NULL;
		return (tree);
	}
	node->n = *(array + mid_index);
	node->parent = node_t;
	node_t->right = node;

	right_tree_side(tree, node, array, mid_index + 1, high);
	left_tree_side(tree, node, array, low, mid_index - 1);

	return (tree);
}
