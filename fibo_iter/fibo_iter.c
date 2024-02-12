unsigned long fibo_iter(unsigned long n)
{
    unsigned long u0 = 0;
    unsigned long u1 = 1;

    if (n <= 1)
    {
        return n;
    }

    for (unsigned long i = 2; i <= n; i++)
    {
        unsigned long tmp = u0;
        u0 = u1;
        u1 = tmp + u1;
    }

    return u1;
}
