#include <assert.h>
#include <stdlib.h>

#include "heap.h"

static void swap2(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

static void max_heapify(struct heap *heap, size_t i)
{
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;
    size_t max = i;

    if (left <= heap->size && heap->array[left] > heap->array[max])
    {
        max = left;
    }

    if (right <= heap->size && heap->array[right] > heap->array[max])
    {
        max = right;
    }

    if (max != i)
    {
        swap2(&heap->array[i], &heap->array[max]);
        max_heapify(heap, max);
    }
}

int pop(struct heap *heap)
{
    assert(heap->size != 0);

    int x = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    max_heapify(heap, 0);

    if (heap->size < heap->capacity / 2)
    {
        if (heap->capacity / 2 >= 8)
        {
            heap->capacity /= 2;
        }

        heap->array = realloc(heap->array, sizeof(int) * heap->capacity);
        if (!heap->array)
        {
            return -1;
        }
    }

    return x;
}
