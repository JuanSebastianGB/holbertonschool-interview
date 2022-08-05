#include "search.h"

/**
 * linear_skip - linear skip search algorithm
 *
 * @list: head of the linked list
 * @value: value to search for
 * Return: the node where the value is found, or NULL if not found
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *temporal_node, *express_node;

	express_node = temporal_node = list;

	if (list == NULL)
		return (NULL);
	while (express_node->express != NULL)
	{
		temporal_node = express_node;
		express_node = express_node->express;
		printf("Value checked at index [%ld] = [%d]\n",
			   express_node->index, express_node->n);

		if (express_node->n >= value || !express_node->express)
		{
			if (!express_node->express && express_node->n < value)
			{
				temporal_node = express_node;
				while (express_node->next)
					express_node = express_node->next;
			}
			printf("Value found between indexes [%ld] and [%ld]\n",
				   temporal_node->index,
				   express_node->index);
			while (temporal_node != express_node)
			{
				printf("Value checked at index [%ld] = [%d]\n",
					   temporal_node->index, temporal_node->n);
				if (temporal_node->n == value)
					return (temporal_node);
				temporal_node = temporal_node->next;
			}
			if (express_node->n < value)
				printf("Value checked at index [%ld] = [%d]\n",
					   temporal_node->index, temporal_node->n);
			return (NULL);
		}
	}
	return (NULL);
}
