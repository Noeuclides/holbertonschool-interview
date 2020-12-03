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
 * max_heap - get a max heap
 *
 * @array: array of integers
 *
 * @lastIndex: the index to evaluate in the unsorted part of the array
 *
 * @idx: index of head node
 *
 * @size: size of the array
 */
void max_heap(int *array, size_t lastIndex, size_t idx, size_t size)
{
	size_t parent, left, right;

	parent = idx;
	left = 2 * idx + 1;
	right = 2 * idx + 2;

	if (left < lastIndex && array[left] > array[parent])
		parent = left;

	if (right < lastIndex && array[right] > array[parent])
		parent = right;

	if (parent != idx)
	{
		swap_nodes(array, idx, parent, size);

		max_heap(array, lastIndex, parent, size);
	}
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
	int i = 0;

	if (!array || size == 1)
		return;
	for (i = size / 2 - 1; i >= 0; i--)
		max_heap(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		swap_nodes(array, 0, i, size);
		max_heap(array, i, 0, size);
	}
}
