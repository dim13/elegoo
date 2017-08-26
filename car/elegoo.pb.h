/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.6 at Sat Aug 26 18:04:10 2017. */

#ifndef PB_ELEGOO_PB_H_INCLUDED
#define PB_ELEGOO_PB_H_INCLUDED
#include <pb.h>

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _Command {
    bool has_SpeedR;
    int32_t SpeedR;
    bool has_SpeedL;
    int32_t SpeedL;
    bool has_Stop;
    bool Stop;
    bool has_Direction;
    uint32_t Direction;
    bool has_StopAfter;
    uint32_t StopAfter;
/* @@protoc_insertion_point(struct:Command) */
} Command;

typedef struct _Events {
    bool has_Distance;
    uint32_t Distance;
    bool has_Direction;
    int32_t Direction;
    bool has_SensorR;
    bool SensorR;
    bool has_SensorC;
    bool SensorC;
    bool has_SensorL;
    bool SensorL;
    bool has_KeyPress;
    uint32_t KeyPress;
    bool has_Time;
    uint32_t Time;
/* @@protoc_insertion_point(struct:Events) */
} Events;

/* Default values for struct fields */

/* Initializer values for message structs */
#define Command_init_default                     {false, 0, false, 0, false, 0, false, 0, false, 0}
#define Events_init_default                      {false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0}
#define Command_init_zero                        {false, 0, false, 0, false, 0, false, 0, false, 0}
#define Events_init_zero                         {false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0}

/* Field tags (for use in manual encoding/decoding) */
#define Command_SpeedR_tag                       1
#define Command_SpeedL_tag                       2
#define Command_Stop_tag                         3
#define Command_Direction_tag                    4
#define Command_StopAfter_tag                    5
#define Events_Distance_tag                      1
#define Events_Direction_tag                     2
#define Events_SensorR_tag                       3
#define Events_SensorC_tag                       4
#define Events_SensorL_tag                       5
#define Events_KeyPress_tag                      6
#define Events_Time_tag                          7

/* Struct field encoding specification for nanopb */
extern const pb_field_t Command_fields[6];
extern const pb_field_t Events_fields[8];

/* Maximum encoded size of messages (where known) */
#define Command_size                             26
#define Events_size                              30

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define ELEGOO_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
