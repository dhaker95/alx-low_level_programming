#include "hash_tables.h"

/**
 * hash_table_delete - function that deletes a hash table
 * @ht: pointer to hash table
 *
 * Return: void
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t **array = NULL;
	hash_node_t *seeker = NULL;
	hash_node_t *next = NULL;
	size_t i = 0;

	/* check if ht is NULL return */
	if (!ht)
		return;

	array = ht->array;

	/* loop through indices of array for non-NULL */
	while (i < ht->size)
	{
		if (array[i])
		{
			/* valid pointer found */
			seeker = array[i];
			while (seeker)
			{
				next = seeker->next;
				free(seeker->key);
				free(seeker->value);
				free(seeker);
				seeker = next;
			}
		}
		i++;
	}
	free(array);
	free(ht);

}
