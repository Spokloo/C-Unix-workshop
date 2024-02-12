#include "str_revert.h"

#include <stddef.h>

void str_revert(char str[])
{
    size_t len = 0;
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        len++;
    }

    if (len == 0)
    {
        return;
    }

    size_t i = 0;
    size_t j = len - 1;

    while (i < j)
    {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;

        i++;
        j--;
    }
}
