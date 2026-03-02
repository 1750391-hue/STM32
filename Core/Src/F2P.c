/*
 * F2P.c
 *
 *  Created on: Feb 27, 2026
 *      Author: oriol
 */
#include "F2P.h"
#include "main.h"

#define ADC1_CH 6 // Definim 6 perquè son els espais a la array contant l'espai 0 com un, es a dir que la array serà de [0-5].
#define ADC2_CH 2 // el mateix fins però amb [0, 1].

extern uint16_t adc1_buf[ADC1_CH];
extern uint16_t adc2_buf[ADC2_CH];

AdcData_t Padc;
GPIOINData_t gpioin;

void F2P_ProcessADC(void) {

    for(int i = 0; i < ADC1_CH; i++) {
        Padc.array[i] = (float)adc1_buf[i];
    }

    for(int i = 0; i < ADC2_CH; i++) {
        Padc.array[i + ADC1_CH] = (float)adc2_buf[i];
    }
}

void F2P_ProcessGPIOIN(void) {
	gpioin.RpSDChvd = HAL_GPIO_ReadPin(GPIOB, RfSDChvd_Pin);
	gpioin.RpSDCtsms = HAL_GPIO_ReadPin(GPIOB, RfSDCtsms_Pin);
	gpioin.RpSDClsdb = HAL_GPIO_ReadPin(GPIOB, RfSDClsdb_Pin);
	gpioin.RpSDCrsdb = HAL_GPIO_ReadPin(GPIOC, RfSDCrsdb_Pin);
}
