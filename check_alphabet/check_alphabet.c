#include "check_alphabet.h"

#include <stddef.h>

int check_alphabet(const char *str, const char *alphabet)
{
    if (!alphabet || alphabet[0] == '\0')
    {
        return 1;
    }

    size_t len = 0;
    for (size_t i = 0; alphabet[i] != '\0'; i++)
    {
        len++;
    }

    size_t n = 0;
    for (size_t i = 0; alphabet[i] != '\0'; i++)
    {
        for (size_t j = 0; str[j] != '\0'; j++)
        {
            if (alphabet[i] == str[j])
            {
                n++;
                break;
            }
        }
    }

    if (n == len)
    {
        return 1;
    }

    return 0;
}
