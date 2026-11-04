#include "binary_trees.h"

/**
 * heap_extract - ...
 * @root: pointer to the root node
 *
 * Return: ...
 */
int heap_extract(heap_t **root)
{
	int value = (*root)->n;
	heap_t *last = find_last(root);
	heap_t *current = *root;
	heap_t *child = NULL;

	/* Swap root node and last node values */
	swap_values(*root, last);

	/* Free last node */
	if (last->parent)
	{
		if (last->parent->left == last)
			last->parent->left = NULL;
		else
			last->parent->right = NULL;
	}

	free(last);

	/* Move new root down */
	child = find_child(current);

	while (child)
	{
		swap_values(current, child);

		current = child;
		child = find_child(current);
	}

	return (value);
}

/**
 * swap_values - swap values of two given nodes
 * @a: first node
 * @b: second node
 */
void swap_values(heap_t *a, heap_t *b)
{
	int temp;

	temp = a->n;
	a->n = b->n;
	b->n = temp;
}

/**
 * find_last - find the last node in level-order
 * @root: pointer to the root node
 *
 * Return: pointer to the node
 */
heap_t *find_last(heap_t **root)
{
	heap_t *parents[512] = {NULL};
	heap_t *children[512] = {NULL};
	heap_t *last = NULL;
	int i = 0, j = 0;

	if (!*root)
		return (NULL);
	parents[0] = *root;
	while (true)
	{
		i = 0;
		j = 0;
		while (parents[i])
		{
			if (parents[i]->left)
			{
				children[j] = parents[i]->left;
				last = children[j++];
			}
			else
				return (last);

			if (parents[i]->right)
			{
				children[j] = parents[i]->right;
				last = children[j++];
			}
			else
				return (last);
			i++;
		}
		i = 0;
		while (children[i])
		{
			parents[i] = children[i];
			i++;
		}
		parents[i] = NULL;
	}
	return (NULL);
}

/**
 * find_child - find the child node with highest value
 * @current: pointer to the current node
 *
 * Return: pointer to the child node
 */
heap_t *find_child(heap_t *current)
{
	if (current->left)
	{
		if (current->right)
		{
			if (current->left->n > current->right->n)
				return (current->left);

			return (current->right);
		}

		return (current->left);
	}

	return (NULL);
}
