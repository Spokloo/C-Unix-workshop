#include "my_atoi.h"

int my_atoi(const char *str)
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
    while (i < len && str[i] >= '0' && str[i] <= '9')
    {
        i++;
    }

    if (i != len)
    {
        return 0;
    }

    int res = 0;
    for (size_t k = j; k < len; k++)
    {
        int n = str[k] - '0';
        res = res * 10 + n;
    }

    return res * sign;
}
