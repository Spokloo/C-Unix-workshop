#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>

int merge_files(const char *file_1, const char *file_2)
{
    FILE *f1 = fopen(file_1, "a");
    FILE *f2 = fopen(file_2, "r");
    if (!f1 || !f2)
        return -1;

    char *line;
    size_t n = 0;
    ssize_t l = 1;
    while (l != -1)
    {
        l = getline(&line, &n, f2);
        if (l == -1)
            break;

        int put = fputs(line, f1);
        if (put == EOF)
            return -1;
    }

    free(line);

    if (fclose(f1) == -1 || fclose(f2) == -1)
        return -1;

    return 0;
}
