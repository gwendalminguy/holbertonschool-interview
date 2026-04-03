#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: head of the list
 * @number: number to insert
 *
 * Return: pointer to newly created node
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current = *head;
	listint_t *prev = *head;
	listint_t *new;

	new = malloc(sizeof(listint_t));
	new->n = number;

	/* Checking if list is empty. */
	if (!head)
	{
		*head = new;
		return *head;
	}

	/* Walking the list until position found. */
	while (current && current->n < number)
	{
		prev = current;
		current = current->next;
	}

	/* Linking previous node to new one. */
	if (current == *head)
		*head = new;
	else
		prev->next = new;

	/* Linking new node to next one. */
	new->next = current;

	return new;
}
