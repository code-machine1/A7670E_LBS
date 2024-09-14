#include "bq27220.h"
/*
    int8_t (*pfinit)(void *);                 //pointer to initialization function
	int8_t (*pfdeinit)(void);               //pointer to de-initialization function
	int8_t (*pfset_capacity)(uint32_t);     //pointer to set battery capacity function
	int8_t (*pfget_batterylevel)(void);     //pointer to get battery level function
	int8_t (*pfget_batteryvoltage)(void);   //pointer to get battery voltage function
	int8_t (*pfgcalibration_battery)(void); //pointer to calibration battery function
	int8_t (*check_status)(void);           //pointer to check battery status function


    int8_t (*pfinit)(void);                                 //pointer to IIC initialization function
	int8_t (*pfdeinit)(void);                               //pointer to IIC de-initialization function
	int8_t (*pfwriteReg)(uint8_t,uint8_t,uint8_t,uint8_t);  //pointer to IIC write reg function
	int8_t (*pfreadReg)(uint8_t,uint8_t,uint8_t *,uint8_t); //pointer to IIC read reg function


*/

uint8_t bq27220_init(const void * pbq27220,
	                 int8_t(*pfiic_init)(void),
				     int8_t(*pfiic_deinit)(void),
					 int8_t (*pfiic_write)(uint8_t,uint8_t,uint8_t,uint8_t),
                     int8_t (*pfiic_read)(uint8_t,uint8_t,uint8_t *,uint8_t),
					 int8_t (*pfiic_write_buff)(uint8_t,uint8_t *,uint8_t))
{
    bq27220_t * ptemp = pbq27220;
	
	iic_driver_interface_t iic_driver_interface;
	
	iic_driver_interface.pfinit     = pfiic_init;
	iic_driver_interface.pfdeinit   = pfiic_deinit;
	iic_driver_interface.pfwriteReg = pfiic_write;
	iic_driver_interface.pfreadReg  = pfiic_read; 

	return 0;
}