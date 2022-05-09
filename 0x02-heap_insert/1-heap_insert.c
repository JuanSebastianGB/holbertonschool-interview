#include "binary_trees.h"

/**
 * tree_height - FUnction that gets the height of a binary tree
 * @tree: Root of the binary tree
 * Return: height of a binary tree
 */
int tree_height(const binary_tree_t *tree)
{
	int left_side = 0, right_side = 0;

	if (!tree)
		return (0);

	left_side = tree_height(tree->left);
	right_side = tree_height(tree->right);
	if (left_side > right_side)
		return (left_side + 1);
	return (right_side + 1);
}

/**
 * tree_is_perfect - checks if a binary tree is perfectly balanced
 * @tree: root node of the binary tree
 * Return: 1 if perfect,  otherwise 0
 */
int tree_is_perfect(const binary_tree_t *tree)
{
	_Bool check_left_child, check_right_childs;

	if (tree && tree_height(tree->left) == tree_height(tree->right))
	{
		if (tree_height(tree->left) == 0)
			return (1);

		check_left_child = tree->left && !((tree->left)->left) &&
						   !((tree->left)->right);
		check_right_childs = tree->right && !((tree->right)->left) &&
							 !((tree->right)->right);

		if (check_left_child && check_right_childs)
			return (1);

		if (tree && tree->left && tree->right)
			return (tree_is_perfect(tree->left) && tree_is_perfect(tree->right));
	}

	return (0);
}

/**
 * swap_node_parent_and_child - swaps nodes when node is lower than its child
 * @args_node: parent node
 * @args_child: child node
 * Return: no return
 */
void swap_node_parent_and_child(heap_t **args_node, heap_t **args_child)
{
	heap_t *node, *child, *node_child, *node_left, *node_right, *parent;
	int left_right;

	node = *args_node, child = *args_child;
	if (node->n < child->n)
	{
		if (child->left)
			child->left->parent = node;
		if (child->right)
			child->right->parent = node;
		if (node->left == child)
			node_child = node->right, left_right = 0;
		else
			node_child = node->left, left_right = 1;
		node_left = child->left, node_right = child->right;
		if (!left_right)
		{
			child->right = node_child;
			if (node_child)
				node_child->parent = child;
			child->left = node;
		}
		else
		{
			child->left = node_child;
			if (node_child)
				node_child->parent = child;
			child->right = node;
		}
		if (node->parent)
		{
			if (node->parent->left == node)
				node->parent->left = child;
			else
				node->parent->right = child;
		}
		parent = node->parent, child->parent = parent;
		node->parent = child, node->left = node_left;
		node->right = node_right, *args_node = child;
	}
}

/**
 * heap_insert - function that inserts a value(node) in Binary Heap
 * @value: value to insert
 * @root: root node
 * Return: pointer to the new node. If fails then NULL.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	if (tree_is_perfect(*root) || !tree_is_perfect((*root)->left))
	{
		if ((*root)->left)
		{
			new_node = heap_insert(&((*root)->left), value);
			swap_node_parent_and_child(root, &((*root)->left));
			return (new_node);
		}
		new_node = (*root)->left = binary_tree_node(*root, value);
		swap_node_parent_and_child(root, &((*root)->left));
		return (new_node);
	}

	if ((*root)->right)
	{
		new_node = heap_insert(&((*root)->right), value);
		swap_node_parent_and_child(root, (&(*root)->right));
		return (new_node);
	}
	new_node = (*root)->right = binary_tree_node(*root, value);
	swap_node_parent_and_child(root, &((*root)->right));
	return (new_node);
}
