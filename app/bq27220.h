#ifndef __BQ27220_H__
#define __BQ27220_H__

#include<stdint.h>
#include<stdbool.h>
#include<stdio.h>

//define the related functions about IIC drive the struct type
typedef struct
{
    int8_t (*pfinit)(void);                                   //pointer to IIC initialization function
	int8_t (*pfdeinit)(void);                                 //pointer to IIC de-initialization function
	int8_t (*pfwriteReg)(uint8_t,uint8_t,uint8_t,uint8_t);    //pointer to IIC write reg function
	int8_t (*pfreadReg)(uint8_t,uint8_t,uint8_t *,uint8_t);   //pointer to IIC read reg function
	//int8_t (*pfreadReg)(uint8_t,uint8_t,uint8_t *,uint8_t); //pointer to IIC delay  function
}iic_driver_interface_t;

//define the related functions about bq27220 in the struct type
typedef struct 
{
    iic_driver_interface_t piicdriver_interfac;
	
	int8_t (*pfinit)(const void *);               //pointer to initialization function
	int8_t (*pfdeinit)(void);               //pointer to de-initialization function
	int8_t (*pfset_capacity)(uint32_t);     //pointer to set battery capacity function
	int8_t (*pfget_batterylevel)(void);     //pointer to get battery level function
	int8_t (*pfget_batteryvoltage)(void);   //pointer to get battery voltage function
	int8_t (*pfgcalibration_battery)(void); //pointer to calibration battery function
	int8_t (*check_status)(void);           //pointer to check battery status function
}bq27220_t;

uint8_t bq27220_init(const void * pbq27220,
	                 int8_t(*pfiic_init)(void),
				     int8_t(*pfiic_deinit)(void),
					 int8_t (*pfiic_write)(uint8_t,uint8_t,uint8_t,uint8_t),
                     int8_t (*pfiic_read)(uint8_t,uint8_t,uint8_t *,uint8_t),
					 int8_t (*pfiic_write_buff)(uint8_t,uint8_t *,uint8_t));



#endif /* __BQ27220_H__ */