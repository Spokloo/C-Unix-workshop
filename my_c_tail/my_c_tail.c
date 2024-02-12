#include "my_c_tail.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void free_lines(char **lines, int size)
{
    for (int i = 0; i <= size; i++)
    {
        free(lines[i]);
    }

    free(lines);
}

void write_output(char **lines, unsigned int nb_lines, unsigned int n)
{
    for (unsigned int i = nb_lines - n; i < nb_lines; i++)
    {
        for (unsigned int j = 0; lines[i][j] != '\0'; j++)
        {
            ssize_t w = write(STDOUT_FILENO, &lines[i][j], 1);
            if (w == -1)
            {
                return;
            }
        }

        char c = '\n';
        ssize_t w = write(STDOUT_FILENO, &c, 1);
        if (w == -1)
        {
            return;
        }
    }
}

void stdintail(unsigned int n)
{
    char buf[1] = { '\0' };
    ssize_t r = read(STDIN_FILENO, buf, sizeof(buf));
    if (r == -1)
    {
        return;
    }

    unsigned int nb_lines = 0;
    int size = 0;
    char **lines = malloc(sizeof(char *));
    lines[0] = malloc(sizeof(char));

    while (r != 0)
    {
        if (buf[0] == '\n')
        {
            lines[nb_lines][size] = '\0';

            size = 0;
            nb_lines++;
            lines = realloc(lines, sizeof(char *) * (nb_lines + 1));
            lines[nb_lines] = malloc(sizeof(char));
        }
        else
        {
            size++;
            lines[nb_lines] = realloc(lines[nb_lines], size + 1);
            lines[nb_lines][size - 1] = buf[0];
        }

        r = read(STDIN_FILENO, buf, sizeof(buf));
    }

    if (nb_lines < n)
    {
        n = nb_lines;
    }

    write_output(lines, nb_lines, n);
    free_lines(lines, nb_lines);
}
