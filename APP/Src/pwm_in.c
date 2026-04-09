#include "pwm_in.h"

extern uint8_t R;
extern uint8_t K;

extern uint8_t mode;

float vel;

float freq;
float MH = 0;
float ML = 0;

uint32_t counter;

void vel_meas() {
		counter = HAL_TIM_ReadCapturedValue(&htim17, TIM_CHANNEL_1);
	
		TIM17->CNT = 0;
}

void max_speed() {
	freq = 80000000 / (80 * counter);
	
	vel = freq * 6.28 * R / (100 * K);
	
	if (mode == 0) {
		if (vel > ML) ML = vel;
	}
	else if (mode == 1) {
		if (vel > MH) MH = vel;
	}
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim) {
	if (htim == &htim17) {
		vel_meas();
		max_speed();
	}
}

