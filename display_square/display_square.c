#include <stdio.h>

void display_square(int width)
{
    if (width <= 0)
    {
        return;
    }

    if (width == 1)
    {
        putchar('*');
        putchar('\n');
        return;
    }

    if (width % 2 == 0)
    {
        width++;
    }

    int rows = (width + 1) / 2;

    for (int j = 0; j < width; j++)
    {
        putchar('*');
    }
    putchar('\n');

    for (int i = 1; i < rows - 1; i++)
    {
        putchar('*');

        for (int j = 1; j < width - 1; j++)
        {
            putchar(' ');
        }
        putchar('*');
        putchar('\n');
    }

    for (int j = 0; j < width; j++)
    {
        putchar('*');
    }
    putchar('\n');
}
