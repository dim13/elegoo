/* Automatically generated nanopb constant definitions */
/* Generated by nanopb-0.3.6 at Mon Aug 21 23:14:33 2017. */

#include "elegoo.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t Command_fields[7] = {
    PB_FIELD(  1, SINT32  , OPTIONAL, STATIC  , FIRST, Command, SpeedR, SpeedR, 0),
    PB_FIELD(  2, SINT32  , OPTIONAL, STATIC  , OTHER, Command, SpeedL, SpeedR, 0),
    PB_FIELD(  3, BOOL    , OPTIONAL, STATIC  , OTHER, Command, Stop, SpeedL, 0),
    PB_FIELD(  4, BOOL    , OPTIONAL, STATIC  , OTHER, Command, Center, Stop, 0),
    PB_FIELD(  5, SINT32  , OPTIONAL, STATIC  , OTHER, Command, TurnHead, Center, 0),
    PB_FIELD(  6, SINT32  , OPTIONAL, STATIC  , OTHER, Command, Trim, TurnHead, 0),
    PB_LAST_FIELD
};

const pb_field_t Event_fields[6] = {
    PB_FIELD(  1, UINT32  , OPTIONAL, STATIC  , FIRST, Event, Distance, Distance, 0),
    PB_FIELD(  2, BOOL    , OPTIONAL, STATIC  , OTHER, Event, SensorR, Distance, 0),
    PB_FIELD(  3, BOOL    , OPTIONAL, STATIC  , OTHER, Event, SensorC, SensorR, 0),
    PB_FIELD(  4, BOOL    , OPTIONAL, STATIC  , OTHER, Event, SensorL, SensorC, 0),
    PB_FIELD(  5, UINT32  , OPTIONAL, STATIC  , OTHER, Event, KeyPress, SensorL, 0),
    PB_LAST_FIELD
};


/* @@protoc_insertion_point(eof) */
