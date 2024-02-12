#include <stdio.h>

int pine(unsigned n)
{
    if (n < 3)
    {
        return 1;
    }

    unsigned int trunk = n / 2;

    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = 0; j < n + i; j++)
        {
            if (j >= n - i - 1)
            {
                putchar('*');
            }
            else
            {
                putchar(' ');
            }
        }

        putchar('\n');
    }

    for (unsigned int i = 0; i < trunk; i++)
    {
        for (unsigned int j = 0; j < n; j++)
        {
            if (j == n - 1)
            {
                putchar('*');
            }
            else
            {
                putchar(' ');
            }
        }

        putchar('\n');
    }

    return 0;
}
