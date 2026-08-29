#include "binary_trees.h"

/**
 * sorted_array_to_avl - creates an AVL tree from a sorted array
 * @array: sorted array
 * @size: size of the array
 *
 * Return: pointer to the root node
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	binary_tree_t *root;
	binary_tree_t *node;

	if (!array)
		return (NULL);

	root = malloc(sizeof(binary_tree_t));

	if (!root)
		return (NULL);

	root->n = 0;
	root->parent = NULL;
	root->left = NULL;
	root->right = NULL;

	node = split_insert(root, array, size, true);

	if (!node)
		return (NULL);

	return (root);
}

/**
 * insert_node - inserts a node in a binary tree
 * @root: pointer to the root node
 * @x: value to insert
 * @first: first call
 *
 * Return: pointer to the inserted node
 */
avl_t *insert_node(binary_tree_t *root, int x, bool first)
{
	binary_tree_t *parent, *child;

	/* Root case */
	if (first)
	{
		root->n = x;
		return (root);
	}

	parent = root;

	child = malloc(sizeof(binary_tree_t));

	if (!child)
		return (NULL);

	child->n = x;
	child->left = NULL;
	child->right = NULL;

	/* Find position of parent to insert value for the child */
	while ((x < parent->n && parent->left) || (x > parent->n && parent->right))
	{
		if (x < parent->n)
			parent = parent->left;
		else
			parent = parent->right;
	}

	child->parent = parent;

	/* Insert new node */
	if (x < parent->n)
		parent->left = child;
	else
		parent->right = child;

	return (child);
}

/**
 * split_insert - insert center value and split array for recursion
 * @root: pointer to the root node
 * @array: full array
 * @size: size of the array
 * @first: first call
 *
 * Return: pointer to the root node
 */
avl_t *split_insert(binary_tree_t *root, int *array, size_t size, bool first)
{
	avl_t *node, *verification;
	int size_left = (size - 1) / 2;
	int size_right = (size - 1) - size_left;
	int center_value;

	if (!size)
		return (root);

	if (size == 1)
	{
		node = insert_node(root, array[0], first);

		if (!node)
			return (NULL);

		return (root);
	}

	center_value = array[size_left];
	node = insert_node(root, center_value, first);

	if (!node)
		return (NULL);

	if (size_left)
	{
		verification = split_insert(root, array, size_left, false);
		if (!verification)
			return (NULL);
	}

	if (size_right)
	{
		verification = split_insert(root, &array[size_left + 1], size_right, false);
		if (!verification)
			return (NULL);
	}

	return (root);
}
