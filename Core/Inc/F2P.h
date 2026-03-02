/*
 * F2P.h
 *
 *  Created on: Feb 27, 2026
 *      Author: oriol
 */

#ifndef INC_F2P_H_
#define INC_F2P_H_

#include "main.h"

#define ADC_CH 8
#define GPIO_IN 4

//Unió de Array amb Struct, cada espai de la array es un punt de la struct (Ex: array[3] = RfSIGItempM)
typedef union {
    float array[ADC_CH];
    struct {
    	float RpSIGOtempI;
    	float RpSIGItempI;
    	float RpSIGOtempM;
    	float RpSIGItempM;
    	float RpSIGLsus;
    	float RpSIGRsus;
    	float RpSHU;
    	float RSIGlvs;
    };
} AdcData_t;

extern AdcData_t adc_RAW;

typedef union {
	float array[GPIO_IN];
	struct {
		uint8_t RpSDChvd;
		uint8_t RpSDCtsms;
		uint8_t RpSDClsdb;
		uint8_t RpSDCrsdb;
	};
} GPIOINData_t;

extern GPIOINData_t GPIOIN_RAW;

void F2P_ProcessADC(void);

#endif /* INC_F2P_H_ */
