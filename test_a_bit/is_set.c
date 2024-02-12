#include "is_set.h"

#include <stddef.h>

unsigned int is_set(unsigned int value, unsigned char n)
{
    unsigned int set = 1 << (n - 1);
    return (value & set) == set;
}
