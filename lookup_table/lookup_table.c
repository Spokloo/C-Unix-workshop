#include "lookup_table.h"

#include <stddef.h>

void apply_lut(unsigned char mat[4][4], const unsigned char lut[256])
{
    size_t size = 4;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            mat[i][j] = lut[mat[i][j]];
        }
    }
}
