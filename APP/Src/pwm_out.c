#include "pwm_out.h"

extern uint8_t page;

uint16_t freq = 2000;
uint8_t duty = 10;

void pwm() {
	if (page == 1) {
		__HAL_TIM_SET_PRESCALER(&htim2, 39);
		
		__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_2, 100);
	}
}