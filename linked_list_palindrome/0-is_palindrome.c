#include <stdio.h>
#include <stddef.h>
#include "lists.h"

/**
 * is_palindrome - determines wheter a linked list is a palindrome or not
 * @head: pointer to pointer of first node of listint_t list
 *
 * Return: 1 if the list is a palindrome ; 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t *current;
	int length = get_length(head);
	int is_even = length % 2 == 0;
	int copy[length / 2];
	int i = 0;

	current = *head;

	if (!current)
		return (1);

	/* Copying first half of linked list */
	while (i != length / 2)
	{
		copy[i] = current->n;

		current = current->next;
		i++;
	}

	i--;

	/* Skipping irrelevant middle value if list length is odd */
	if (!is_even)
		current = current->next;

	/* Checking if second half of list matches copied values in array */
	while (current)
	{
		if (current->n != copy[i])
			return (0);

		current = current->next;
		i--;
	}

	return (1);
}

/**
 * get_length - finds out number of nodes in linked list
 * @head: pointer to pointer of first node of listint_t list
 *
 * Return: number of nodes
 */
int get_length(listint_t **head)
{
	listint_t *current;
	int length = 0;

	current = *head;

	while (current)
	{
		length++;
		current = current->next;
	}

	return (length);
}
