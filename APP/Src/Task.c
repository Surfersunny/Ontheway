#include "Task.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim == &htim4) {
		key_scan();
		lcd_show();
		led_show();
	}
}