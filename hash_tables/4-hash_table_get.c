#include <string.h>
#include "hash_tables.h"

/**
 * hash_table_get - Retrieves the value associated with a key
 * @ht: Pointer to the hash table
 * @key: Key string to look for
 *
 * Return: Pointer to the value associated with the key,
 *         or NULL if the key could not be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *node;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
		return (NULL);

	node = ht->array[index];

	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}

	return (NULL);
}
