unsigned int greatest_divisor(unsigned int n)
{
    unsigned int max = 1;
    for (unsigned int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            max = i;
        }
    }

    return max;
}
