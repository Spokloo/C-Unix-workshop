int binary_search(const int vec[], int size, int elt)
{
    int min = 0;
    int max = size - 1;

    while (min <= max)
    {
        int mid = min + (max - min) / 2;

        if (elt == vec[mid])
        {
            return mid;
        }

        if (elt > vec[mid])
        {
            min = mid + 1;
        }

        if (elt < vec[mid])
        {
            max = mid - 1;
        }
    }

    return -1;
}
