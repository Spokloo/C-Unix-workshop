#include "../include/libstream.h"

int set_error(struct stream *stream)
{
    stream->error = 1;
    return LBS_EOF;
}

int lbs_fflush(struct stream *stream)
{
    if (!stream)
        return LBS_EOF;

    if (stream->io_operation == STREAM_WRITING)
    {
        if (!stream_writable(stream))
            return set_error(stream);

        if (stream->buffered_size != 0)
        {
            ssize_t w =
                write(stream->fd, stream->buffer, stream->buffered_size);
            size_t n = w;
            while (n < stream->buffered_size)
            {
                w = write(stream->fd, stream->buffer + n,
                          stream->buffered_size - n);
                if (w == -1)
                    return set_error(stream);

                n += w;
            }

            stream->buffered_size = 0;
            stream->already_read = 0;
        }
    }
    else if (stream->io_operation == STREAM_READING)
    {
        if (!stream_readable(stream))
            return set_error(stream);

        off_t seek =
            lseek(stream->fd, -stream_remaining_buffered(stream), SEEK_CUR);
        if (seek == -1)
            return set_error(stream);

        stream->buffered_size = 0;
        stream->already_read = 0;
    }

    return 0;
}
