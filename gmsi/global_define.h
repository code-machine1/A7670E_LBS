#ifndef __GLOBAL_DEFINE_H__
#define __GLOBAL_DEFINE_H__

// Include necessary libraries
#include <stdbool.h>
#include <stdint.h>

// Define types
#define GMSI_ID_BASEOFFSET      8
// HARDWARE
#define GMSI_ID_UART        1
#define GMSI_ID_IIC         2
#define GMSI_ID_SPI         3
#define GMSI_ID_CAN         4
#define GMSI_ID_INPUT       5
#define GMSI_ID_SENSOR      6
#define GMSI_ID_TIMER       7
#define GMSI_ID_IO          8
#define GMSI_ID_STORAGE     9
// SOFTWARE
#define GMSI_ID_CLASS       100
#define GMSI_ID_MOCK        101

// Define error codes
#define GMSI_SUCCESS        0
#define GMSI_EPERM          -1
#define GMSI_ENOENT         -2
#define GMSI_ESRCH          -3  
#define GMSI_EINTR          -4
#define GMSI_EIO            -5
#define GMSI_ENXIO          -6
#define GMSI_E2BIG          -7
#define GMSI_EINVAL         -8
#define GMSI_EBADF          -9
#define GMSI_ECHILD         -10
#define GMSI_EAGAIN         -11
#define GMSI_ENOMEM         -12
#define GMSI_EACCES         -13
#define GMSI_EFAULT         -14
#define GMSI_ENOTBLK        -15
#define GMSI_EBUSY          -16
#define GMSI_EEXIST         -17
#define GMSI_EXDEV          -18
#define GMSI_ENODEV         -19
#define GMSI_EFAIL          -20
#define GMSI_EMAX           -21

// Define events
typedef enum {
    Gmsi_Event00 = 1 << 0,
    Gmsi_Event01 = 1 << 1,
    Gmsi_Event02 = 1 << 2,
    Gmsi_Event03 = 1 << 3,
    Gmsi_Event04 = 1 << 4,
    Gmsi_Event05 = 1 << 5,
    Gmsi_Event06 = 1 << 6,
    Gmsi_Event07 = 1 << 7,
    Gmsi_Event08 = 1 << 8,
    Gmsi_Event09 = 1 << 9,
    Gmsi_Event10 = 1 << 10,
    Gmsi_Event11 = 1 << 11,
    Gmsi_Event12 = 1 << 12,
    Gmsi_Event13 = 1 << 13,
    Gmsi_Event14 = 1 << 14,
    Gmsi_Event15 = 1 << 15,
    Gmsi_Event16 = 1 << 16,
    Gmsi_Event17 = 1 << 17,
    Gmsi_Event18 = 1 << 18,
    Gmsi_Event19 = 1 << 19,
    Gmsi_Event20 = 1 << 20,
    Gmsi_Event21 = 1 << 21,
    Gmsi_Event22 = 1 << 22,
    Gmsi_Event23 = 1 << 23,
    Gmsi_Event24 = 1 << 24,
    Gmsi_Event25 = 1 << 25,
    Gmsi_Event26 = 1 << 26,
    Gmsi_Event27 = 1 << 27,
    Gmsi_Event28 = 1 << 28,
    Gmsi_Event29 = 1 << 29,
    Gmsi_Event_Timeout = 1 << 30,
    Gmsi_Event_Transition = (uint32_t)(1 << 31),
} Gmsi_Event;

// Define GMSI IDs
#define GMSI_STORAGE        ((GMSI_ID_STORAGE<<8)+1)
typedef enum{
    Event_Storage = Gmsi_Event00,
    Event_GetData = Gmsi_Event01,
}GMSI_STORAGE_Event;
#define GMSI_INPUT          ((GMSI_ID_IO<<8)+1)

#define GET_OBJECT_POINT(OBJECT, ADDR)    (OBJECT *)(ADDR)
/*
#define DEFINE_OBJECT(OBJECT)   \
    do{
        OBJECT##_cfg_t t##OBJECT##Cfg = {
            .
    }
    }while(0)
*/

#endif