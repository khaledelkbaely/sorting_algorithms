#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - sort array of integers in ascending order using bubble sort
 *
 * @array: array to sort
 * @size: size of the array
 *
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, n;
	char swapped = 0;

	if (!array || !size)
		return;
	n = size;
	for (i = 0; i < size; i++)
	{
		for (j = 1; j < n; j++)
		{
			if (array[j - 1] > array[j])
			{
				swap(array + j, array + j - 1);
				print_array(array, size);
				swapped = 1;
			}
		}
		n--;
		if (!swapped)
			break;
	}
}