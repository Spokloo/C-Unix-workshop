unsigned int digit(int n, int k)
{
    if (n <= 0 || k <= 0)
    {
        return 0;
    }

    int r = 0;
    while (k > 0)
    {
        r = n % 10;
        n /= 10;
        k--;
    }

    return r;
}
