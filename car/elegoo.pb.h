/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.6 at Tue Aug 22 00:23:16 2017. */

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
    bool has_Center;
    bool Center;
    bool has_Direction;
    int32_t Direction;
/* @@protoc_insertion_point(struct:Command) */
} Command;

typedef struct _Event {
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
/* @@protoc_insertion_point(struct:Event) */
} Event;

/* Default values for struct fields */

/* Initializer values for message structs */
#define Command_init_default                     {false, 0, false, 0, false, 0, false, 0, false, 0}
#define Event_init_default                       {false, 0, false, 0, false, 0, false, 0, false, 0, false, 0}
#define Command_init_zero                        {false, 0, false, 0, false, 0, false, 0, false, 0}
#define Event_init_zero                          {false, 0, false, 0, false, 0, false, 0, false, 0, false, 0}

/* Field tags (for use in manual encoding/decoding) */
#define Command_SpeedR_tag                       1
#define Command_SpeedL_tag                       2
#define Command_Stop_tag                         3
#define Command_Center_tag                       4
#define Command_Direction_tag                    5
#define Event_Distance_tag                       1
#define Event_Direction_tag                      2
#define Event_SensorR_tag                        3
#define Event_SensorC_tag                        4
#define Event_SensorL_tag                        5
#define Event_KeyPress_tag                       6

/* Struct field encoding specification for nanopb */
extern const pb_field_t Command_fields[6];
extern const pb_field_t Event_fields[7];

/* Maximum encoded size of messages (where known) */
#define Command_size                             22
#define Event_size                               24

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define ELEGOO_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
