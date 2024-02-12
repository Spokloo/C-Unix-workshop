#include <stdio.h>

#include "heap.h"

static void print_rec(const struct heap *heap, size_t i)
{
    printf("%d", heap->array[i]);

    if (2 * i + 1 < heap->size)
    {
        printf(" ");
        print_rec(heap, 2 * i + 1);
    }

    if (2 * i + 2 < heap->size)
    {
        printf(" ");
        print_rec(heap, 2 * i + 2);
    }
}

void print_heap(const struct heap *heap)
{
    if (heap->size == 0)
    {
        return;
    }

    print_rec(heap, 0);
    printf("\n");
}
