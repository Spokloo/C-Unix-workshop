#include "dlist.h"

unsigned int min(size_t a, size_t b, size_t c)
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

unsigned int lev(struct dlist *l1, struct dlist *l2, size_t i, size_t j)
{
    if (i == 0 || j == 0)
    {
        return i > j ? i : j;
    }

    int eq = dlist_get(l1, i - 1) != dlist_get(l2, j - 1);
    size_t a = lev(l1, l2, i - 1, j) + 1;
    size_t b = lev(l1, l2, i, j - 1) + 1;
    size_t c = lev(l1, l2, i - 1, j - 1) + eq;
    return min(a, b, c);
}

unsigned int dlist_levenshtein(struct dlist *list1, struct dlist *list2)
{
    return lev(list1, list2, list1->size, list2->size);
}
