#include "my_strspn.h"

int is_in_alphabet(char c, const char *accept)
{
    for (size_t i = 0; accept[i] != '\0'; i++)
    {
        if (c == accept[i])
        {
            return 1;
        }
    }

    return 0;
}

size_t my_strspn(const char *s, const char *accept)
{
    size_t len = 0;

    size_t i = 0;
    while (s[i] != '\0' && is_in_alphabet(s[i], accept))
    {
        len++;
        i++;
    }

    return len;
}
