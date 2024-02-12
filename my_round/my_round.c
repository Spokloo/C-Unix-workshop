int my_round(float n)
{
    int r = n;
    float d = n - r;

    if (d >= 0)
    {
        if (d < 0.5)
        {
            return r;
        }
        else
        {
            return r + 1;
        }
    }
    else
    {
        if (d > -0.5)
        {
            return r;
        }
        else
        {
            return r - 1;
        }
    }
}
