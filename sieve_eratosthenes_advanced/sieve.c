#include <stdio.h>
#include <stdlib.h>

void sieve(int n)
{
    if (n <= 2)
    {
        return;
    }

    int *arr = calloc(n - 1, sizeof(int));
    int count = 0;

    for (int i = 2; i * i <= n; i++)
    {
        if (!arr[i - 2])
        {
            for (int j = i * i; j <= n; j += i)
            {
                arr[j - 2] = 1;
            }
        }
    }

    for (int i = 2; i < n; i++)
    {
        if (!arr[i - 2])
        {
            count++;
        }
    }

    printf("%d\n", count);
    free(arr);
}
