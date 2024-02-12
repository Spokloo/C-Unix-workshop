#include "../include/libstream.h"

int lbs_fputc(int c, struct stream *stream)
{
    if (!stream)
        return LBS_EOF;

    if (stream->io_operation == STREAM_READING)
    {
        if (!stream_writable(stream) || lbs_fflush(stream) == LBS_EOF)
        {
            stream->error = 1;
            return LBS_EOF;
        }

        stream->io_operation = STREAM_WRITING;
    }

    unsigned char d = c;
    if (stream->buffering_mode == STREAM_UNBUFFERED)
    {
        int f = lbs_fflush(stream);
        if (f == LBS_EOF)
            return LBS_EOF;
    }

    if (stream->buffering_mode == STREAM_BUFFERED)
    {
        if (stream->buffered_size == LBS_BUFFER_SIZE)
        {
            int f = lbs_fflush(stream);
            if (f == LBS_EOF)
                return LBS_EOF;
        }
    }

    if (stream->buffering_mode == STREAM_LINE_BUFFERED)
    {
        if (stream->buffered_size == LBS_BUFFER_SIZE || d == '\n')
        {
            int f = lbs_fflush(stream);
            if (f == LBS_EOF)
                return LBS_EOF;
        }
    }

    stream->buffer[stream->buffered_size] = d;
    stream->buffered_size++;
    if (stream->buffering_mode == STREAM_UNBUFFERED)
    {
        int f = lbs_fflush(stream);
        if (f == LBS_EOF)
            return LBS_EOF;
    }

    return d;
}
