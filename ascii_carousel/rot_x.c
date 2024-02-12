#include <stddef.h>

void rot_x(char *s, int x)
{
    if (!s)
    {
        return;
    }

    while (x < 0)
    {
        x += 26;
    }

    for (size_t i = 0; s[i] != '\0'; i++)
    {
        char c = s[i];
        if (c >= 'a' && c <= 'z')
        {
            c = (c - 'a' + x) % 26 + 'a';
        }
        else if (c >= 'A' && c <= 'Z')
        {
            c = (c - 'A' + x) % 26 + 'A';
        }

        s[i] = c;
    }
}
