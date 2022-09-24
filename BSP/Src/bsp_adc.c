#include "bsp_adc.h"

#include "adc.h"

void BSP_ADC_Init(void)
{
    osDelay(100);
    HAL_ADCEx_Calibration_Start(&hadc1, ADC_CALIB_OFFSET, ADC_SINGLE_ENDED);
    HAL_ADCEx_Calibration_Start(&hadc2, ADC_CALIB_OFFSET, ADC_SINGLE_ENDED);
    HAL_ADCEx_Calibration_Start(&hadc3, ADC_CALIB_OFFSET, ADC_SINGLE_ENDED);
    
    for(int i = 0;i < 5;i++)
    {
        //Refresh Data 5 times in order to make sure the correct data is gotten
        BSP_Get_BatteryVot();
        BSP_Get_BatteryCur();
        BSP_Get_CoreTempature();
        osDelay(50);
    }
}
    

void BSP_Get_CoreTempature(void)
{
    uint16_t adc_val;
    uint16_t TS_CAL1;
	uint16_t TS_CAL2;
    float temp;
    HAL_ADC_Start(&hadc3);
    HAL_ADC_PollForConversion(&hadc3,100);
    adc_val = HAL_ADC_GetValue(&hadc3);
    TS_CAL1 = *(__IO uint16_t *)(0x1FF1E820);
    TS_CAL2 = *(__IO uint16_t *)(0x1FF1E840);
    temp = ((110.0f - 30.0f) / (TS_CAL2 - TS_CAL1)) * (adc_val - TS_CAL1) + 30.0f;
    SystemState.core_temp = temp;
}

void BSP_Get_BatteryVot(void)
{
    uint16_t adc_val;
    float vot;
    //CV
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1,100);
    adc_val = HAL_ADC_GetValue(&hadc1);
    vot = adc_val * (3.3f/65535.0f);
    SystemState.battery_vot = vot*2;
}

void BSP_Get_BatteryCur(void)
{
    uint16_t adc_val;
    float cur;
    //CV
    HAL_ADC_Start(&hadc2);
    HAL_ADC_PollForConversion(&hadc2,100);
    adc_val = HAL_ADC_GetValue(&hadc2);
    cur = adc_val * (3.3f/65535.0f);
    cur = (cur/590)*400;
    SystemState.battery_cc = cur;
}
