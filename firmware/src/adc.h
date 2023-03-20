
#ifndef _ADC_H    /* Guard against multiple inclusion */
#define _ADC_H

#include "config/sam_e54_xpro_freertos/peripheral/adc/plib_adc0.h"
#include "configuration.h"
#include "definitions.h"
#define adc_diff 10
#define adc_flag_1 352
#define adc_flag_2 768
#define adc_flag_3 1472
#define adc_flag_4 2304
#define adc_flag_5 2944
#define adc_flag_6 3664

#ifdef __cplusplus
extern "C" {
#endif



//void ADC0_EventHandler(ADC0_STATUS status, uintptr_t context);
void ADC0_EventHandler(ADC0_STATUS *status);



#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */
