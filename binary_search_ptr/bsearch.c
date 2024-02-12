#include "bsearch.h"

int *binary_search(int *begin, int *end, int elt)
{
    if (begin == end)
    {
        return begin;
    }

    end--;

    while (begin <= end)
    {
        int *mid = begin + (end - begin) / 2;

        if (elt == *mid)
        {
            return mid;
        }

        if (elt > *mid)
        {
            begin = mid + 1;
        }

        if (elt < *mid)
        {
            end = mid - 1;
        }
    }

    return begin;
}
