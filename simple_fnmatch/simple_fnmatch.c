#include "simple_fnmatch.h"

int length(const char *str)
{
    int size = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        size++;
    }

    return size;
}

int simple_fnmatch_rec(const char *pattern, const char *string, int i, int j)
{
    int size_p = length(pattern);
    int size_s = length(string);
    int escape = 0;

    while (i < size_p && j < size_s)
    {
        if (!escape && pattern[i] == '*')
        {
            i++;
            while (string[j] != '\0'
                   && simple_fnmatch_rec(pattern, string, i, j) != 0)
            {
                j++;
            }
        }
        else if (!escape && pattern[i] == '?')
        {
            i++;
            j++;
        }
        else if (!escape && pattern[i] == '\\')
        {
            escape = 1;
            i++;
        }
        else
        {
            if (pattern[i] != string[j])
                return FNM_NOMATCH;

            i++;
            j++;
            escape = 0;
        }
    }

    if (i == size_p && j < size_s)
        return FNM_NOMATCH;
    if (i < size_p && j == size_s)
    {
        while (i < size_p && pattern[i] == '*')
            i++;

        return i < size_p;
    }

    return 0;
}

int simple_fnmatch(const char *pattern, const char *string)
{
    return simple_fnmatch_rec(pattern, string, 0, 0);
}
