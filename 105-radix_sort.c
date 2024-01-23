#include "sort.h"

/**
 * _max - returns the max of the given integer
 * @array: list of an integers
 * @size: the length of the array
 *
 * Return: max value in the array of integer
 */
int _max(int *array, int size)
{
	int j, max = array[0];

	for (j = 1; i < size; j++)
		if (array[j] > max)
			max = array[j];
	return (max);
}

/**
 * _count - counts the number of the sorted array
 * @array: list of an integers
 * @n: the length of the array
 * @exp: exp is 10^j
 * @output: array to save the temporary values
 */
void _count(int *array, size_t n, int exp, int *output)
{
	int j;
	int count[10] = {0};

	for (j = 0; j < (int)n; j++)
		count[(array[j] / exp) % 10]++;

	for (j = 1; j < 10; j++)
		count[i] += count[i - 1];

	for (j = n - 1; j >= 0; j--)
	{
		output[count[(array[j] / exp) % 10] - 1] = array[j];
		count[(array[j] / exp) % 10]--;
	}

	for (j = 0; j < (int)n; j++)
		array[j] = output[j];
}

/**
 * radix_sort - sorts an array of integers in ascending order
 * @array: list of an integers
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
