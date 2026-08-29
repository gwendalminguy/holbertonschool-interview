#include <stdio.h>
#include <stdlib.h>
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

    root = malloc(sizeof(binary_tree_t));

    if (!root)
        return NULL;

    node = split_insert(root, array, size);

    if (!node)
        return (NULL);

    return (root);
}

/**
 * insert_node - inserts a node in a binary tree
 * @root: pointer to the root node
 * @value: value to insert
 *
 * Return: pointer to the inserted node
 */
avl_t *insert_node(binary_tree_t *root, int value)
{
    binary_tree_t *parent;
    binary_tree_t *child;

    /* Root case */
    if (!root->n)
    {
        root->n = value;

        return (root);
    }

    parent = root;

    child = malloc(sizeof(binary_tree_t));

    if (!child)
        return NULL;

    child->n = value;

    /* Find position of parent to insert value for the child */
    while ((value < parent->n && parent->left) || (value > parent->n && parent->right))
    {
        if (value < parent->n)
        {
            parent = parent->left;
        }
        else
        {
            parent = parent->right;
        }
    }

    child->parent = parent;

    /* Insert new node */
    if (value < parent->n)
    {
        parent->left = child;
    }
    else
    {
        parent->right = child;
    }

    return (child);
}

/**
 * split_insert - insert center value and split array for recursion
 * @root: pointer to the root node
 * @array: full array
 * @size: size of the array
 *
 * Return: pointer to the root node
 */
avl_t *split_insert(binary_tree_t *root, int *array, size_t size)
{
    avl_t *node, *verification;
    int size_right = (size - 1) / 2;
    int size_left = (size - 1) - size_right;
    int center_value;

    if (!size)
        return (root);

    if (size == 1)
    {
        node = insert_node(root, array[0]);

        if (!node)
            return (NULL);

        return (root);
    }

    center_value = array[size_left];

    node = insert_node(root, center_value);

    if (!node)
        return (NULL);

    if (size_left)
    {
        verification = split_insert(root, array, size_left);

        if (!verification)
            return (NULL);
    }

    if (size_right)
    {
        verification = split_insert(root, &array[size_left + 1], size_right);

        if (!verification)
            return (NULL);
    }

    return (root);
}
