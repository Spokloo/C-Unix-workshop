void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

unsigned array_min(const int arr[], unsigned start, unsigned size)
{
    unsigned min = start;
    for (unsigned i = start + 1; i < size; i++)
    {
        if (arr[i] < arr[min])
        {
            min = i;
        }
    }

    return min;
}

void selection_sort(int arr[], unsigned size)
{
    if (size == 0)
    {
        return;
    }

    for (unsigned i = 0; i < size - 1; i++)
    {
        unsigned min = array_min(arr, i + 1, size);
        if (arr[i] > arr[min])
        {
            swap(&arr[i], &arr[min]);
        }
    }
}
