#include "hash_map.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hash_map *hash_map_init(size_t size)
{
    struct hash_map *hash_map = malloc(sizeof(struct hash_map));
    if (!hash_map)
    {
        return NULL;
    }

    hash_map->size = size;
    hash_map->data = malloc(sizeof(struct pair_list) * size);
    if (!hash_map->data)
    {
        return NULL;
    }

    for (size_t i = 0; i < size; i++)
    {
        hash_map->data[i] = NULL;
    }

    return hash_map;
}

bool hash_map_insert(struct hash_map *hash_map, const char *key, char *value,
                     bool *updated)
{
    if (!hash_map || hash_map->size == 0)
    {
        return false;
    }

    size_t h = hash(key) % hash_map->size;
    struct pair_list *new_hash = malloc(sizeof(struct pair_list));
    if (!new_hash)
    {
        return false;
    }

    new_hash->key = key;
    new_hash->value = value;
    new_hash->next = NULL;

    struct pair_list *hashed = hash_map->data[h];
    if (!hashed)
    {
        hash_map->data[h] = new_hash;
        if (updated)
            *updated = false;
        return true;
    }

    struct pair_list *tmp = hashed;
    while (tmp->next && strcmp(tmp->key, key) != 0)
    {
        tmp = tmp->next;
    }

    if (strcmp(tmp->key, key) == 0)
    {
        tmp->value = value;
        if (updated)
            *updated = true;

        free(new_hash);
        return true;
    }

    new_hash->next = hash_map->data[h];
    hash_map->data[h] = new_hash;
    if (updated)
        *updated = false;
    return true;
}

void hash_map_free(struct hash_map *hash_map)
{
    if (!hash_map)
    {
        return;
    }

    for (size_t i = 0; i < hash_map->size; i++)
    {
        if (hash_map->data[i])
        {
            struct pair_list *tmp = hash_map->data[i];

            while (tmp)
            {
                struct pair_list *tmp2 = tmp;
                tmp = tmp->next;
                free(tmp2);
            }
        }
    }

    free(hash_map->data);
    free(hash_map);
}

void hash_map_dump(struct hash_map *hash_map)
{
    if (!hash_map)
    {
        return;
    }

    for (size_t i = 0; i < hash_map->size; i++)
    {
        if (hash_map->data[i])
        {
            struct pair_list *tmp = hash_map->data[i];
            printf("%s: %s", tmp->key, tmp->value);

            tmp = tmp->next;
            while (tmp)
            {
                printf(", %s: %s", tmp->key, tmp->value);
                tmp = tmp->next;
            }

            printf("\n");
        }
    }
}

const char *hash_map_get(const struct hash_map *hash_map, const char *key)
{
    if (!hash_map || hash_map->size == 0)
    {
        return NULL;
    }

    size_t h = hash(key) % hash_map->size;
    struct pair_list *tmp = hash_map->data[h];
    if (!tmp)
    {
        return NULL;
    }

    while (tmp->next && strcmp(tmp->key, key) != 0)
    {
        tmp = tmp->next;
    }

    if (strcmp(tmp->key, key) == 0)
    {
        return tmp->value;
    }

    return NULL;
}

bool hash_map_remove(struct hash_map *hash_map, const char *key)
{
    if (!hash_map || hash_map->size == 0)
    {
        return false;
    }

    size_t h = hash(key) % hash_map->size;
    struct pair_list *prev = hash_map->data[h];
    struct pair_list *tmp = hash_map->data[h];

    if (!tmp)
    {
        return false;
    }

    while (tmp->next && strcmp(tmp->key, key) != 0)
    {
        prev = tmp;
        tmp = tmp->next;
    }

    if (strcmp(tmp->key, key) == 0)
    {
        if (tmp == prev)
        {
            hash_map->data[h] = tmp->next;
        }
        else
        {
            prev->next = tmp->next;
        }

        free(tmp);
        return true;
    }

    return false;
}
