#include "uart.h"

char buff[30];
char temp_buff[30];
uint8_t rxflag = 0;
char s1[20];

uint8_t usartstop1 = 0;
uint8_t usartstop2 = 0;

extern uint8_t mode;
extern float freq1;
extern float freq2;

void uart_proc() {
	if (rxflag == 1) {
		if (mode == 0) HAL_UART_Transmit_IT(&huart1, (uint8_t*)"NULL", 4);
	
		else {
			if (strlen(temp_buff) == 3) {
				if (temp_buff[0] == 'T' && temp_buff[1] == 'F' && temp_buff[2] == '1') usartstop1 = 0;
				else if (temp_buff[0] == 'T' && temp_buff[1] == 'F' && temp_buff[2] == '2') usartstop2 = 0;
				else if (temp_buff[0] == 'P' && temp_buff[1] == 'F' && temp_buff[2] == '1') usartstop1 = 1;
				else if (temp_buff[0] == 'P' && temp_buff[1] == 'F' && temp_buff[2] == '2') usartstop2 = 1;
				else HAL_UART_Transmit_IT(&huart1, (uint8_t*)"NULL", 4);
			}
			
			else if (strlen(temp_buff) == 2) {
				if (temp_buff[0] == 'F' && temp_buff[1] == '1') {
					sprintf(s1, "F1:%dHz", (int)freq1);
					HAL_UART_Transmit_IT(&huart1, (uint8_t*)s1, strlen(s1));
				}
				else if (temp_buff[0] == 'F' && temp_buff[1] == '2') {
					sprintf(s1, "F2:%dHz", (int)freq2);
					HAL_UART_Transmit_IT(&huart1, (uint8_t*)s1, strlen(s1));
				}
				else HAL_UART_Transmit_IT(&huart1, (uint8_t*)"NULL", 4);
			}
			
			else HAL_UART_Transmit_IT(&huart1, (uint8_t*)"NULL", 4);
			}
		
		// Remember to zero!
		memset(temp_buff, 0, sizeof(temp_buff));
		rxflag = 0;
	}
}

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size) {
	if (huart == &huart1) {		
		rxflag = 1;
		
		memcpy(temp_buff, buff, strlen(buff));
		
		// Remember to zero!
		memset(buff, 0, sizeof(buff));
		
		HAL_UARTEx_ReceiveToIdle_DMA(huart, (uint8_t*)buff, 30);
	}
}