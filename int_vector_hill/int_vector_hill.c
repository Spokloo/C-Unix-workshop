#include "int_vector_hill.h"

int int_vector_hill(struct int_vector vec)
{
    if (vec.size == 0)
    {
        return -1;
    }

    if (vec.size == 1)
    {
        return 0;
    }

    size_t i = 0;
    int hill_max = vec.data[0];
    int hill = 0;

    if (vec.data[vec.size - 1] < 0)
    {
        return -1;
    }

    while (i < vec.size - 1 && vec.data[i] <= vec.data[i + 1])
    {
        if (vec.data[i] < 0)
        {
            return -1;
        }

        i++;

        if (vec.data[i] > hill_max)
        {
            hill_max = vec.data[i];
            hill = i;
        }
    }

    while (i < vec.size - 1 && vec.data[i] >= vec.data[i + 1])
    {
        if (vec.data[i] < 0)
        {
            return -1;
        }

        i++;
    }

    if (i != vec.size - 1)
    {
        return -1;
    }

    return hill;
}
