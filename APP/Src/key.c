#include "key.h"

uint8_t page = 0;
uint8_t change = 0;

uint32_t B2_count = 0;
uint32_t B4_start;

uint8_t mode = 0;
uint8_t old_mode = 0;
uint8_t RorK = 0;

uint8_t R = 1;
uint8_t K = 1;

uint8_t lock = 0;

uint32_t count = 0;

extern float freq;
uint8_t lowtohigh;

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
				page = (page + 1) % 3;
				flag1 = 0;
			}
			break;
	}
	
	static uint8_t flag2 = 0;
	old_mode = mode;
	
	uint8_t state2 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1);
	
	if (page != 1) RorK = 0;
	
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
				if (page == 0 && B2_count == 0) {
					count++;
					B2_count++;
					if (freq < 7000.0) lowtohigh = 1;
					else lowtohigh = 0;
				}
				else if (page == 1) RorK = (RorK + 1) % 2;
				flag2 = 0;
			}
			break;
	}

	if (B2_count > 0 && B2_count < 50) {
		B2_count++;
		change = 1;	
	}
	else if (B2_count == 50) {
		B2_count = 0;
		change = 0;
		mode = (mode + 1) % 2;
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
				if (page == 1) {
					if (RorK == 0) {
						if (R == 10) R = 1;
						else R = R + 1;
					}
					else {
						if (K == 10) K = 1;
						else K = K + 1;
					}
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
			if (state4 == 0) {
				B4_start = HAL_GetTick();
				flag4 = 2;
			}
			break;
		case 2:
			if (state4 == 1) {
				if (page == 1) {
					if (RorK == 0) {
						if (R == 1) R = 10;
						else R = R - 1;
					}
					else {
						if (K == 1) K = 10;
						else K = K - 1;
					}
				}
				else if (page == 0) {
					if (HAL_GetTick() - B4_start >= 2000 && lock == 0) {
						lock = 1;
					}
					else if (lock == 1) lock = 0;
				}
				flag4 = 0;
			}
			break;
	}
}