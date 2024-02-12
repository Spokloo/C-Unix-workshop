#include <stdio.h>

int append_file(const char *file_in, const char *content)
{
    if (!file_in || !content)
        return -1;

    FILE *f = fopen(file_in, "a");
    if (!f)
        return -1;

    int l = fprintf(f, "%s", content);
    if (l == -1)
        return -1;

    if (fclose(f) == -1)
        return -1;

    return 0;
}
