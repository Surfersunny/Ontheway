#ifndef __TASK_H
#define __TASK_H

#include "lcd_bsp.h"
#include "led.h"
#include "adc_samp.h"
#include "key.h"
#include "uart.h"

#include "tim.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

#endif