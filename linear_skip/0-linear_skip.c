#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 *
 * @head: pointer to the head of the list
 * @value: value to search for
 *
 * Return: ...
 */
skiplist_t *linear_skip(skiplist_t *head, int value)
{
	size_t upper;
	skiplist_t *current, *last;

	if (!head)
		return (NULL);

	last = head;
	current = head;

	/* First search through express lane */
	while (current)
	{
		last = current;
		current = current->express;

		if (current)
		{
			printf("Value checked at index [%li] = [%i]\n", current->index, current->n);

			if (current->n >= value)
			{
				upper = current->index;
				break;
			}
		}
	}

	printf("Value found between indexes ");
	printf("[%li] and [%li]\n", last->index, current->index);

	current = last;

	/* Second search through normal lane */
	while (current && current->index <= upper)
	{
		printf("Value checked at index [%li] = [%i]\n", current->index, current->n);

		if (current->n == value)
			return (current);

		current = current->next;
	}

	return (NULL);
}
