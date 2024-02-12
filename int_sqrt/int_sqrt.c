int int_sqrt(int n)
{
    if (n < 0)
    {
        return -1;
    }

    if (n <= 1)
    {
        return n;
    }

    int i = 1;
    int res = 1;
    for (i = 1; i < n; i++)
    {
        if (i * i > n)
        {
            res = i;
            break;
        }
    }

    return res - 1;
}
