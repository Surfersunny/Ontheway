#include "led.h"

extern uint8_t lock;
extern float adc_1;
extern float adc_2;

void led_show() {
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET);
	
	for (uint8_t i = 1; i < 7; i++) {
			HAL_GPIO_WritePin(GPIOC ,GPIO_PIN_8 << i, GPIO_PIN_SET);
		}
	
	if (lock == 1) {
		HAL_GPIO_WritePin(GPIOC ,GPIO_PIN_8, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC ,GPIO_PIN_15, GPIO_PIN_SET);
	}
	
	if (lock == 0) HAL_GPIO_WritePin(GPIOC ,GPIO_PIN_8, GPIO_PIN_SET);
	
	if (lock == 0 && (adc_1 <= 0.55 || adc_1 >= 2.75 || adc_2 <= 0.55 || adc_2 >= 2.75))  {
		HAL_GPIO_WritePin(GPIOC ,GPIO_PIN_15, GPIO_PIN_RESET);
	}
	else HAL_GPIO_WritePin(GPIOC ,GPIO_PIN_15, GPIO_PIN_SET);
	
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_RESET);
}