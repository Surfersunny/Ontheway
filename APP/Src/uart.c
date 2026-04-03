#include "uart.h"

float duty = 0.1;
char get[1];

void uart_duty() {
	HAL_UART_Receive_IT(&huart1, (uint8_t*)get, 1);
	
	if ('1' <= get[0] && get[0] <= '9') {
		for (uint8_t j = 1; j < 10; j++) {
			if (get[0] - '0' == j) duty = j / 10.0;
		}
	}
	else HAL_UART_Transmit_IT(&huart1, (uint8_t*)"Error", 5);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	if (huart == &huart1) uart_duty();
}