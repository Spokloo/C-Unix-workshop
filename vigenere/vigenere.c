#include "vigenere.h"

#include <stddef.h>

char to_upper(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        c -= 'a' - 'A';
    }

    return c;
}

size_t get_length(const char *str)
{
    size_t len = 0;
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        len++;
    }

    return len;
}

void cipher(const char *key, const char *msg, char *res)
{
    size_t len = get_length(msg);
    size_t j = 0;
    for (size_t i = 0; i < len; i++)
    {
        char c1 = to_upper(msg[i]);
        char c2 = to_upper(key[j]);

        if (c1 >= 'A' && c1 <= 'Z')
        {
            if (c2 == '\0')
            {
                j = 0;
                c2 = to_upper(key[j]);
            }

            res[i] = (c1 + c2 - 2 * 'A') % 26 + 'A';

            j++;
        }
        else
        {
            res[i] = c1;
        }
    }
}

void decipher(const char *key, const char *msg, char *res)
{
    size_t len = get_length(msg);
    size_t j = 0;
    for (size_t i = 0; i < len; i++)
    {
        char c1 = to_upper(msg[i]);
        char c2 = to_upper(key[j]);

        if (c1 >= 'A' && c1 <= 'Z')
        {
            if (c2 == '\0')
            {
                j = 0;
                c2 = to_upper(key[j]);
            }

            int x = c1 - c2 - 2 * 'A';
            while (x < 0)
            {
                x += 26;
            }

            res[i] = x % 26 + 'A';

            j++;
        }
        else
        {
            res[i] = c1;
        }
    }
}
