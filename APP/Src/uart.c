#include "uart.h"

uint8_t password1 = 1;
uint8_t password2 = 2;
uint8_t password3 = 3;

uint8_t data[7];

void set_password() {
	HAL_UART_Receive_IT(&huart1, data ,7);
	
	if (data[0] - '0' == password1 && data[1] - '0' == password2 && data[2] - '0' == password3 && data[3] == '-'
		&& '0' <= data[4] && data[4] <= '9' &&  '0' <= data[5] && data[5] <= '9' &&  '0' <= data[6] && data[6] <= '9') {
		password1 = data[4] - '0';
		password2 = data[5] - '0';
		password3 = data[6] - '0';
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	if (huart == &huart1) set_password();
}