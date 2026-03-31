#include "pwm.h"

extern uint16_t rpm;

void pwm_out() {
	__HAL_TIM_SetCompare(&htim17, TIM_CHANNEL_1, rpm);
}