#include "my_strcasecmp.h"

#include <stddef.h>

int my_strcasecmp(const char *s1, const char *s2)
{
    size_t i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        char s1_tmp = s1[i];
        char s2_tmp = s2[i];

        if (s1[i] >= 'A' && s1[i] <= 'Z')
        {
            s1_tmp = s1[i] + 'a' - 'A';
        }

        if (s2[i] >= 'A' && s2[i] <= 'Z')
        {
            s2_tmp = s2[i] + 'a' - 'A';
        }

        if (s1_tmp != s2_tmp)
        {
            return s1_tmp - s2_tmp;
        }

        i++;
    }

    return s1[i] - s2[i];
}
