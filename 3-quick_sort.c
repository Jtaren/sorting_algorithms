#include "sort.h"

void swap_ints(int *a, int *b);
int part_lomuto(int *array, size_t size, int left, int right);
void sort_lomuto(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * part_lomuto - Arrange a portion of an array of integers using the Lomuto partition
 * 		scheme, with the last element serving as the pivot.
 * @array: The int array.
 * @size: The array size.
 * @left: First index of the subset to order.
 * @right: Last index of the subset to order.
 *
 * Return: The final partition index.
 */
int part_lomuto(int *array, size_t size, int left, int right)
{
	int *pivot, high, low;

	pivot = array + right;
	for (high = low = left; low < right; low++)
	{
		if (array[low] < *pivot)
		{
			if (high < low)
			{
				swap_ints(array + low, array + high);
				print_array(array, size);
			}
			high++;
		}
	}

	if (array[high] > *pivot)
	{
		swap_ints(array + high, pivot);
		print_array(array, size);
	}

	return (high);
}

/**
 * sort_lomuto - Recursively implement quicksort algo
 * @array: An int array to be sorted.
 * @size: The array size.
 * @left: First index of the array partition to order.
 * @right: last array index partition to order.
 *
 * Description: Incorporates the Lomuto partition scheme.
 */
void sort_lomuto(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = part_lomuto(array, size, left, right);
		sort_lomuto(array, size, left, part - 1);
		sort_lomuto(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort an int array from low to high through the
 * 		quicksort algorithm.
 * @array: An int array.
 * @size: The array size.
 *
 * Description: Employs the Lomuto partition scheme and displays the array
 * 		following every interchange of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort_lomuto(array, size, 0, size - 1);
}
