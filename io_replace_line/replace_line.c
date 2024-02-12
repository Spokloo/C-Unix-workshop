#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>

int replace_line(const char *file_in, const char *file_out, const char *content,
                 int n)
{
    FILE *f1 = fopen(file_in, "r");
    FILE *f2 = fopen(file_out, "w");
    if (!f1 || !f2)
        return -1;

    char *line;
    int count = 0;
    size_t size = 0;
    ssize_t l = 1;
    while (l != -1)
    {
        l = getline(&line, &size, f1);
        if (l == -1)
            break;

        if (count == n)
        {
            int put = fputs(content, f2);
            if (put == EOF)
                return -1;
        }
        else
        {
            int put = fputs(line, f2);
            if (put == EOF)
                return -1;
        }

        count++;
    }

    free(line);

    if (fclose(f1) == -1 || fclose(f2) == -1)
        return -1;

    if (count < n)
        return 1;
    return 0;
}
