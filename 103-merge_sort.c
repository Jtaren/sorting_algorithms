#include "sort.h"

void sub_arr_merge(int *sub_arr, int *buff, size_t right, size_t mid,
		size_t left);
void recursive_merge_sort(int *sub_arr, int *buff, size_t right, size_t left);
void merge_sort(int *array, size_t size);

/**
 * sub_arr_merge - Sort an int sub-array.
 * @sub_arr: A sub-array of an array of int to sort.
 * @buff: A buffer to store the sorted subarray.
 * @right: Front array index.
 * @mid: Middle array index.
 * @left: Back array index.
 */
void sub_arr_merge(int *sub_arr, int *buff, size_t right, size_t mid,
		size_t left)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(sub_arr + right, mid - right);

	printf("[right]: ");
	print_array(sub_arr + mid, left - mid);

	for (i = right, j = mid; i < mid && j < left; k++)
		buff[k] = (sub_arr[i] < sub_arr[j]) ? sub_arr[i++] : sub_arr[j++];
	for (; i < mid; i++)
		buff[k++] = sub_arr[i];
	for (; j < left; j++)
		buff[k++] = sub_arr[j];
	for (i = right, k = 0; i < left; i++)
		sub_arr[i] = buff[k++];

	printf("[Done]: ");
	print_array(sub_arr + right, left - right);
}

/**
 * recursive_merge_sort - Recursively implement the merge sort algo.
 * @sub_arr: A sub_array of an int array sort.
 * @buff: A buffer to store the sorted result.
 * @right: The front subarray index.
 * @left: The back subarray index.
 */
void recursive_merge_sort(int *sub_arr, int *buff, size_t right, size_t left)
{
	size_t mid;

	if (left - right > 1)
	{
		mid = right + (left - right) / 2;
		recursive_merge_sort(sub_arr, buff, right, mid);
		recursive_merge_sort(sub_arr, buff, mid, left);
		sub_arr_merge(sub_arr, buff, right, mid, left);
	}
}

/**
 * merge_sort - Sort an int array from low to high through
 * the merge sort algo.
 * @array: An int array.
 * @size: The array size.
 *
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	recursive_merge_sort(array, buff, 0, size);

	free(buff);
}
