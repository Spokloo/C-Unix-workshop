#include "lakes.h"

void fill_lake(char **map, int i, int j)
{
    map[i][j] = '$';

    if (map[i][j - 1] == '.')
    {
        fill_lake(map, i, j - 1);
    }
    if (map[i][j + 1] == '.')
    {
        fill_lake(map, i, j + 1);
    }
    if (map[i - 1][j] == '.')
    {
        fill_lake(map, i - 1, j);
    }
    if (map[i + 1][j] == '.')
    {
        fill_lake(map, i + 1, j);
    }
}

int lakes(char **map, int width, int height)
{
    int n = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (map[i][j] == '.')
            {
                fill_lake(map, i, j);
                n++;
            }
        }
    }

    return n;
}
