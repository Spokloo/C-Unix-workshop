#include <stdlib.h>
#include <string.h>

#include "../include/libstream.h"

struct stream *lbs_fdopen(int fd, const char *mode)
{
    if (fd == -1)
        return NULL;

    struct stream *stream = malloc(sizeof(struct stream));
    if (!stream)
        return NULL;

    int flags;
    if (strcmp(mode, "r") == 0)
    {
        stream->io_operation = STREAM_READING;
        flags = O_RDONLY;
    }
    else if (strcmp(mode, "r+") == 0)
    {
        stream->io_operation = STREAM_READING;
        flags = O_RDWR;
    }
    else if (strcmp(mode, "w") == 0)
    {
        stream->io_operation = STREAM_WRITING;
        flags = O_WRONLY | O_CREAT | O_TRUNC;
    }
    else if (strcmp(mode, "w+") == 0)
    {
        stream->io_operation = STREAM_WRITING;
        flags = O_RDWR | O_CREAT | O_TRUNC;
    }
    else
    {
        free(stream);
        return NULL;
    }

    stream->flags = flags;
    stream->error = 0;
    stream->fd = fd;
    enum stream_buffering buffer_mode =
        isatty(fd) ? STREAM_LINE_BUFFERED : STREAM_BUFFERED;
    lbs_setbufmode(stream, buffer_mode);
    stream->buffered_size = 0;
    stream->already_read = 0;
    return stream;
}
