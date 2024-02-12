#include "my_itoa_base.h"

#include <stddef.h>

char get_char(size_t n, const char *base, size_t base_len)
{
    for (size_t i = 0; i < base_len; i++)
    {
        if (i == n)
        {
            return base[i];
        }
    }

    return '\0';
}

char *my_itoa_base(int n, char *s, const char *base)
{
    if (n == 0)
    {
        s[0] = base[0];
        s[1] = '\0';
        return s;
    }

    size_t i = 0;

    if (n < 0)
    {
        s[0] = '-';
        i++;
        n = -n;
    }

    size_t base_len = 0;
    for (size_t k = 0; base[k] != '\0'; k++)
    {
        base_len++;
    }

    while (n > 0)
    {
        size_t r = n % base_len;
        n /= base_len;

        s[i] = get_char(r, base, base_len);
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
