#include "list.h"

/**
 * create_new_node - take memory to store a new node
 * @str: the string to copy into the new node
 * Return: a new List node, NULL otherwise
 */
List *create_new_node(char *str)
{
	List *node = NULL;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);

	node->str = strdup(str);
	node->prev = NULL;
	node->next = NULL;

	if (str && !node->str)
	{
		free(node);
		return (NULL);
	}

	return (node);
}


/**
 * add_node_end - Add a new node to the end of a
 * double circular linked list
 * @list: the list to modify
 * @str: the string to store in the new node
 * Return: new node address, or NULL if fails
 */
List *add_node_end(List **list, char *str)
{
	List *node = NULL, *tail = NULL, *head = NULL;

	if (!list)
		return (NULL);

	node = create_new_node(str);
	if (!node)
		return (NULL);

	head = *list;
	if (!head)
	{
		node->next = node;
		node->prev = node;
		*list = node;
	}
	else
	{
		tail = head->prev;
		node->next = head;
		tail->next = node;
		node->prev = tail;
		head->prev = node;
	}

	return (node);
}

/**
 * add_node_begin - Add a new node to the beginning of a
 * double circular linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *node = NULL;

	node = add_node_end(list, str);
	if (!node)
		return (NULL);

	*list = node;
	return (node);
}
