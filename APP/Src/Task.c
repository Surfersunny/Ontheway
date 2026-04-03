#include "Task.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim == &htim6) {
		lcd_show();
		led_show();
		key_scan();
		adc_meas();
		pwm_set();
	}
}
