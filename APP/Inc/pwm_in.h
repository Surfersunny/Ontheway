#ifndef __PWM_IN_H
#define __PWM_IN_H

#include "tim.h"

void vel_meas();

void max_speed();

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);

#endif