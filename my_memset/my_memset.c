#include "my_memset.h"

void *my_memset(void *s, int c, size_t n)
{
    char *s_tmp = s;

    size_t i = 0;
    while (i < n)
    {
        s_tmp[i] = c;
        i++;
    }

    return s;
}
