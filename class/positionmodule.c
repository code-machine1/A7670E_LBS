#include "positionmodule.h"

/* positionmodule info */
typedef struct
{
  uint8_t SIMEI_data[15];
  uint8_t latitude_data[15];
  uint8_t longitude_data[15];
} positionmodule_t;
volatile positionmodule_t tPositionModuleInfo;

/* positionmodule status */
typedef struct
{
    bool poweron;
    bool poweroff;
    bool modulestatus;    // true:working   false:shoutdown
    bool residentnetwork; // true:connected network successfully   false:connected network fail
    uint8_t signalvalue;  /* signalvalue(0-31)    0 -113 dBm or less
												  1 -111 dBm
												  2бн30 -109бн -53 dBm
												  31 -51 dBm or greater
	                      */
} positionmodulestatus_t;
volatile positionmodulestatus_t tPositionModuleStatus;


uint8_t PositionModulePowerOn(void)
{
    A7670E_PWIO_EN(1);        //pull power io hight
    HAL_Delay(30);            //delay 30ms
    A7670E_PWIO_EN(0);        //pull power io dowm
    if(GET_A7670E_STATUS)     //check module status
        return 0;
    else
        return -1;

}

char PositionModulePowerOff(void)
{
    A7670E_PWIO_EN(1);       //pull power io hight
    HAL_Delay(3000);         //delay 3000ms
    A7670E_PWIO_EN(0);       //pull power io dowm
    if(GET_A7670E_STATUS)    //check module status
        return -1;
    else
        return 0;
}

uint8_t Get_PositionModuleStatus(void)
{
    if(GET_A7670E_STATUS)//read status pin: high mean workong,low mean shoutdowm
        return 0;
    else
        return -1;
}

char PositionModuleInit(void)
{
    PositionModulePowerOn();  //power on
    HAL_Delay(2000);//wait for module ready
    if(Get_PositionModuleStatus())//check module status
    {

    }
    else
        return -1;
    /* hardware initialization */
    //send at command
	
    //send AT+CPIN?
    //send AT+CSQ
    //check signal value
    //send AT+CREG?
    //check network registration status
    //send AT+SIMEI?
    //check SIMEI data
    //send AT+SIMEI=xxxx    xxxx must correspond to the IMEI code on the module sticker

    /* MQTT parameter initialization */
    //send AT+CMQTTSTART
    //send AT+CMQTTACCQ=0,"SIM7600Test"   //set client ID
    //send AT+CMQTTCONNECT=0,"tcp://8.134.147.78:1883",60,1,"aimira","aimira123" //set connect info

    return 0;
}

uint8_t Get_Lbs(void)
{
    //send AT+CLBS=1
    return 0;
}

uint8_t Send_ModuleInfo(void)
{
    //send AT+CLBS=1
    return 0;
}

uint8_t Get_MQTTInfo(void)
{
    //send AT+CLBS=1
    return 0;
}



