#include "my_strstr.h"

#include <stddef.h>

int my_strstr(const char *haystack, const char *needle)
{
    if (!needle || needle[0] == '\0')
    {
        return 0;
    }

    for (size_t i = 0; haystack[i] != '\0'; i++)
    {
        if (haystack[i] == needle[0])
        {
            size_t index = i;
            size_t j = 0;
            while (needle[j] != '\0')
            {
                if (haystack[i] != needle[j])
                {
                    break;
                }

                i++;
                j++;
            }

            if (needle[j] == '\0')
            {
                return index;
            }

            i = index + 1;
        }
    }

    return -1;
}
