#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - merge array
 *
 * @array: array of integer
 * @start: start index
 * @end: end index
 * @sorted: sorted array
 */
void merge(int *array, int start, int end, int *sorted)
{
	int i = start, j, k, mid;

	j = mid = (start + end) / 2;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, end - mid);
	for (k = start; k < end; k++)
		if (i < mid && (j >= end || array[i] <= array[j]))
			sorted[k] = array[i++];
		else
			sorted[k] = array[j++];
	printf("[Done]: ");
	print_array(sorted + start, end - start);

}

/**
 * mergeSort - merge sort algo
 *
 * @array: array to sort
 * @start: index left
 * @end: index right
 * @sorted: sorted array
 *
 */
void mergeSort(int *array, int start, int end, int *sorted)
{
	int mid;

	mid = (start + end) / 2;
	if (end - start < 2)
		return;
	mergeSort(sorted, start, mid, array);
	mergeSort(sorted, mid, end, array);
	merge(array, start, end, sorted);
}

/**
 * merge_sort - sort an array of integers with merge sort
 *
 * @array: array of integers
 * @size: size of the array
 *
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	int *sorted;
	int i;

	if (!array || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return;
	for (i = 0; i < (int) size; i++)
		sorted[i] = array[i];
	mergeSort(sorted, 0, size, array);
	free(sorted);
}
