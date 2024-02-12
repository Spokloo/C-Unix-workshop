#include <stdio.h>

int main(void)
{
    int i = 'a';
    for (i = 'a'; i < 'z'; i++)
    {
        char c = i;
        putchar(c);
        putchar(' ');
    }

    char c = i;
    putchar(c);
    putchar('\n');

    return 0;
}
