#include "my_memcmp.h"

int my_memcmp(const void *s1, const void *s2, size_t num)
{
    if (num == 0)
        return 0;

    const char *s1_tmp = s1;
    const char *s2_tmp = s2;

    size_t i = 0;
    while (i < num)
    {
        if (s1_tmp[i] != s2_tmp[i])
        {
            int res = s1_tmp[i] - s2_tmp[i];
            return res;
        }

        i++;
    }

    return s1_tmp[i] - s2_tmp[i];
}
