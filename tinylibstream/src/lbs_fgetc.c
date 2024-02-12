#include "../include/libstream.h"

int lbs_fgetc(struct stream *stream)
{
    if (stream->io_operation == STREAM_WRITING)
    {
        if (!stream_readable(stream) || lbs_fflush(stream) == LBS_EOF)
        {
            stream->error = 1;
            return LBS_EOF;
        }

        stream->io_operation = STREAM_READING;
    }

    if (stream->already_read == stream->buffered_size
        || stream->buffered_size == 0)
    {
        ssize_t r = read(stream->fd, stream->buffer, LBS_BUFFER_SIZE);
        if (r <= 0)
        {
            stream->error = 1;
            return LBS_EOF;
        }

        stream->buffered_size = r;
        stream->already_read = 0;
    }

    stream->already_read++;
    unsigned char c = stream->buffer[stream->already_read - 1];
    return c;
}
