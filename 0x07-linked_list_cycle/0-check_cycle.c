#include "lists.h"

/**
 * check_cycle-If there is a cycle, the fast pointer will eventually
 * catch up to the slow pointer
 *
 * @list: the head of the linked list
 *
 * Return: 1 if is a cycle 0 if not.
 */
int check_cycle(listint_t *list)
{
	listint_t *slow, *fast;

	if (list == NULL)
		return (0);

	slow = list;

	fast = list->next;

	while (fast != NULL && fast->next != NULL)
	{
		if (slow == fast)
			return (1);
		slow = slow->next;
		fast = fast->next->next;
	}

	return (0);
}
