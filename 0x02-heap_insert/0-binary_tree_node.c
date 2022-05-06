#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node
 * @parent: pointer to the parent node.
 * @value: value to set in the new node
 * Return: Pointer to the newly created node and Null if failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));

	if (!new_node)
		return (NULL);

	new_node->parent = parent;
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;

	if (parent == NULL)
		return (new_node);

	if ((parent->left) == NULL)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (new_node);
}
