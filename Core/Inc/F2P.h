/*
 * F2P.h
 *
 *  Created on: Feb 27, 2026
 *      Author: oriol
 */

#ifndef INC_F2P_H_
#define INC_F2P_H_

#include "main.h"

#define ADC1_CH 8

typedef union {
    float array[ADC1_CH];
    struct {
    	float RfSIGOtempI;
    	float RfSIGItempI;
    	float RfSIGOtempM;
    	float RfSIGItempM;
    	float RSIGLsus;
    	float RSIGRsus;
    	float RfSHU;
    	float RSIGlvs;
    };
} Adc1Data_t;

extern Adc1Data_t adc1_RAW;

void F2P_ProcessADC(void);

#endif /* INC_F2P_H_ */
