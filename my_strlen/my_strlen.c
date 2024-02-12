#include "my_strlen.h"

size_t my_strlen(const char *s)
{
    size_t size = 0;
    for (size_t i = 0; s[i] != '\0'; i++)
    {
        size++;
    }

    return size;
}
