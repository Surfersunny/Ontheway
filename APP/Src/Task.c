#include "Task.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim == &htim2) {
		get_temperature();
		key_scan();
		rpm_set();
		led_show();
		lcd_show();
	}
}