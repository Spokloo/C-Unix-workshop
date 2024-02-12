#include "bst_static.h"

#include <stddef.h>
#include <stdlib.h>

struct bst *init(size_t capacity)
{
    struct bst *bst = malloc(sizeof(struct bst));
    if (!bst)
        return NULL;

    bst->size = 0;
    bst->capacity = capacity;
    bst->data = malloc(sizeof(struct value *) * bst->capacity);
    if (!bst->data)
        return NULL;

    for (size_t i = 0; i < bst->capacity; i++)
        bst->data[i] = NULL;

    return bst;
}

static size_t get_ind(struct bst *tree, size_t i, int value)
{
    if (i > tree->capacity || !tree->data[i])
        return i;

    if (tree->data[i]->val >= value)
        return get_ind(tree, 2 * i + 1, value);

    return get_ind(tree, 2 * i + 2, value);
}

void add(struct bst *tree, int value)
{
    if (!tree)
        return;

    struct value *elm = malloc(sizeof(struct value));
    if (!elm)
        return;

    elm->val = value;
    size_t i = get_ind(tree, 0, value);

    if (i > tree->capacity)
    {
        tree->data = realloc(tree->data, sizeof(struct value *) * (i + 1));
        if (!tree->data)
            return;

        for (size_t j = tree->capacity; j < i + 1; j++)
            tree->data[j] = NULL;
        tree->capacity = i + 1;
    }

    tree->data[i] = elm;
    tree->size++;
}

int search(struct bst *tree, int value)
{
    if (!tree)
        return -1;

    for (size_t i = 0; i < tree->capacity; i++)
    {
        if (tree->data[i] && tree->data[i]->val == value)
            return i;
    }

    return -1;
}

void bst_free(struct bst *tree)
{
    if (!tree)
        return;

    for (size_t i = 0; i < tree->capacity; i++)
    {
        if (tree->data[i])
            free(tree->data[i]);
    }

    free(tree->data);
    free(tree);
}
