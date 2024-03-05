#include "sort.h"

/**
 * insertion_sort_list - sort list via insertion sort
 *
 * @list: pointer to the head of the list
 *
 * Return: NOthing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ptr, *tmp, *p;

	if (!list || !(*list)->next)
		return;

	ptr = (*list)->next;
	while (ptr)
	{
		tmp = ptr->prev;
		p = ptr;
		while (tmp && tmp->n > p->n)
		{
			if (p->next)
				p->next->prev = tmp;
			tmp->next = p->next;

			if (!tmp->prev)
				*list = p;
			else
				tmp->prev->next = p;

			p->prev = tmp->prev;
			tmp->prev = p;
			p->next = tmp;

			print_list(*list);
			tmp = p->prev;
		}

		ptr = ptr->next;
	}
}
