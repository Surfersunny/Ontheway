#ifndef __TASK_H
#define __TASK_H

#include "tim.h"

#include "lcd_bsp.h"
#include "led.h"
#include "key.h"
#include "adc_samp.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

#endif