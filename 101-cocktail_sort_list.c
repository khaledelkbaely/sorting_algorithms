#include "sort.h"

/**
 * swapp_list - swap two nodes
 *
 * @list: pointer to the head of the list
 * @node1: first node
 * @node2: second node
 *
 * Return: Nothing
 */
void swapp_list(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node2->next)
		node2->next->prev = node1;
	node1->next = node2->next;

	if (!node1->prev)
		*list = node2;
	else
		node1->prev->next = node2;

	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
	print_list(*list);
}

/**
 * cocktail_sort_list - sort doubly linked list of integers
 *
 * @list: pointer to the head of the linked list
 *
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *ptr, *start, *end;

	if (!list || !(*list) || !(*list)->next)
		return;

	end = start = *list;
	while (swapped)
	{
		swapped = 0;
		ptr = start;
		while (ptr->next)
		{
			if (ptr->n > ptr->next->n)
			{
				swapp_list(list, ptr, ptr->next);
				swapped = 1;
			}
			else
				if (ptr->next)
					ptr = ptr->next;
		}
		end = ptr->prev;
		ptr = end;
		while (ptr->prev)
		{
			if (ptr->n < ptr->prev->n)
			{
				swapp_list(list, ptr->prev, ptr);
				swapped = 1;
			}
			else
				if (ptr->prev)
					ptr = ptr->prev;
		}
		start = start->next;
	}
}
