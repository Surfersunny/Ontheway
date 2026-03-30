#include "key.h"

extern uint8_t password1;
extern uint8_t password2;
extern uint8_t password3;

uint8_t page = 0;
uint8_t word1 = 11;
uint8_t word2= 11;
uint8_t word3 = 11;
uint32_t wrong_count = 0;
uint8_t start_count = 0;
uint8_t lightup = 0;

void key_scan() {
	static uint8_t flag1 = 0;
	static uint8_t flag2 = 0;
	static uint8_t flag3 = 0;
	static uint8_t flag4 = 0;
	
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
			if (page == 0 && state1 == 1) {
				flag1 = 0;
				if (word1 == 11) {
					word1 = 0;
				}
				else word1 = (word1 + 1) % 10;
			}
			break;
	}
	
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
			if (page == 0 && state2 == 1) {
				flag2 = 0;
				if (word2 == 11) {
					word2 = 0;
				}
				else word2 = (word2 + 1) % 10;
			}
			break;
	}
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
			if (page == 0 && state3 == 1) {
				flag3 = 0;
				if (word3 == 11) {
					word3 = 0;
				}
				else word3 = (word3 + 1) % 10;
			}
			break;
	}
	
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
			if (page == 0 && state4 == 1) {
				flag4 = 0;
				if (word1 == password1 && word2 == password2 && word3 == password3) {
					page = 1;
					wrong_count = 0;
				}
				else {
					wrong_count++;
					if (wrong_count >= 3) {
						lightup = 1;
					}
				}
			
				word1 = word2 = word3 = 11;
			}
			break;
	}
	
	if (lightup == 1 && start_count < 50) start_count++;
				
	else if (lightup == 1 && start_count == 50) {
		start_count = 0;
		lightup = 0;
	}
				
	if (page == 1 && start_count < 50) start_count++;
				
	else if (page == 1 && start_count == 50) {
		start_count = 0;
		page = 0;
	}
}