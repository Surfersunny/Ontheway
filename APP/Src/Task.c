#include "Task.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim == &htim6) {
		key_scan();
		lcd_show();
		led_show();
		uart_proc();
	}
}