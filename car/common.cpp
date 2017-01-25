//#include <Arduino.h>
#include <HardwareSerial.h>
#include "pb_encode.h"
#include "pb_decode.h"

#define MAXSZ 32

bool
write_callback(pb_ostream_t *stream, const uint8_t *buf, size_t count)
{
	int result = Serial.write(buf, count);
//	Serial.flush();
	return result == count;
}

bool
read_callback(pb_istream_t *stream, uint8_t *buf, size_t count)
{
	int result = Serial.readBytes(buf, count);
	if (result == 0) {
		stream->bytes_left = 0; // EOF
	}
	return result == count;
}

pb_ostream_t
pb_ostream_from_serial()
{
	pb_ostream_t stream = {write_callback, NULL, MAXSZ, 0};
	return stream;
}

pb_istream_t
pb_istream_from_serial()
{
	pb_istream_t stream = {read_callback, NULL, MAXSZ};
	return stream;
}
