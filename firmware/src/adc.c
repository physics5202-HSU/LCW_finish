#include "adc.h"
#include "lcw.h"
//uint8_t lcw_value[7]={138,178,201,218,231,242,251}; log10
//uint8_t lcw_value[7]={138,142,146,151,155,167,248};
uint8_t lcw_value[7]={138,147,150,154,161,177,248};
//void ADC0_EventHandler(ADC0_STATUS status, uintptr_t context)
void ADC0_EventHandler(ADC0_STATUS *status)
{
    //0x0130[304] ~ 0x0fff[4095]
    volatile ADC0_STATUS pre_status=*status; 
    if(ADC0_ConversionStatusGet())
    {
        uint16_t v_adc=ADC0_ConversionResultGet();
        if (v_adc < adc_flag_1-adc_diff)
        {
            *status=ADC0_TRANSFER_STATUS_LV_0;
        }
        else if (v_adc >= adc_flag_1-adc_diff && v_adc < adc_flag_1+adc_diff)
        {}//do not distinguish
        else if (v_adc >= adc_flag_1+adc_diff && v_adc < adc_flag_2-adc_diff)
        {
            *status=ADC0_TRANSFER_STATUS_LV_1;
        }
        else if (v_adc >= adc_flag_2-adc_diff && v_adc < adc_flag_2+adc_diff)
        {}//do not distinguish
        else if (v_adc >= adc_flag_2+adc_diff && v_adc < adc_flag_3-adc_diff)
        {
            *status=ADC0_TRANSFER_STATUS_LV_2;
        }
        else if (v_adc >= adc_flag_3-adc_diff && v_adc < adc_flag_3+adc_diff)
        {}//do not distinguish
        else if (v_adc >= adc_flag_3+adc_diff && v_adc < adc_flag_4-adc_diff)
        {
            *status=ADC0_TRANSFER_STATUS_LV_3;
        }
        else if (v_adc >= adc_flag_4-adc_diff && v_adc < adc_flag_4+adc_diff)
        {}//do not distinguish
        else if (v_adc >= adc_flag_4+adc_diff && v_adc < adc_flag_5-adc_diff)
        {
            *status=ADC0_TRANSFER_STATUS_LV_4;
        }
        else if (v_adc >= adc_flag_5-adc_diff && v_adc < adc_flag_5+adc_diff)
        {}//do not distinguish
        else if (v_adc >= adc_flag_5+adc_diff && v_adc < adc_flag_6-adc_diff)
        {
            *status=ADC0_TRANSFER_STATUS_LV_5;
        }
        else if (v_adc >= adc_flag_6-adc_diff && v_adc < adc_flag_6+adc_diff)
        {}//do not distinguish
        else if (v_adc >= adc_flag_6+adc_diff)
        {
            *status=ADC0_TRANSFER_STATUS_LV_6;
        }
        if (pre_status != *status)
        {
            //SYS_CONSOLE_PRINT("ADC_Value= 0x%04x [ %d -> %d]\r\n",v_adc,pre_status,*status);
            //SYS_CONSOLE_PRINT("ADC_Value= %d [ %d -> %d]\r\n",v_adc,pre_status,*status);
            //LCW_Brightness(Driving_Board_1_CTRL_ADDR,lcw_value[*status-1]);
            LCW_Brightness(Driving_Board_1_CTRL_ADDR,lcw_value[abs(*status-7)]);
        }      
        //SYS_CONSOLE_PRINT("ADC_Value= 0x%04x [%d]\r\n",v_adc,*status)
        //SYS_CONSOLE_PRINT("ADC_Value= %d [%d]\r\n",v_adc,*status);
    }
}