#include "binary_trees.h"

/**
 * sorted_array_to_avl - It takes a sorted array and turns it into a
 * balanced binary tree
 *
 * @array: a pointer to the first element of the array to be converted
 * @size: the size of the array
 *
 * Return: A pointer to the root node of the created AVL tree.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree;
	size_t mid;

	if (size == 0)
		return (NULL);
	tree = malloc(sizeof(avl_t));
	if (tree == NULL)
		return (NULL);
	mid = (size - 1) / 2;
	tree->n = array[mid];
	tree->parent = NULL;
	tree->left = sorted_array_to_avl(array, mid);
	if (tree->left != NULL)
		tree->left->parent = tree;
	tree->right = sorted_array_to_avl(array + mid + 1, size - mid - 1);
	if (tree->right != NULL)
		tree->right->parent = tree;
	return (tree);
}
