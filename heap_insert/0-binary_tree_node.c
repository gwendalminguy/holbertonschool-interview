#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - inserts a node into a binary tree
 * @parent: pointer to the parent of the node to create
 * @value: value for the new node
 *
 * Return: pointer to newly created node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));

	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	if (new == NULL)
		return (NULL);

	return (new);
}
