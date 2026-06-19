#include "lists.h"

int is_seen(listint_t **array, listint_t *node);

/**
 * check_cycle - checks wether a linked list contains a cycle or not
 * @list: linked list to check
 *
 * Return: 1 if it contains a cycle ; 0 otherwise
 */
int check_cycle(listint_t *list)
{
	listint_t *current_all = list;
	listint_t *current_half = list;
	int i = 0;

	while (current_all)
	{
		/* Moving current_all at every iteration */
		current_all = current_all->next;

		if (current_all == current_half)
			return 1;

		/* Moving current_half once in two iterations */
		if (i % 2 == 1)
			current_half = current_half->next;

		i++;
	}

	return 0;
}
