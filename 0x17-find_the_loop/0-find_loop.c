#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: pointer to the first node in the singly linked list to check
 * Return: The address of the node where the loop starts,
 * or NULL if there is no loop
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *turtle = head, *hare = head;

	if (head == NULL || head->next == NULL)
		return (NULL);
	while (hare->next != NULL && hare->next->next != NULL)
	{
		turtle = turtle->next;
		hare = hare->next->next;
		if (turtle == hare)
		{
			turtle = head;
			while (hare != NULL)
			{
				if (turtle == hare)
					return (turtle);
				turtle = turtle->next;
				hare = hare->next;
			}
		}
	}
	return (NULL);
}
