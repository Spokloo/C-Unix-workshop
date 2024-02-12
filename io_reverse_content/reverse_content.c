#include <stdio.h>

int reverse_content(const char *file_in, const char *file_out)
{
    if (!file_in || !file_out)
        return -1;

    FILE *f1 = fopen(file_in, "r");
    FILE *f2 = fopen(file_out, "w");
    if (!f1 || !f2)
        return -1;

    int seek = fseek(f1, -1, SEEK_END);
    while (seek != -1)
    {
        int c = fgetc(f1);
        if (c == EOF || fputc(c, f2) == EOF)
            break;

        seek = fseek(f1, -2, SEEK_CUR);
        if (seek == -1)
            break;
    }

    if (fclose(f1) == -1 || fclose(f2) == -1)
        return -1;

    return 0;
}
