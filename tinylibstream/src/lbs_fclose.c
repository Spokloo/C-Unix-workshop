#include <stdlib.h>

#include "../include/libstream.h"

int lbs_fclose(struct stream *file)
{
    int f = lbs_fflush(file);
    if (f == LBS_EOF)
    {
        free(file);
        return LBS_EOF;
    }

    if (close(file->fd) == -1)
    {
        free(file);
        return LBS_EOF;
    }

    free(file);
    return 0;
}
