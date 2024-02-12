#include <stddef.h>

int *swap(int *tab, int i, int j)
{
    int tmp = tab[i];
    tab[i] = tab[j];
    tab[j] = tmp;

    return tab;
}

int partition(int *tab, int begin, int end)
{
    int pivot = tab[end];
    int i = begin - 1;

    for (int j = begin; j <= end - 1; j++)
    {
        if (tab[j] <= pivot)
        {
            tab = swap(tab, ++i, j);
        }
    }

    tab = swap(tab, ++i, end);
    return i;
}

void quick_rec(int *tab, int begin, int end)
{
    if (begin >= end || begin < 0)
    {
        return;
    }

    int i = partition(tab, begin, end);

    quick_rec(tab, begin, i - 1);
    quick_rec(tab, i + 1, end);
}

void quicksort(int *tab, int len)
{
    if (!tab)
    {
        return;
    }

    quick_rec(tab, 0, len - 1);
}
