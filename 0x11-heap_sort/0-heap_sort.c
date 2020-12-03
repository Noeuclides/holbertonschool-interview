#include "sort.h"


/**
 * swap_nodes - swap values in the array when parent is smaller than child
 *
 * @array: array of integers that is seen as a complete binary tree
 *
 * @parent: position of the parent to swap with the child
 *
 * @child: position of the child to swap with the parent
 *
 * @size: size of the array
 */
void swap_nodes(int *array, size_t parent, size_t child, size_t size)
{
	int aux;

	aux = array[parent];
	array[parent] = array[child];
	array[child] = aux;
	print_array(array, size);
}

/**
 * compare_nodes - compare parent with left and child nodes in the array
 *
 * @array: array of integers that is seen as a complete binary tree
 *
 * @lastParent: last parent of the array(binary tree)
 *
 * @lastIndex: the index to evaluate in the unsorted part of the array
 *
 * @size: size of the array
 *
 * Return: integer that can be 0 of no swap was done or 1 otherwise
 */
int compare_nodes(int *array, int lastParent, int lastIndex, size_t size)
{
	int parent, leftChild, rightChild;
	int swap = 0;

	for (parent = lastParent; parent >= 0; parent--)
	{
		leftChild = parent * 2 + 1;
		rightChild = parent * 2 + 2;
		if (leftChild <= lastIndex && rightChild <= lastIndex)
		{
			if (array[leftChild] >= array[rightChild])
			{
				if (array[parent] < array[leftChild])
				{
					swap_nodes(array, parent, leftChild, size);
					swap = 1;
					parent = lastParent + 1;
				}
			}
			else
			{
				if (array[parent] < array[rightChild])
				{
					swap_nodes(array, parent, rightChild, size);
					swap = 1;
					parent = lastParent + 1;
				}
			}
		}
		else if (leftChild <= lastIndex)
		{
			if (array[parent] < array[leftChild])
			{
				swap_nodes(array, parent, leftChild, size);
				swap = 1;
				parent = lastParent + 1;
			}
		}
	}
	return (swap);
}

/**
 * heap_sort - sorts an array of integers in asc order with Heap sort algorithm
 *
 * @array: array of integers that is seen as a complete binary tree
 *
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int lastParent, lastIndex;
	int swap = 1;

	if (!array || size == 1)
		return;

	lastIndex = size - 1;
	while (lastIndex > 0 && swap == 1)
	{
		lastParent = lastIndex / 2;
		swap = compare_nodes(array, lastParent, lastIndex, size);
		swap_nodes(array, 0, lastIndex, size);
		lastIndex -= 1;
	}
}
