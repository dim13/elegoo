/* Automatically generated nanopb constant definitions */
/* Generated by nanopb-0.3.6 at Mon Aug 21 21:08:59 2017. */

#include "elegoo.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t Command_fields[5] = {
    PB_FIELD(  1, INT32   , OPTIONAL, STATIC  , FIRST, Command, LeftSpeed, LeftSpeed, 0),
    PB_FIELD(  2, INT32   , OPTIONAL, STATIC  , OTHER, Command, RightSpeed, LeftSpeed, 0),
    PB_FIELD(  3, SINT32  , OPTIONAL, STATIC  , OTHER, Command, TurnHead, RightSpeed, 0),
    PB_FIELD(  4, BOOL    , OPTIONAL, STATIC  , OTHER, Command, Center, TurnHead, 0),
    PB_LAST_FIELD
};

const pb_field_t Event_fields[6] = {
    PB_FIELD(  1, INT32   , OPTIONAL, STATIC  , FIRST, Event, Distance, Distance, 0),
    PB_FIELD(  2, BOOL    , OPTIONAL, STATIC  , OTHER, Event, SensorR, Distance, 0),
    PB_FIELD(  3, BOOL    , OPTIONAL, STATIC  , OTHER, Event, SensorC, SensorR, 0),
    PB_FIELD(  4, BOOL    , OPTIONAL, STATIC  , OTHER, Event, SensorL, SensorC, 0),
    PB_FIELD(  5, UINT32  , OPTIONAL, STATIC  , OTHER, Event, KeyPress, SensorL, 0),
    PB_LAST_FIELD
};


/* @@protoc_insertion_point(eof) */
