// From https://github.com/amorellgarcia/arduino-nanopb

#include "pb_stream.h"

#define MAXSZ (size_t)-1

bool
os_read(pb_istream_t *stream, uint8_t *buf, size_t count)
{
	Stream *s = static_cast<Stream *>(stream->state);
	while (count > 0) {
		if (s->available() > 0) {
			size_t readCount = s->readBytes((char *)buf, count);
			count -= readCount;
		}
	}
	return true;
}


void
pb_istream_from_stream(Stream &stream, pb_istream_t &istream)
{
	istream.callback = &os_read;
	istream.state = &stream;
	istream.bytes_left = MAXSZ;
#ifndef PB_NO_ERRMSG
	istream.errmsg = NULL;
#endif
}

bool
os_write(pb_ostream_t *stream, const uint8_t *buf, size_t count)
{
	if (stream == NULL || buf == NULL) {
		return false;
	}
	Print *s = static_cast<Print *>(stream->state);
	return (s->write(buf, count) == count);
}

void
pb_ostream_from_stream(Print &stream, pb_ostream_t &ostream) {
	ostream.callback = &os_write;
	ostream.state = &stream;
	ostream.max_size = MAXSZ;
	ostream.bytes_written = 0;
#ifndef PB_NO_ERRMSG
	ostream.errmsg = NULL;
#endif
}
