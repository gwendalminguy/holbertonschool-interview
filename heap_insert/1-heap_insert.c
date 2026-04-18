#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binary_trees.h"

/**
 * heap_insert - inserts a node into a max binary heap
 * @root: pointer to the root node of the max binary heap
 * @value: value for the new node
 *
 * Return: pointer to newly created node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;
	heap_t *parent;

	new = malloc(sizeof(heap_t));

	if (new == NULL)
		return (NULL);

	new->n = value;
	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;

	/* Finding new node inserting position */
	parent = find_position(root);

	if (!parent)
	{
		*root = new;
		return (new);
	}

	/* Inserting new node */
	if (!parent->left)
	{
		parent->left = new;
		new->parent = parent;
	}
	else
	{
		parent->right = new;
		new->parent = parent;
	}

	/* Swapping new node's value with its parent's while necessary */
	while (parent->n < new->n)
	{
		new = swap_values(parent, new);
		parent = new->parent;

		if (!parent)
		{
			*root = new;
			break;
		}
	}

	return (new);
}

/**
 * find_position - find insertion position (first NULL in levelorder)
 * @root: pointer to the root node of the max binary heap
 *
 * Return: pointer to parent node
 */
heap_t *find_position(heap_t **root)
{
	heap_t *parents[512] = {NULL};
	heap_t *children[512] = {NULL};
	int i = 0, j = 0;

	if (!*root)
		return (NULL);

	parents[0] = *root;

	while (true)
	{
		i = 0;
		j = 0;

		/* Collecting children until NULL is found */
		while (parents[i])
		{
			if (parents[i]->left)
			{
				children[j] = parents[i]->left;
				j++;
			}
			else
				return (parents[i]);

			if (parents[i]->right)
			{
				children[j] = parents[i]->right;
				j++;
			}
			else
				return (parents[i]);

			i++;
		}

		i = 0;

		/* Switching children to parents */
		while (children[i])
		{
			parents[i] = children[i];
			i++;
		}

		parents[i] = NULL;
	}
}

/**
 * swap_values - swap a node's value with its parent's
 * @parent: pointer to the parent node
 * @child: pointer to the child node
 *
 * Return: pointer to parent node
 */
heap_t *swap_values(heap_t *parent, heap_t *child)
{
	int temp;

	temp = parent->n;
	parent->n = child->n;
	child->n = temp;

	return (parent);
}
