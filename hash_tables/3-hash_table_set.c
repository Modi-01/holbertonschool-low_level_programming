#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * hash_table_set - Adds an element to a hash table
 * @ht: Pointer to the hash table
 * @key: Key string (can not be an empty string)
 * @value: Value associated with the key (will be duplicated)
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *node, *tmp;
	char *key_copy, *value_copy;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];

	/* If key already exists, update its value */
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			value_copy = strdup(value);
			if (value_copy == NULL)
				return (0);

			free(tmp->value);
			tmp->value = value_copy;
			return (1);
		}
		tmp = tmp->next;
	}

	/* Key does not exist: create a new node */
	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (0);

	key_copy = strdup(key);
	if (key_copy == NULL)
	{
		free(node);
		return (0);
	}

	value_copy = strdup(value);
	if (value_copy == NULL)
	{
		free(key_copy);
		free(node);
		return (0);
	}

	node->key = key_copy;
	node->value = value_copy;

	/* add at the beginning of the list (collision handling) */
	node->next = ht->array[index];
	ht->array[index] = node;

	return (1);
}
