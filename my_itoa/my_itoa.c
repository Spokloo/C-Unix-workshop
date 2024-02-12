#include "my_itoa.h"

#include <stddef.h>

char *my_itoa(int value, char *s)
{
    if (value == 0)
    {
        s[0] = '0';
        s[1] = '\0';
        return s;
    }

    size_t i = 0;

    if (value < 0)
    {
        s[0] = '-';
        i++;
        value = -value;
    }

    while (value > 0)
    {
        int r = value % 10;
        value /= 10;

        s[i] = r + '0';
        i++;
    }

    size_t len = i;
    i = s[0] == '-';
    size_t j = len - 1;

    while (i < j)
    {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;

        i++;
        j--;
    }

    s[len] = '\0';
    return s;
}
