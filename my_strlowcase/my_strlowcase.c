#include "my_strlowcase.h"

void my_strlowcase(char *str)
{
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 'a' - 'A';
        }
    }
}
