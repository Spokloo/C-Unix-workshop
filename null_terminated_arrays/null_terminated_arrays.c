#include "null_terminated_arrays.h"

#include <stddef.h>

static int array_length(const char **arr)
{
    int length = 0;
    for (int i = 0; arr[i]; i++)
        length++;

    return length;
}

static void reverse_array(const char **arr)
{
    int length = array_length(arr);
    if (length == 0)
        return;

    int i = 0;
    int j = length - 1;

    while (i < j)
    {
        const char *tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;

        i++;
        j--;
    }
}

void reverse_matrix(const char ***matrix)
{
    int length = 0;
    for (int i = 0; matrix[i]; i++)
    {
        reverse_array(matrix[i]);
        length++;
    }

    int i = 0;
    int j = length - 1;

    while (i < j)
    {
        const char **tmp = matrix[i];
        matrix[i] = matrix[j];
        matrix[j] = tmp;

        i++;
        j--;
    }
}
