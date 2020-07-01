#include "slide_line.h"

/**
 * slide_left - merges an array of integers
 *
 * @line: points to an array of integers
 *
 * @size: number of elements in the array
 *
 */
void slide_left(int *line, size_t size)
{
	size_t i, j, num, m, flag = 1;

	for (i = 0; i < size; i++)
	{
		flag = 1;
		for (j = i + 1; j < size && flag == 1; j++)
		{
			if (line[i] == 0)
				flag = 0;
			else if (line[i] == line[j])
			{
				line[i] = line[i] * 2;
				flag = 0;
				i += 1;
				line[j] = 0;
			}
			else if (line[i] != line[j] && line[j] != 0)
				flag = 0;
		}
	}
}

/**
 * slide - slide an array of integers
 *
 * @line: points to an array of integers
 *
 * @size: number of elements in the array
 *
 */
void slide(int *line, size_t size)
{
	size_t	i = 0;
	int flag = 1;

	while (i < size)
	{
		if (line[i] == 0 && flag == 1)
		{
			num = i;
			flag = 0;
		}
		if (line[i] != 0 && flag == 0)
		{
			m = line[i];
			line[i] = line[num];
			line[num] = m;
			flag = 1;
			i = num;
		}
		i++;
	}
}


/**
 * reverse_line - reverse an array integers
 *
 * @line: points to an array of integers
 *
 * @size: number of elements in the array
 *
 */
void reverse_line(int *line, size_t size)
{
	size_t start = 0, end = size - 1;
	int aux;

	while (start < end)
	{
		aux = line[start];
		line[start] = line[end];
		line[end] = aux;
		start++;
		end--;
	}
}



/**
 * slide_line - slides and merges an array of integers
 *
 * @line: points to an array of integers
 *
 * @size: number of elements in the array
 *
 * @direction: can be either left or right
 *
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
		slide(line, size);
	}
	if (direction == SLIDE_RIGHT)
	{
		reverse_line(line, size);
		slide_left(line, size);
		slide(line, size);
		reverse_line(line, size);
	}

	return (1);
}
