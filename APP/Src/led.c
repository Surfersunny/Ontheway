#include "led.h"

extern uint8_t page;
extern uint8_t lightup;

void led_show() {
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2 ,GPIO_PIN_SET);
	
	for (uint8_t i = 2; i < 8; i++) {
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8 << i ,GPIO_PIN_SET);
	}
	
	if (page == 1) {
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8 ,GPIO_PIN_RESET);
	}
	else HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8 ,GPIO_PIN_SET);
	
	if (lightup == 1) {
		HAL_GPIO_TogglePin(GPIOC ,GPIO_PIN_9);
	}
	else HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9 ,GPIO_PIN_SET);
	
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2 ,GPIO_PIN_RESET);
}