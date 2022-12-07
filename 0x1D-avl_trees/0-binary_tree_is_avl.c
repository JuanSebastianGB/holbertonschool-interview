#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: A binary tree.
 * Return: return the height of the binary tree.
 */
int binary_tree_height(const binary_tree_t *tree)
{
	int height_left, height_right;

	if (!tree || (!tree->left && !tree->right))
		return (0);

	height_left = binary_tree_height(tree->left);
	height_right = binary_tree_height(tree->right);

	if (height_left > height_right)
		return (height_left + 1);
	else
		return (height_right + 1);
}

/**
 * helper - help function
 * @tree: - tree
 * @low: low node
 * @hig: hig node
 *
 * Return: 1 or 0
 */
int helper(const binary_tree_t *tree, int low, int hig)
{
	if (!tree)
		return (0);

	if (low > tree->n || hig < tree->n)
		return (0);

	return (helper(tree->left, low, tree->n - 1) &&
			helper(tree->right, tree->n + 1, hig));

	return (1);
}

/**
 * binary_tree_is_bst - function that checks if a binary tree
 * is a valid Binary Search Tree
 * @tree:  a pointer to the root node of the tree to check
 *
 * Return: value reurned by helper function
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int num = 1;

	if (!tree)
		return (0);

	return (helper(tree, num, num));
}

/**
 * binary_tree_is_avl - check if a binary tree is a valid AVL tree
 * @tree: pointer to root node of tree
 * Return: 1 or 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int lh, rh;

	if (tree == NULL)
		return (0);

	lh = binary_tree_height(tree->left);
	rh = binary_tree_height(tree->right);

	if (abs(lh - rh) <= 1)
		return (binary_tree_is_bst(tree));

	return (0);
}
