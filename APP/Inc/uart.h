#ifndef __UART_H
#define __UART_H

#include "usart.h"

extern uint8_t rx_data;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

#endif