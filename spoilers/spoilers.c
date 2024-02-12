#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int read_file(char *path)
{
    int fd = open(path, O_RDONLY);
    if (fd == -1)
    {
        write(STDERR_FILENO, "Could not open file\n", 20);
        return 1;
    }

    char buf[1024];
    ssize_t r = read(fd, buf, sizeof(buf));
    int size = r;
    while (r != 0)
    {
        r = read(fd, buf, sizeof(buf));
        size += r;
    }

    char disp[3];
    disp[2] = '\n';

    int n = 1;
    int i = size - 1;
    while (n >= 0 && i > 0)
    {
        if (buf[i] != ' ' && buf[i] != '\f' && buf[i] != '\r' && buf[i] != '\n'
            && buf[i] != '\t' && buf[i] != '\v')
        {
            disp[n] = buf[i];
            n--;
        }
        i--;
    }

    if (n >= 0)
    {
        write(STDERR_FILENO, "File is not long enough\n", 24);
        return 1;
    }

    write(STDOUT_FILENO, disp, 3);
    int c = close(fd);
    if (c == -1)
    {
        return 1;
    }

    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write(STDERR_FILENO, "Invalid number of arguments\n", 28);
        return 1;
    }

    int c = read_file(argv[1]);
    return c;
}
