#include "uart.h"
#include <string.h>

extern uint8_t mode;
extern float temperature;
extern uint16_t rpm;

uint8_t rx_data;
char tx_buffer[32];

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    if (huart == &huart1) {
        switch (rx_data) {
            case 'M':
                if (mode == 0) 
                    HAL_UART_Transmit_IT(&huart1, (uint8_t*)"Mode:AUTO", 9);
                else 
                    HAL_UART_Transmit_IT(&huart1, (uint8_t*)"Mode:MANU", 9);
                break;
            case 'T':
                sprintf(tx_buffer, "Temp:%.1f", temperature);
                HAL_UART_Transmit_IT(&huart1, (uint8_t*)tx_buffer, strlen(tx_buffer));
                break;
            case 'S':
                sprintf(tx_buffer, "Speed:%drpm", rpm);
                HAL_UART_Transmit_IT(&huart1, (uint8_t*)tx_buffer, strlen(tx_buffer));
                break;
            default:
                HAL_UART_Transmit_IT(&huart1, (uint8_t*)"ERROR", 5);
                break;
        }
        
        HAL_UART_Receive_IT(&huart1, &rx_data, 1);
    }
}