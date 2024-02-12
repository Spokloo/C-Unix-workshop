#include "int_vector_vice_max.h"

int int_vector_vice_max(const struct int_vector vec)
{
    int max = vec.data[0];
    int vice_max = vec.data[1];

    if (max < vice_max)
    {
        max = vec.data[1];
        vice_max = vec.data[0];
    }

    for (size_t i = 2; i < vec.size; i++)
    {
        if (vec.data[i] > max)
        {
            int tmp = max;
            max = vec.data[i];
            vice_max = tmp;
        }
        else if (vec.data[i] > vice_max)
        {
            vice_max = vec.data[i];
        }
    }

    return vice_max;
}
