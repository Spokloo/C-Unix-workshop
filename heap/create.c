#include <stdlib.h>

#include "heap.h"

struct heap *create_heap(void)
{
    struct heap *heap = malloc(sizeof(struct heap));
    if (!heap)
    {
        return NULL;
    }

    heap->size = 0;
    heap->capacity = 8;
    heap->array = malloc(sizeof(int) * heap->capacity);
    if (!heap->array)
    {
        return NULL;
    }

    return heap;
}
