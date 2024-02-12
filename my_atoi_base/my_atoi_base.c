#include "my_atoi_base.h"

#include <stddef.h>

int is_in_base(const char *base, char c)
{
    for (size_t i = 0; base[i] != '\0'; i++)
    {
        if (base[i] == c)
        {
            return 1;
        }
    }

    return 0;
}

int get_num(char c, const char *base, size_t base_len)
{
    for (size_t i = 0; i < base_len; i++)
    {
        if (base[i] == c)
        {
            return i;
        }
    }

    return -1;
}

int my_atoi_base(const char *str, const char *base)
{
    if (!str || str[0] == '\0')
    {
        return 0;
    }

    size_t len = 0;
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        len++;
    }

    size_t i = 0;
    while (i < len && str[i] == ' ')
    {
        i++;
    }

    int sign = 1;
    if (i < len)
    {
        if (str[i] == '+')
        {
            sign = 1;
            i++;
        }
        else if (str[i] == '-')
        {
            sign = -1;
            i++;
        }
    }

    size_t j = i;
    while (i < len && is_in_base(base, str[i]))
    {
        i++;
    }

    if (i != len)
    {
        return 0;
    }

    size_t base_len = 0;
    for (size_t k = 0; base[k] != '\0'; k++)
    {
        base_len++;
    }

    int res = 0;
    for (size_t k = j; k < len; k++)
    {
        int n = get_num(str[k], base, base_len);
        res = res * base_len + n;
    }

    return res * sign;
}
