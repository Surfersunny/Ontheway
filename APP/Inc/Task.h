#ifndef __TASK_H
#define __TASK_H

#include "led.h"
#include "lcd_bsp.h"
#include "adc_samp.h"
#include "pwm_out.h"
#include "pwm_in.h"
#include "key.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

#endif