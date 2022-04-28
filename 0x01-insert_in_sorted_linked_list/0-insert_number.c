#include "lists.h"
/**
 * insert_node - inserts a number into a sorted singly linked list.
 *
 * @head: the head of the list
 * @number: the number to insert
 * Return: listint_t*
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *current = *head;
    listint_t *newNode;

    newNode = malloc(sizeof(listint_t));
    /* Testing fail in node creation */
    if (newNode == NULL)
        return (NULL);
    newNode->n = number;

    if (*head == NULL)
    {
        *(head) = newNode;
        return (newNode);
    }
    while (current->next != NULL)
    {
        if (current->n <= number && current->next->n >= number)
        {
            newNode->next = current->next;
            current->next = newNode;
            return (newNode);
        }
        if (newNode->n <= current->n)
        {
            newNode->next = current;
            return (newNode);
        }
        current = current->next;
    }
    return (NULL);
}
