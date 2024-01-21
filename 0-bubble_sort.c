#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */

void bubble_sort(int *array, size_t size) {
  for (size_t i = 0; i < size - 1; i++) {
    int swapped = 0;
    for (size_t j = 0; j < size - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
        swapped = 1;
        printf("Swapped %d and %d\n", array[j + 1], array[j]);
      }
    }
    if (!swapped) {
      break; // Array is already sorted
    }
  }
}
