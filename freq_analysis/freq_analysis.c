#include <stddef.h>
#include <stdio.h>

size_t get_max(int occ[], size_t size)
{
    size_t max = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (occ[i] > occ[max])
        {
            max = i;
        }
    }

    return max;
}

void get_ranking(int occ[], char *s, size_t size)
{
    size_t len = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (occ[i] > 0)
        {
            len++;
        }
    }

    for (size_t i = 0; i < len; i++)
    {
        size_t max = get_max(occ, size);
        occ[max] = -occ[max];
        s[i] = max + 'A';
    }
}

void freq_analysis(const char text[], const char table[])
{
    size_t size = 26;
    int occ[26] = { 0 };

    for (size_t i = 0; text[i] != '\0'; i++)
    {
        size_t index = text[i] - 'A';
        occ[index]++;
    }

    char s[27] = { '\0' };
    get_ranking(occ, s, size);
    size_t s_len = 0;
    for (size_t i = 0; s[i] != '\0'; i++)
    {
        s_len++;
    }

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < s_len; j++)
        {
            char ciphered = i + 'A';
            if (ciphered == s[j])
            {
                char original = table[j];

                printf("%c %c\n", ciphered, original);
            }
        }
    }
}
