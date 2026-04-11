#ifndef __TASK_H
#define __TASK_H

#include "led.h"
#include "lcd_bsp.h"
#include "key.h"
#include "uart.h"

#include "tim.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

#endif