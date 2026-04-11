#ifndef __PWM_IN_H
#define __PWM_IN_H

#include "tim.h"

void pwm_in1();
void pwm_in2();

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);
	
#endif