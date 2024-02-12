#include <stdio.h>

void hanoi_main(int d, int from, int to, int tmp)
{
    if (d > 0)
    {
        hanoi_main(d - 1, from, tmp, to);
        printf("%d->%d\n", from, to);
        hanoi_main(d - 1, tmp, to, from);
    }
}

void hanoi(unsigned n)
{
    hanoi_main(n, 1, 3, 2);
}
