/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.9 at Mon Dec 11 22:16:39 2017. */

#ifndef PB_ELEGOO_ELEGOO_PB_H_INCLUDED
#define PB_ELEGOO_ELEGOO_PB_H_INCLUDED
#include <pb.h>

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _elegoo_InfraRed {
    bool R;
    bool C;
    bool L;
/* @@protoc_insertion_point(struct:elegoo_InfraRed) */
} elegoo_InfraRed;

typedef struct _elegoo_RemoteControl {
    uint32_t Key;
/* @@protoc_insertion_point(struct:elegoo_RemoteControl) */
} elegoo_RemoteControl;

typedef struct _elegoo_Speed {
    int32_t L;
    int32_t R;
/* @@protoc_insertion_point(struct:elegoo_Speed) */
} elegoo_Speed;

typedef struct _elegoo_UltraSonic {
    uint32_t Distance;
    int32_t Direction;
/* @@protoc_insertion_point(struct:elegoo_UltraSonic) */
} elegoo_UltraSonic;

typedef struct _elegoo_Command {
    elegoo_Speed Speed;
    bool Stop;
    uint32_t Direction;
    uint32_t StopAfter;
/* @@protoc_insertion_point(struct:elegoo_Command) */
} elegoo_Command;

typedef struct _elegoo_Event {
    elegoo_UltraSonic Head;
    elegoo_InfraRed Sensor;
    elegoo_RemoteControl Remote;
    uint32_t TimeStamp;
/* @@protoc_insertion_point(struct:elegoo_Event) */
} elegoo_Event;

/* Default values for struct fields */

/* Initializer values for message structs */
#define elegoo_Speed_init_default                {0, 0}
#define elegoo_Command_init_default              {elegoo_Speed_init_default, 0, 0, 0}
#define elegoo_UltraSonic_init_default           {0, 0}
#define elegoo_InfraRed_init_default             {0, 0, 0}
#define elegoo_RemoteControl_init_default        {0}
#define elegoo_Event_init_default                {elegoo_UltraSonic_init_default, elegoo_InfraRed_init_default, elegoo_RemoteControl_init_default, 0}
#define elegoo_Speed_init_zero                   {0, 0}
#define elegoo_Command_init_zero                 {elegoo_Speed_init_zero, 0, 0, 0}
#define elegoo_UltraSonic_init_zero              {0, 0}
#define elegoo_InfraRed_init_zero                {0, 0, 0}
#define elegoo_RemoteControl_init_zero           {0}
#define elegoo_Event_init_zero                   {elegoo_UltraSonic_init_zero, elegoo_InfraRed_init_zero, elegoo_RemoteControl_init_zero, 0}

/* Field tags (for use in manual encoding/decoding) */
#define elegoo_InfraRed_R_tag                    1
#define elegoo_InfraRed_C_tag                    2
#define elegoo_InfraRed_L_tag                    3
#define elegoo_RemoteControl_Key_tag             1
#define elegoo_Speed_L_tag                       1
#define elegoo_Speed_R_tag                       2
#define elegoo_UltraSonic_Distance_tag           1
#define elegoo_UltraSonic_Direction_tag          2
#define elegoo_Command_Speed_tag                 1
#define elegoo_Command_Stop_tag                  3
#define elegoo_Command_Direction_tag             4
#define elegoo_Command_StopAfter_tag             5
#define elegoo_Event_Head_tag                    1
#define elegoo_Event_Sensor_tag                  2
#define elegoo_Event_Remote_tag                  3
#define elegoo_Event_TimeStamp_tag               4

/* Struct field encoding specification for nanopb */
extern const pb_field_t elegoo_Speed_fields[3];
extern const pb_field_t elegoo_Command_fields[5];
extern const pb_field_t elegoo_UltraSonic_fields[3];
extern const pb_field_t elegoo_InfraRed_fields[4];
extern const pb_field_t elegoo_RemoteControl_fields[2];
extern const pb_field_t elegoo_Event_fields[5];

/* Maximum encoded size of messages (where known) */
#define elegoo_Speed_size                        12
#define elegoo_Command_size                      28
#define elegoo_UltraSonic_size                   12
#define elegoo_InfraRed_size                     6
#define elegoo_RemoteControl_size                6
#define elegoo_Event_size                        36

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define ELEGOO_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
