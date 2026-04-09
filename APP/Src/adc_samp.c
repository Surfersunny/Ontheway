#include "adc_samp.h"

extern uint8_t lock;

uint8_t duty;

void duty_set() {
	HAL_ADCEx_Calibration_Start(&hadc2, ADC_SINGLE_ENDED);
	
	HAL_ADC_Start(&hadc2);
	
	uint32_t num = HAL_ADC_GetValue(&hadc2);
	
	float temp = num / 4095.0 * 3.3;
	
	if (lock == 0) {
		if (temp <= 1) duty = 10;
	
		else if (1 <= temp && temp <= 3) duty = (uint8_t)(37.5 * temp - 27.5);

		else duty = 85;
	}
}