#include "pwm_in.h"

float freq1;
float freq2;

extern uint8_t mode;
extern uint8_t keystop1;
extern uint8_t keystop2;
extern uint8_t usartstop1;
extern uint8_t usartstop2;

void pwm_in1() {
	uint32_t value1 = HAL_TIM_ReadCapturedValue(&htim3, TIM_CHANNEL_1);
	
	if (mode == 0 && keystop1 == 0) {
		freq1 = 80000000 / (80 * value1);
	
		TIM3->CNT = 0;
	}
	
	else if (mode == 1 && usartstop1 == 0) {
		freq1 = 80000000 / (80 * value1);
	
		TIM3->CNT = 0;
	}
}

void pwm_in2() {
	uint32_t value2 = HAL_TIM_ReadCapturedValue(&htim2, TIM_CHANNEL_1);
	
	if (mode == 0 && keystop2 == 0 ) {
		freq2 = 80000000 / (80 * value2);
	
		TIM2->CNT = 0;
	}
	
	else if (mode == 1 && usartstop2 == 0) {
		freq2 = 80000000 / (80 * value2);
	
		TIM2->CNT = 0;
	}
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim) {
	if (htim == &htim3) {
		pwm_in1();
	}
	else if (htim == &htim2) {
		pwm_in2();
	}
}