/* Automatically generated nanopb constant definitions */
/* Generated by nanopb-0.3.9 at Mon Dec 11 22:33:35 2017. */

#include "elegoo.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t elegoo_Speed_fields[3] = {
    PB_FIELD(  1, SINT32  , SINGULAR, STATIC  , FIRST, elegoo_Speed, L, L, 0),
    PB_FIELD(  2, SINT32  , SINGULAR, STATIC  , OTHER, elegoo_Speed, R, L, 0),
    PB_LAST_FIELD
};

const pb_field_t elegoo_Command_fields[5] = {
    PB_FIELD(  1, MESSAGE , SINGULAR, STATIC  , FIRST, elegoo_Command, Speed, Speed, &elegoo_Speed_fields),
    PB_FIELD(  3, BOOL    , SINGULAR, STATIC  , OTHER, elegoo_Command, Stop, Speed, 0),
    PB_FIELD(  4, UINT32  , SINGULAR, STATIC  , OTHER, elegoo_Command, Look, Stop, 0),
    PB_FIELD(  5, UINT32  , SINGULAR, STATIC  , OTHER, elegoo_Command, StopAfter, Look, 0),
    PB_LAST_FIELD
};

const pb_field_t elegoo_UltraSonic_fields[3] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, elegoo_UltraSonic, Distance, Distance, 0),
    PB_FIELD(  2, SINT32  , SINGULAR, STATIC  , OTHER, elegoo_UltraSonic, Direction, Distance, 0),
    PB_LAST_FIELD
};

const pb_field_t elegoo_InfraRed_fields[4] = {
    PB_FIELD(  1, BOOL    , SINGULAR, STATIC  , FIRST, elegoo_InfraRed, R, R, 0),
    PB_FIELD(  2, BOOL    , SINGULAR, STATIC  , OTHER, elegoo_InfraRed, C, R, 0),
    PB_FIELD(  3, BOOL    , SINGULAR, STATIC  , OTHER, elegoo_InfraRed, L, C, 0),
    PB_LAST_FIELD
};

const pb_field_t elegoo_RemoteControl_fields[2] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, elegoo_RemoteControl, Key, Key, 0),
    PB_LAST_FIELD
};

const pb_field_t elegoo_Event_fields[5] = {
    PB_FIELD(  1, MESSAGE , SINGULAR, STATIC  , FIRST, elegoo_Event, Head, Head, &elegoo_UltraSonic_fields),
    PB_FIELD(  2, MESSAGE , SINGULAR, STATIC  , OTHER, elegoo_Event, Sensor, Head, &elegoo_InfraRed_fields),
    PB_FIELD(  3, MESSAGE , SINGULAR, STATIC  , OTHER, elegoo_Event, Remote, Sensor, &elegoo_RemoteControl_fields),
    PB_FIELD(  4, UINT32  , SINGULAR, STATIC  , OTHER, elegoo_Event, TimeStamp, Remote, 0),
    PB_LAST_FIELD
};


/* Check that field information fits in pb_field_t */
#if !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_32BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in 8 or 16 bit
 * field descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(elegoo_Command, Speed) < 65536 && pb_membersize(elegoo_Event, Head) < 65536 && pb_membersize(elegoo_Event, Sensor) < 65536 && pb_membersize(elegoo_Event, Remote) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_elegoo_Speed_elegoo_Command_elegoo_UltraSonic_elegoo_InfraRed_elegoo_RemoteControl_elegoo_Event)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(elegoo_Command, Speed) < 256 && pb_membersize(elegoo_Event, Head) < 256 && pb_membersize(elegoo_Event, Sensor) < 256 && pb_membersize(elegoo_Event, Remote) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_elegoo_Speed_elegoo_Command_elegoo_UltraSonic_elegoo_InfraRed_elegoo_RemoteControl_elegoo_Event)
#endif


/* @@protoc_insertion_point(eof) */
