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
