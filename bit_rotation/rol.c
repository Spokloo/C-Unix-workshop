unsigned char rol(unsigned char value, unsigned char roll)
{
    for (int i = 0; i < roll; i++)
    {
        unsigned char test = 1 << (sizeof(unsigned char) * 8 - 1);
        unsigned char mask = (value & test) == 0 ? 0 : 1;
        value = (value << 1) | mask;
    }

    return value;
}
