#include "key.h"
#include "math.h"

uint8_t page = 0;
uint32_t freq = 1000;
float VP1 = 0.3;

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
			if (state2 == 1 && page == 1) {
				if (fabs(VP1 - 3.3) <= 0.1) VP1 = 0;
				else VP1 = VP1 + 0.3;
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
			if (state3 == 1 && page == 0) {
				if (freq == 10000) freq = 1000;
				else freq = freq + 1000;
				flag3 = 0;
			}
			break;
	}
}