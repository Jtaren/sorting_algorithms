#include "sort.h"

/**
 * _max - returns the max of the given integer
 * @array: list of an integer
 * @size: the length of the array
 *
 * Return: max value in the array of integer
 */
int _max(int *array, int size)
{
	int x, max = array[0];

	for (x = 1; x < size; x++)
		if (array[x] > max)
			max = array[x];
	return (max);
}
/**
 * _count - counts the number of the sorted array
 * @array: list of an integer
 * @n: the length of the array
 * @exp: exp is 10^x
 * @output: array to save the temporary values
 */
void _count(int *array, size_t n, int exp, int *output)
{
	int x;
	int count[10] = {0};

	for (x = 0; x < (int)n; x++)
		count[(array[x] / exp) % 10]++;

	for (x = n - 1 >= 0; x--)
	{
		output[count[(array[x] / exp) % 10] - 1] = array[x];
		count[(array[x] / exp) % 10]--;
	}
	for (i = 0; i < (int)n; i++)
		array[i] = output[i];
}
/**
 * radix_spot - sorts an array of integers in ascending order
 * @array: list of an integer
 * @size: the length of the array
 *
 * Return: void has no return value
 */
void radix_sort(int *array, size_t size)
{
	int exp, maximum = 0;
	int *output = '\0';

	if (array == NULL || size < 2)
		return;

	maximum = _max(array, size);
	output = malloc(size * sizeof(int));
	if (output == NULL)
		return;

	for (exp = 1; maximum / exp > 0; exp *= 10)
	{
		_count(array, size, exp, output);
		print_array(array, size);
	}
	free(output);
}
