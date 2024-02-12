#include "my_strtok_r.h"

#include <stddef.h>

int is_delimiter(char c, const char *delim)
{
    for (size_t i = 0; delim[i] != '\0'; i++)
    {
        if (delim[i] == c)
        {
            return 1;
        }
    }

    return 0;
}

char *my_strtok_r(char *str, const char *delim, char **saveptr)
{
    if (!str)
    {
        str = *saveptr;
    }

    size_t i = 0;

    if (str[0] == '\0')
    {
        *saveptr = str;
        return NULL;
    }

    while (str[i] != '\0')
    {
        if (!is_delimiter(str[i], delim))
        {
            break;
        }

        i++;
    }

    if (str[i] == '\0')
    {
        *saveptr = str;
        return NULL;
    }

    size_t j = i;
    char *start = str + j;
    while (str[i] != '\0')
    {
        if (is_delimiter(str[i], delim))
        {
            break;
        }

        i++;
    }

    if (str[i] == '\0')
    {
        *saveptr = str + i;
        return start;
    }

    start[i - j] = '\0';
    *saveptr = str + i + 1;
    return start;
}
