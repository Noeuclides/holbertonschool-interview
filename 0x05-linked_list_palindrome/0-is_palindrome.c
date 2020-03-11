#include "lists.h"

/**
 * nodes_equal - check if the nodes are equal
 *
 *@head: head of the linked list
 *
 *@head2: pointer to the node in the middle of the list
 *
 *@index: index of the middle node of the list
 *
 *@lenght: lenght of the node to compare with the first part of the list
 *
 *Return:0 if it is not equal, 1 if it is equal
 **/
int nodes_equal(listint_t *head, listint_t *head2, int index, int lenght)
{
	listint_t *aux;
	int i;

	aux = head2;
	for (i = index; i < lenght - 1; i++)
		aux = aux->next;

	if (head->n != aux->n)
		return (0);

	return (1);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 *
 *@head: the head of the linked list
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 **/
int is_palindrome(listint_t **head)
{
	listint_t *aux, *head2;
	int i, j, index, palindrome;

	if (*head == NULL)
		return (1);

	aux = *head;
	head2 = *head;

	for (i = 1; aux->next != NULL; i++)
		aux = aux->next;

	if (i % 2 == 0)
		index = i / 2;
	else
		index = i / 2 + 1;

	for (j = 0; j < index; j++)
		head2 = head2->next;

	aux = *head;

	while (i > index)
	{
		palindrome = nodes_equal(aux, head2, index, i);
		if (palindrome == 0)
			return (0);
		aux = aux->next;
		i -= 1;
	}
	return (1);
}
