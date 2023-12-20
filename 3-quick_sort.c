#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - two integers are swapped in an array.
 * @a: first integer.
 * @b: second integ.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition -  an array of integers' subset order according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: array of integers.
 * @size: size of the array.
 * @left:  start index of the subset to order.
 * @right: end index of the subset to order.
 *
 * Return:  final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - the quicksort algorithm is implemented through recursion.
 * @array: array of integers to sort.
 * @size:  size of the array.
 * @left:  first index of the array partition to order.
 * @right: last index of the array partition to order.
 *
 * Description: the Lomuto partition scheme is used.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort -  an array of integers is sorted in ascending
 *              order using the quicksort algorithm.
 * @array: array of integers.
 * @size:  size of the array.
 *
 * Description: Uses the Lomuto partition scheme to print
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
