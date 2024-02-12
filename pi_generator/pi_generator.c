double pi_generator(int precision)
{
    if (precision <= 0)
    {
        return 2;
    }

    double pi = 1;
    for (double i = precision; i > 0; i--)
    {
        pi = 1 + (i / (i * 2 + 1)) * pi;
    }

    return pi * 2;
}
