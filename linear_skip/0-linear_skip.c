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
	skiplist_t *current = head, *last = head;

	if (!head)
		return (NULL);

	/* First search through express lane */
	while (current)
	{
		last = current;

		if (!current->express)
		{
			while (current->next)
				current = current->next;

			break;
		}

		current = current->express;

		printf("Value checked at index [%li] = [%i]\n", current->index, current->n);

		if (current->n >= value)
			break;
	}

	printf("Value found between indexes [%li] and [%li]\n", last->index, current->index);

	upper = current->index;
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
