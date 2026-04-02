#include "adc_samp.h"

float adc_1, adc_2;

void adc_meas() {
	// Always Calibrate in the beginning!!!Secure!!!
	HAL_ADCEx_Calibration_Start(&hadc1, ADC_SINGLE_ENDED);
	HAL_ADCEx_Calibration_Start(&hadc2, ADC_SINGLE_ENDED);
	
	HAL_ADC_Start(&hadc1);
	HAL_ADC_Start(&hadc2);
	
	uint16_t num1 = HAL_ADC_GetValue(&hadc1);
	uint16_t num2 = HAL_ADC_GetValue(&hadc2);
	
	adc_1 = num1 / 4095.0 * 3.3;
	adc_2 = num2 / 4095.0 * 3.3;
}