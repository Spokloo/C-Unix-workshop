#include <stdlib.h>
#include <string.h>

#include "../include/libstream.h"

struct stream *lbs_fopen(const char *path, const char *mode)
{
    int flags;
    int mode_open = 00644;
    if (strcmp(mode, "r") == 0)
        flags = O_RDONLY;
    else if (strcmp(mode, "r+") == 0)
        flags = O_RDWR;
    else if (strcmp(mode, "w") == 0)
        flags = O_WRONLY | O_CREAT | O_TRUNC;
    else if (strcmp(mode, "w+") == 0)
        flags = O_RDWR | O_CREAT | O_TRUNC;
    else
        return NULL;

    int fd = open(path, flags, mode_open);
    if (fd == -1)
        return NULL;

    struct stream *stream = lbs_fdopen(fd, mode);
    if (!stream)
        return NULL;

    return stream;
}
