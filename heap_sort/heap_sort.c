#include "heap_sort.h"

static void swap(int *array, int i, int j)
{
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

static void max_heapify(int *array, size_t size, size_t i)
{
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;
    size_t max = i;

    if (left < size && array[left] > array[max])
    {
        max = left;
    }

    if (right < size && array[right] > array[max])
    {
        max = right;
    }

    if (max != i)
    {
        swap(array, i, max);
        max_heapify(array, size, max);
    }
}

void heapify(int *array, size_t size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        max_heapify(array, size, i);
    }
}

void heap_sort(int *array, size_t size)
{
    heapify(array, size);

    for (int i = size - 1; i >= 0; i--)
    {
        swap(array, 0, i);
        max_heapify(array, i, 0);
    }
}
