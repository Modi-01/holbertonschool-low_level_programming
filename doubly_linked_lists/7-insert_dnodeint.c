#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: double pointer to the head of the list
 * @idx: index where the new node should be added (starting from 0)
 * @n: value to store in the new node
 *
 * Return: address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node;
	dlistint_t *temp;
	unsigned int i = 0;

	if (h == NULL)
		return (NULL);

	/* إدراج في البداية */
	if (idx == 0)
		return (add_dnodeint(h, n));

	/* القائمة غير فاضية ونبغى موقع داخلها أو في نهايتها */
	temp = *h;
	while (temp != NULL && i < idx - 1)
	{
		temp = temp->next;
		i++;
	}

	/* لو وصلنا للنهاية قبل الوصول للموقع المطلوب → index غير صالح */
	if (temp == NULL)
		return (NULL);

	/* إدراج في النهاية تمامًا */
	if (temp->next == NULL && i == idx - 1)
		return (add_dnodeint_end(h, n));

	/* إدراج في المنتصف بين temp و temp->next */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = temp;
	new_node->next = temp->next;

	if (temp->next != NULL)
		temp->next->prev = new_node;

	temp->next = new_node;

	return (new_node);
}
