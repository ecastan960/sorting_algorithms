#include "sort.h"
/**
 * insertion_sort_list - Doubly linked list node
 *
 * @list: Integer stored in the node
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = *list;
	listint_t *head = *list;

	if (*list == NULL || list == NULL || (*list)->next == NULL)
		return;

	while ((*list)->next != NULL)
	{
		while ((*list)->next->n < (*list)->n)
		{
			tmp = (*list)->next;
			(*list)->next = (*list)->next->next;
			if ((*list)->prev != NULL)
			{
				(*list)->prev->next = tmp;
				tmp->prev = (*list)->prev;
				(*list)->prev = tmp;
			}
			else
			{
				tmp->prev = NULL;
				(*list)->prev = tmp;
				head = tmp;
			}
			if ((*list)->next != NULL)
			{
				(*list)->next->prev = *list;
				tmp->next = *list;
			}
			else
				tmp->next = *list;
			print_list(head);
			if (tmp->prev != NULL)
				*list = tmp->prev;
			else
				*list = tmp;
		}
		(*list) = (*list)->next;
	}
	*list = head;
}
