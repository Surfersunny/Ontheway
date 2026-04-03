#ifndef __UART_H
#define __UART_H

#include "usart.h"

void uart_duty();

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

#endif