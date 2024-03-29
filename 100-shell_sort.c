#include "sort.h"

/**
 * shell_sort - sort an array of integers using the shell sort
 *
 * @array: array to sort
 * @size: size of the array
 *
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i, j;
	int temp;

	if (!array || size < 2)
		return;

	while (gap < size)
	{
		gap = (gap * 3) + 1;
	}
	gap = (gap - 1) / 3;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;
			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
