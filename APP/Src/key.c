#include "key.h"

uint8_t page = 0;
uint8_t mode = 0;

uint8_t keystop1 = 0;
uint8_t keystop2 = 0;

float PF = 1000.0;

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
				page = (page + 1) % 2;
				flag1 = 0;
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
				mode = (mode + 1) % 2;
				flag2 = 0;
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
				if (page == 0 && mode == 0) keystop1 = (keystop1 + 1) % 2;
				else if (page == 1) {
					if (fabs(PF - 10000.0) < 0.01) PF = 1000.0;
					else PF += 1000.0;
				}
				flag3 = 0;
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
				if (page == 0 && mode == 0) keystop2 = (keystop2 + 1) % 2;
				else if (page == 1) {
					if (fabs(PF - 1000.0) < 0.01) PF = 10000.0;
					else PF -= 1000.0;
				}
				flag4 = 0;
			}
			break;
	}
}
	