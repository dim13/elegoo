#ifndef COMMON_H
#define COMMON_H

#include "pb_encode.h"
#include "pb_decode.h"

pb_istream_t pb_istream_from_serial();
pb_ostream_t pb_ostream_from_serial();

#endif
