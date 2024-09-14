#include "battery.h"

#define Battery_Address        0X55
#define Battery_Read_Address   0XAB
#define Battery_Write_Address  0XAA

/* battery info */
typedef struct
{
    uint8_t level;
    uint8_t endurance;
    uint8_t voltage;
    uint8_t temperature;
    bool levelcalibration;
} batteryinfo_t;
volatile batteryinfo_t tBatteryInfo;

/* battery status */
typedef struct
{
    bool charging;
    bool discharge;
} batterystatus_t;
volatile batterystatus_t tBatteryStatus;

uint8_t read_batterylevel(void)
{
    return 0;
}

uint8_t read_batteryvoltage(void)
{
    return 0;
}

uint8_t read_batteryendurance(void)
{
    return 0;
}

uint8_t calibration_battery(void)
{
    return 0;
}

uint8_t battery_init(void)
{
    return 0;
}
