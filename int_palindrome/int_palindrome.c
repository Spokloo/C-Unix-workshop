int int_palindrome(int n)
{
    if (n < 0)
    {
        return 0;
    }

    int r = 0;
    int rev = 0;
    int tmp = n;

    while (n > 0)
    {
        r = n % 10;
        rev = (10 * rev) + r;
        n /= 10;
    }

    if (rev == tmp)
    {
        return 1;
    }

    return 0;
}
