#include "insertion_sort.h"

#include <stddef.h>

void insertion_sort(void **array, f_cmp comp)
{
    if (!array || !array[0])
        return;

    for (int i = 1; array[i]; i++)
    {
        for (int j = i; j > 0; j--)
        {
            int c = comp(array[j], array[j - 1]);
            if (c < 0)
            {
                void *tmp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = tmp;
            }
        }
    }
}
