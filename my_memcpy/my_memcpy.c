#include "my_memcpy.h"

void *my_memcpy(void *dest, const void *source, size_t num)
{
    char *dest_tmp = dest;
    const char *src_tmp = source;

    for (size_t i = 0; i < num; i++)
    {
        dest_tmp[i] = src_tmp[i];
    }

    return dest;
}
