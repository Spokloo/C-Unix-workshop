#include "hill_array.h"

int top_of_the_hill(int tab[], size_t len)
{
    if (len == 0)
    {
        return -1;
    }

    if (len == 1)
    {
        return 0;
    }

    size_t i = 0;
    int hill_max = tab[0];
    int hill = 0;

    while (i < len - 1 && tab[i] <= tab[i + 1])
    {
        if (tab[i] < 0)
        {
            return -1;
        }

        i++;

        if (tab[i] > hill_max)
        {
            hill_max = tab[i];
            hill = i;
        }
    }

    while (i < len - 1 && tab[i] >= tab[i + 1])
    {
        if (tab[i] < 0)
        {
            return -1;
        }

        i++;
    }

    if (i != len - 1)
    {
        return -1;
    }

    return hill;
}
