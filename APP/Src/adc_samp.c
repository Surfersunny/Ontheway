#include "adc_samp.h"

float temperature;

void get_temperature() {
	HAL_ADC_Start(&hadc2);
	
	uint32_t num = HAL_ADC_GetValue(&hadc2);
	
	float adc_val = num / 4095.0 * 3.3; 
	
	if (adc_val < 0.3) temperature = 0;
	
	else if (adc_val >= 0.3 && adc_val <= 3.0) temperature = (80.0 / 2.7) * (adc_val - 0.3);
	
	else temperature = 80.0;
}