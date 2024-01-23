#include "sort.h"

/**
 * swap_ints - Swap two ints in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sort an int array of integers from lowest
 * 		highest through selection sort
 * @array: An int array
 * @size: Array size
 *
 */
void selection_sort(int *array, size_t size)
{
	int *low;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		low = array + i;
		for (j = i + 1; j < size; j++)
			low = (array[j] < *low) ? (array + j) : low;

		if ((array + i) != low)
		{
			swap_ints(array + i, low);
			print_array(array, size);
		}
	}
}
