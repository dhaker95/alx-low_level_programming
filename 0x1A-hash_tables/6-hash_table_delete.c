#include "hash_tables.h"
/**
 * hash_table_set - this function adds an element to the hash table
 * @ht: the hash table that a new eement will be added
 * @key: the key for the new element
 * @value: the value for the new element
 *
 * Return: On success, it returns 1. On error, it returns 0, and errno * is set appropriately
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    unsigned long int hash_code;
    hash_node_t *new = NULL, *aux;
    if (!key || ht == NULL)
        return (0);
    new = create_node(key, value);
    if (new == NULL)
        return (0);
    hash_code = key_index((unsigned char *)key, ht->size);
    if (ht->array[hash_code] == NULL)
    {
        ht->array[hash_code] = new;
        new->next = NULL;
        return (1);
    }
    aux = ht->array[hash_code];
    while (aux != NULL)
    {
        if (strcmp(aux->key, key) == 0)
        {
            free(aux->value);
            aux->value = strdup(value);
            free(new->key);
            free(new->value);
            free(new);
            return (1);
        }
    }
    aux = aux->next;

new->next = ht->array[hash_code];
ht->array[hash_code] = new;
return (1);
}
