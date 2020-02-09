#include "lists.h"

/**
 * insert_node - insert node in a linked list
 *
 * @head: pointer to the first node of the linked list
 *
 * @number: integer value of the new node to insert
 *
 * Return: the head of the linked list with the new node inserted
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *aux, *before, *new_node;

	aux = *head;
	before = NULL;

	new_node = malloc(sizeof(listint_t));
	new_node->n = number;
	new_node->next = NULL;

	while (aux->next != NULL)
	{
		if (aux->n > number)
		{
			if (before == NULL)
			{
				new_node->next = *head;
				*head = new_node;
				return (*head);
			}
			else
			{
				before->next = new_node;
				new_node->next = aux;
				return (*head);
			}
		}
		else
		{
			before = aux;
			aux = aux->next;
		}
	}
	aux->next = new_node;
	new_node->next = NULL;
	return (*head);
}
