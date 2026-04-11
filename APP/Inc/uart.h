#ifndef __UART_H
#define __UART_H

#include "usart.h"
#include "dma.h"

#include "string.h"

void uart_proc();

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size);

#endif