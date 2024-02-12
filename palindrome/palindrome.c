#include "palindrome.h"

#include <stddef.h>

int is_alphanumeric(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        return 1;
    }

    if (c >= '0' && c <= '9')
    {
        return 1;
    }

    return 0;
}

int palindrome(const char *s)
{
    if (!s)
    {
        return 0;
    }

    size_t len = 0;
    for (size_t i = 0; s[i] != '\0'; i++)
    {
        len++;
    }

    if (len == 0)
    {
        return 1;
    }

    size_t i = 0;
    size_t j = len - 1;

    while (i < j)
    {
        if (!is_alphanumeric(s[i]))
        {
            i++;
        }
        else if (!is_alphanumeric(s[j]))
        {
            j--;
        }
        else if (s[i] != s[j])
        {
            return 0;
        }
        else
        {
            i++;
            j--;
        }
    }

    return 1;
}
