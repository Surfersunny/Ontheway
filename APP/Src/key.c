#include "key.h"

uint8_t lock = 0;

void key_proc() {
	static uint8_t flag = 0;
		
	uint8_t state = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0);
	
	switch (flag) {
		case 0:
			if (state == 0)
				flag = 1;
			break;
		case 1:
			if (state == 0)
				flag = 2;
			break;
		case 2:
			if (state == 1) {
				lock = (lock + 1) % 2;
				flag = 0;
			}
			break;
	}
}