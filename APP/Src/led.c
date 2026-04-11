#include "led.h"

extern uint8_t page;
extern float freq1;
extern float freq2;
extern float PF;
extern uint8_t mode;

void led_show() {
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET);
	
	for (uint8_t i = 3; i < 7; i++) {
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8 << i, GPIO_PIN_SET);
	}
	
	if (page == 0) HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);
	else HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
	
	if (page == 1) HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_RESET);
	else HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET);
	
	if (freq1 < PF && freq2 < PF) HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_10);
	else HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, GPIO_PIN_SET);
	
	if (mode == 1) HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, GPIO_PIN_RESET);
	else HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, GPIO_PIN_SET);
	
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_RESET);
}