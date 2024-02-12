#define _POSIX_C_SOURCE 200809L

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static size_t length(const char *str)
{
    size_t len = 0;
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        len++;
    }

    return len;
}

static size_t count_content(size_t count, ssize_t l, const char *content)
{
    size_t i;
    for (i = 0; content[i] != '\0'; i++)
    {
        if (content[i] == '\n')
            count++;
    }

    if (l == -1 && content[i - 1] != '\n')
        count++;

    return count;
}

static int insert_hat_func(FILE *f1, FILE *f2, const char *content, size_t n)
{
    char *line;
    size_t size = 0;
    size_t count = 0;
    ssize_t l = getline(&line, &size, f1);

    while (count < n && l != -1)
    {
        if (fputs(line, f2) == EOF)
            return -1;

        count++;
        l = getline(&line, &size, f1);
    }

    if (count < n && line[length(line) - 1] != '\n')
    {
        if (fputs("\n", f2) == EOF)
            return -1;
        count++;
    }

    while (count < n && l == -1)
    {
        if (fputs("\n", f2) == EOF)
            return -1;

        count++;
        l = getline(&line, &size, f1);
    }

    if (fputs(content, f2) == EOF)
        return -1;

    count = count_content(count, l, content);

    while (l != -1)
    {
        if (fputs(line, f2) == EOF)
            return -1;

        count++;
        l = getline(&line, &size, f1);
    }

    free(line);
    return count;
}

int insert_line(const char *file_in, const char *file_out, const char *content,
                size_t n)
{
    if (!file_in || !file_out || !content)
        return -1;

    FILE *f1 = fopen(file_in, "r");
    FILE *f2 = fopen(file_out, "w");
    if (!f1 || !f2)
        return -1;

    int count = insert_hat_func(f1, f2, content, n);
    if (count == -1)
        return -1;

    if (fclose(f1) == -1 || fclose(f2) == -1)
        return -1;

    return count;
}
