#include "key.h"

extern float temperature;

uint8_t UI = 0;
uint8_t mode = 1;
uint16_t rpm = 200;
uint8_t TH = 30;

void key_scan() {
	static uint8_t flag1 = 0;
	
	uint8_t state1 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0);
	
	switch (flag1) {
		case 0:
			if (state1 == 0)
				flag1 = 1;
			break;
		case 1:
			if (state1 == 0)
				flag1 = 2;
			break;
		case 2:
			if (state1 == 1) {
				flag1 = 0;
				mode = (mode + 1) % 2;
			}	
			break;
	}
	
	static uint8_t flag2 = 0;
	
	uint8_t state2 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1);
	
	switch (flag2) {
		case 0:
			if (state2 == 0)
				flag2 = 1;
			break;
		case 1:
			if (state2 == 0)
				flag2 = 2;
			break;
		case 2:
			if (state2 == 1) {
				flag2 = 0;
				
				if (UI == 0 && mode == 1 && rpm <= 900) rpm += 100;

				else if (UI == 1 && TH <= 55) TH += 5;
			}	
			break;
	}
	
	static uint8_t flag3 = 0;
	
	uint8_t state3 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2);
	
	switch (flag3) {
		case 0:
			if (state3 == 0)
				flag3 = 1;
			break;
		case 1:
			if (state3 == 0)
				flag3 = 2;
			break;
		case 2:
			if (state3 == 1) {
				flag3 = 0;
				
				if (UI == 0 && mode == 1 && rpm >= 200) rpm -= 100;

				else if (UI == 1 && TH >= 35) TH -= 5;
			}	
			break;
	}
	
	static uint8_t flag4 = 0;
	
	uint8_t state4 = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
	
	switch (flag4) {
		case 0:
			if (state4 == 0)
				flag4 = 1;
			break;
		case 1:
			if (state4 == 0)
				flag4 = 2;
			break;
		case 2:
			if (state4 == 1) {
				flag4 = 0;
				UI = (UI + 1) % 2;
			}	
			break;
	}
}

void rpm_set() {
	if (mode == 0) {
		if (temperature <= (TH + 5)) {
			rpm = 100;
		}
		else {
			rpm = (uint16_t)((temperature - TH) * 20);
		}
	}
}