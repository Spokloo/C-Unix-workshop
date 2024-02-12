#include <stdio.h>

int count_words(const char *file_in)
{
    if (!file_in)
        return -1;

    FILE *f = fopen(file_in, "r");
    if (!f)
        return -1;

    int count = 0;
    int is_word = 0;
    int c = fgetc(f);
    while (c != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            if (is_word)
            {
                count++;
                is_word = 0;
            }

            while (c != EOF && (c == ' ' || c == '\t' || c == '\n'))
                c = fgetc(f);
        }
        else
        {
            is_word = 1;
            c = fgetc(f);
        }
    }

    if (is_word)
        return count + 1;

    if (fclose(f) != 0)
        return -1;

    return count;
}
