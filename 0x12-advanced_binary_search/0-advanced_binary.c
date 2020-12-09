#include "search_algos.h"

/**
 * advanced_binary - searches the index of a value in a sorted array
 * @array:  pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search
 * Return:  index where value is located otherwise -1
 *
 **/
int advanced_binary(int *array, size_t size, int value)
{
	int min = 0, guess = (size - 1) / 2, index;
	size_t i = 1;

	if (array == NULL || size == 0)
		return (-1);
	printf("Searching in array: %d", array[0]);
	while (i < size)
		printf(", %d", array[i++]);
	printf("\n");
	if (size == 1 && array[0] != value)
		return (-1);
	if (array[guess] == value)
	{
		if (guess == 0 || (array[guess - 1] < value))
			return (guess);
	}
	if (array[guess] < value)
	{
		min += guess + 1;
		array += min;
		if (size % 2 != 0)
			guess--;
	}
	guess++;
	index = advanced_binary(array, guess, value);
	if (index != -1)
		return (index + min);
	return (-1);
}
