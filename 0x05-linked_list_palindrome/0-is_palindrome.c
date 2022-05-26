#include "lists.h"

/**
 * check_list_at_same_time - Compares first with las node, and after
 * from let to right and at the same time from right to left
 * @left: left node
 * @right: right node
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */

int check_list_at_same_time(listint_t **left, listint_t *right)
{
	int result;

	/* Break point*/
	if (!right)
		return (1);

	result = check_list_at_same_time(left, right->next) && right->n == (*left)->n;
	*left = (*left)->next;

	return (result);
}

/**
 * is_palindrome - Checks if a given linked list is a palindrome
 * @head: Double pointer to head of list
 * Return: 1 if is a palindrome, otherwise 0
 */

int is_palindrome(listint_t **head)
{
	listint_t *deref = *head;

	return (check_list_at_same_time(&deref, deref));
}
