#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it.
 *
 * @list: pointer to the head of the linked list
 *
 * Return: 1 if there is a cycle, 0 otherwise
 */

int check_cycle(listint_t *list)
{
	listint_t *turtle, *hare;

	if (!list)
		return (0);

	turtle = list;
	hare = list;

	while (hare->next->next)
	{
		hare = hare->next->next;
		turtle = turtle->next;

		if (hare == turtle)
			return (1);
	}

	return (0);
}
