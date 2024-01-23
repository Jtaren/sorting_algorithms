#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to be swapped.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An int array.
 * @size: The array size.
 *
 * Description: Employs the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t space, x, y;

	if (array == NULL || size < 2)
		return;

	for (space = 1; space < (size / 3);)
		space = space * 3 + 1;

	for (; space >= 1; space /= 3)
	{
		for (x = space; x < size; x++)
		{
			y = x;
			while (y >= space && array[y - space] > array[y])
			{
				swap_ints(array + y, array + (y - space));
				y -= space;
			}
		}
		print_array(array, size);
	}
}
