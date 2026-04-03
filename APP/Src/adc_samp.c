#include "adc_samp.h"

float VR37;

void adc_meas() {
	HAL_ADCEx_Calibration_Start(&hadc2, ADC_SINGLE_ENDED);
	
	HAL_ADC_Start(&hadc2);
	
	uint32_t value = HAL_ADC_GetValue(&hadc2);
	
	VR37 = value / 4095.0 * 3.3;
}