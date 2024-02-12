#include <stdlib.h>

#include "heap.h"

static void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

static void heapify(struct heap *heap, size_t i)
{
    if (i == 0)
    {
        return;
    }

    if (heap->array[i] > heap->array[(i - 1) / 2])
    {
        swap(&heap->array[i], &heap->array[(i - 1) / 2]);
        heapify(heap, (i - 1) / 2);
    }
}

void add(struct heap *heap, int val)
{
    if (heap->size == heap->capacity)
    {
        heap->capacity *= 2;
        heap->array = realloc(heap->array, sizeof(int) * heap->capacity);
        if (!heap->array)
        {
            return;
        }
    }

    size_t i = heap->size;
    heap->array[i] = val;
    heapify(heap, i);

    heap->size++;
}
