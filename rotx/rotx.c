#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        return 0;
    }

    char buf[1] = { '\0' };
    ssize_t r = read(STDIN_FILENO, buf, sizeof(buf));
    if (r == -1)
    {
        return 1;
    }

    while (r != 0)
    {
        char c = buf[0];
        int x = atoi(argv[1]);

        if (c >= 'a' && c <= 'z')
        {
            while (x < 0)
            {
                x += 26;
            }

            c = (c - 'a' + x) % 26 + 'a';
        }
        else if (c >= 'A' && c <= 'Z')
        {
            while (x < 0)
            {
                x += 26;
            }

            c = (c - 'A' + x) % 26 + 'A';
        }
        else if (c >= '0' && c <= '9')
        {
            while (x < 0)
            {
                x += 10;
            }

            c = (c - '0' + x) % 10 + '0';
        }

        buf[0] = c;
        ssize_t w = write(STDOUT_FILENO, buf, sizeof(buf));
        if (w == -1)
        {
            return 1;
        }

        r = read(STDIN_FILENO, buf, sizeof(buf));
    }

    return 0;
}
