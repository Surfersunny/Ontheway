#include "pwm_out.h"

extern uint8_t mode;
extern uint8_t old_mode;
extern uint8_t duty;

extern uint8_t change;
extern uint8_t lowtohigh;

uint8_t time_count = 0;

void pwm_out() {
	// Not switched:change duty
	if (change == 0) {
		__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_2, 250 * duty / 100);
		time_count = 0;
	}
		
	// Switched:change freq
	else if (change == 1 && lowtohigh == 1) {
				// 1. ??????
        //HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_2);
        
        // 2. ??????
        __HAL_TIM_PRESCALER(&htim2, 80000000 / (250 * (4000 + 80 * time_count)));
        
        // 3. ???????
        //HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
        
        time_count++;
	}
	
	else if (change == 1 && lowtohigh == 0) {
				// 1. ??????
        //HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_2);
        
        // 2. ??????
        __HAL_TIM_PRESCALER(&htim2, 80000000 / (250 * (8000 - 80 * time_count)));
        
        // 3. ???????
        //HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
        
        time_count++;
	}
}