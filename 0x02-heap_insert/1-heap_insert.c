#include "binary_trees.h"

779 Bytes

#include "binary_trees.h"

	/**
	 * binary_tree_is_leaf - checks if a node is a leaf
	 *
	 * @node: Node to check
	 * Return: int
	 */
	int
	binary_tree_is_leaf(const binary_tree_t *node)
{

	if (node != NULL && node->right == NULL && node->left == NULL)
		return (1);
	return (0);
}

/**
 * binary_tree_height - measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_count = 0, right_count = 0;

	if (tree == NULL || binary_tree_is_leaf(tree))
		return (0);

	left_count = binary_tree_height(tree->left);
	right_count = binary_tree_height(tree->right);
	if (right_count >= left_count)
		return (1 + right_count);
	return (1 + left_count);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap:
 * @root: double pointer to the root node of the Heap.
 * @value: value to store in the node to be inserted.
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;
}
