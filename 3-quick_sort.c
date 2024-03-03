#include "sort.h"

/**
 * swap - swap two integers
 *
 * @x: first integer
 * @y: second integer
 *
 * Return: Nothing
 */
void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
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
	int i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);

	return (i + 1);
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
	quickSort(array, 0, size - 1, size);
}
