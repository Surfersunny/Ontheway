#include "pwm_out.h"

extern float duty;
extern uint32_t freq;

void pwm_set() {
	__HAL_TIM_PRESCALER(&htim3, 80000000 / (1000 * freq));
	
	__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 1000 * duty);
}