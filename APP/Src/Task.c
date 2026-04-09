#include "Task.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim == &htim4) {
		led_show();
		lcd_show();
		duty_set();
		pwm_out();
		key_scan();
	}
}