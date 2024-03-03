#include "sort.h"

/**
 * qswap - swap two integers
 *
 * @x: first integer
 * @y: second integer
 * @array: array to sort
 * @size: size of the array
 *
 * Return: Nothing
 */
void qswap(int *array, size_t size, int *x, int *y)
{
	int temp;

	if (*x != *y)
	{
		temp = *x;
		*x = *y;
		*y = temp;
		print_array(array, size);
	}
}

/**
 * partition - ...
 *
 * @array: array of integers
 * @low: low index
 * @high: high index
 * @size: size of the array
 *
 * Return: pivot index
 */
int partition(int array[], int low, int high, size_t size)
{
	int pivot = array[high];
	int i, j;

	for (i = j = low; j < high; j++)
		if (array[j] < pivot)
			qswap(array, size, &array[i++], &array[j]);

	qswap(array, size, &array[i], &array[high]);

	return (i);
}
/**
 * quickSort - sort array of integer with quick sort algorithm
 *
 * @array: array to sort
 * @low: low index
 * @high: high index
 * @size: size of the array
 *
 * Return: Nothing
 */
void quickSort(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);

		quickSort(array, low, pivot_index - 1, size);
		quickSort(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - sort array of integer with quick sort algorithm
 *
 * @array: array to sort
 * @size: size of the array
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quickSort(array, 0, size - 1, size);
}
