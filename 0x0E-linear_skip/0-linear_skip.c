#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers.
 *
 * @list: pointer to the head of the skip list to search in.
 *
 * @value: value to search for.
 *
 * Return: pointer on the first node where value is located or NULL on fail.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *min, *max;

	if (!list)
		return (NULL);
	min = list;
	if (!list->express)
		return (NULL);
	max = list->express;

	while (max != NULL)
	{
		printf("Value checked at index [%lu] = [%i]\n",
		       max->index, max->n);
		if (value < max->n)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
			       min->index, max->index);
			return (linear_search(min, max, value));
		}
		if (max->express == NULL)
			return (linear_search(max, max, value));
		max = max->express;
		min = min->express;
	}
	return (NULL);
}

/**
 * linear_search - searches for a value in a sorted linked list of integers.
 *
 * @min: pointer to the node with the minimum value interval.
 *
 * @max: pointer to the node with the maximum value interval.
 *
 * @value: value to search for.
 *
 * Return: pointer on the first node where value is located or NULL on fail.
 */
skiplist_t *linear_search(skiplist_t *min, skiplist_t *max, int value)
{
	if (min == max)
	{
		while (max->next != NULL)
			max = max->next;
		printf("Value found between indexes [%lu] and [%lu]\n",
		       min->index, max->index);
		max = max->next;
	}
	while (min != max)
	{
		printf("Value checked at index [%lu] = [%i]\n",
		       min->index, min->n);
		if (min->n == value)
			return (min);
		min = min->next;
	}
	return (NULL);
}

