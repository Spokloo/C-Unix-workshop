#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

struct vector *vector_init(size_t n)
{
    struct vector *v = malloc(sizeof(struct vector));
    if (!v)
    {
        return NULL;
    }

    v->size = 0;
    v->capacity = n;
    v->data = malloc(sizeof(int) * v->capacity);
    if (!v->data)
    {
        return NULL;
    }

    return v;
}

void vector_destroy(struct vector *v)
{
    free(v->data);
    free(v);
}

struct vector *vector_resize(struct vector *v, size_t n)
{
    if (n == v->capacity)
    {
        return v;
    }

    if (n < v->capacity)
    {
        v->size = n;
    }

    v->capacity = n;
    v->data = realloc(v->data, sizeof(int) * v->capacity);
    if (!v->data)
    {
        return NULL;
    }

    return v;
}

struct vector *vector_append(struct vector *v, int elt)
{
    if (!v)
    {
        return NULL;
    }

    if (v->capacity == v->size)
    {
        v = vector_resize(v, 2 * v->capacity);
        if (!v)
        {
            return NULL;
        }
    }

    v->data[v->size] = elt;
    v->size++;
    return v;
}

void vector_print(const struct vector *v)
{
    if (!v || v->size == 0)
    {
        printf("\n");
        return;
    }

    for (size_t i = 0; i < v->size - 1; i++)
    {
        printf("%d,", v->data[i]);
    }

    printf("%d\n", v->data[v->size - 1]);
}

struct vector *vector_reset(struct vector *v, size_t n)
{
    for (size_t i = 0; i < v->size; i++)
    {
        v->data[i] = 0;
    }

    v = vector_resize(v, n);
    if (!v)
    {
        return NULL;
    }

    v->size = 0;
    return v;
}

struct vector *vector_insert(struct vector *v, size_t i, int elt)
{
    if (!v)
    {
        return NULL;
    }

    if (i == v->size)
    {
        v = vector_append(v, elt);
        return v;
    }

    if (i > v->size)
    {
        return NULL;
    }

    if (v->capacity == v->size)
    {
        v = vector_resize(v, 2 * v->capacity);
        if (!v)
        {
            return NULL;
        }
    }

    for (size_t j = v->size; j > i; j--)
    {
        v->data[j] = v->data[j - 1];
    }

    v->data[i] = elt;
    v->size++;
    return v;
}

struct vector *vector_remove(struct vector *v, size_t i)
{
    if (!v)
    {
        return NULL;
    }

    if (i >= v->size)
    {
        return NULL;
    }

    if (v->capacity / 2 > v->size - 1)
    {
        v = vector_resize(v, v->capacity / 2);
        if (!v)
        {
            return NULL;
        }
    }

    for (size_t j = i; j < v->size - 1; j++)
    {
        v->data[j] = v->data[j + 1];
    }

    v->size--;
    return v;
}
