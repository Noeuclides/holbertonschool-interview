#include "palindrome.h"


/**
 * reverse_number - reverse a number recursevely
 *
 * @n: number to be reversed
 *
 * @aux: number that is going to become the reverse number
 *
 * Return: the number reversed
 */
unsigned long reverse_number(unsigned long n, unsigned long aux)
{
	unsigned long reverse = 0, number = 0;

	if (n == 0)
		return (aux);

	reverse = n % 10;
	number = aux * 10 + reverse;

	return (reverse_number(n / 10, number));
}


/**
 * is_palindrome - function that checks if a number is a palindrome.
 *
 * @n: number to be checked
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long aux = 0, reverse = 0;


	reverse = reverse_number(n, aux);

	if (reverse == n)
		return (1);

	return (0);
}
