#ifndef __UART_H
#define __UART_H

#include "usart.h"

void set_password();

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

#endif