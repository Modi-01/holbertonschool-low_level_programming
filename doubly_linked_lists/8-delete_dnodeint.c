#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at a given index of a
 *                            dlistint_t linked list
 * @head: double pointer to the head of the list
 * @index: index of the node that should be deleted (starting from 0)
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	temp = *head;

	/* delete the head node */
	if (index == 0)
	{
		*head = temp->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}

	/* move temp to the node at position index */
	while (temp != NULL && i < index)
	{
		temp = temp->next;
		i++;
	}

	/* index is out of range */
	if (temp == NULL)
		return (-1);

	/* relink previous and next nodes */
	if (temp->prev != NULL)
		temp->prev->next = temp->next;

	if (temp->next != NULL)
		temp->next->prev = temp->prev;

	free(temp);

	return (1);
}
