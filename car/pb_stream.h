#ifndef PB_STREAM
#define PB_STREAM

#include <Stream.h>
#include <Print.h>
#include "pb_encode.h"
#include "pb_decode.h"

void pb_istream_from_stream(Stream &stream, pb_istream_t &istream);
void pb_ostream_from_stream(Print &stream, pb_ostream_t &ostream);

#endif
