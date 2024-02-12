#include "levenshtein.h"

#include <stddef.h>

size_t min(size_t a, size_t b, size_t c)
{
    if (a <= b && a <= c)
    {
        return a;
    }
    else if (b <= a && b <= c)
    {
        return b;
    }
    else
    {
        return c;
    }
}

size_t lev(const char *s1, const char *s2, size_t i, size_t j)
{
    if (i == 0 || j == 0)
    {
        return i > j ? i : j;
    }

    size_t a = lev(s1, s2, i - 1, j) + 1;
    size_t b = lev(s1, s2, i, j - 1) + 1;
    size_t c = lev(s1, s2, i - 1, j - 1) + (s1[i - 1] != s2[j - 1]);

    return min(a, b, c);
}

size_t levenshtein(const char *s1, const char *s2)
{
    size_t s1_len = 0;
    for (size_t i = 0; s1[i] != '\0'; i++)
    {
        s1_len++;
    }

    size_t s2_len = 0;
    for (size_t i = 0; s2[i] != '\0'; i++)
    {
        s2_len++;
    }

    return lev(s1, s2, s1_len, s2_len);
}
