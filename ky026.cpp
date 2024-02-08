#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include "D:/VISHNUPRIYA_WORKSPACE-1/zephyr-v3.2.0/zephyr/include/zephyr/drivers/adc.h"
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/printk.h>
#include "D:/VISHNUPRIYA_WORKSPACE-1/SDK52_DeviceDownload/nRF5_SDK_17.1.0_ddde560/modules/nrfx/hal/nrf_saadc.h"
#include "D:/VISHNUPRIYA_WORKSPACE-1/zephyr-v3.2.0/modules/hal/nordic/nrfx/hal/nrf_gpio.h"

#include "ky026.h"


/*setting buffer for ADC sequence*/
int16_t sample_buffer[1];

ky026::ky026() {

		
		#define SLEEP_TIME_MS   2000  //delay 2 sec
		#define ADC_NODE DT_NODELABEL(adc) //accessing device tree node of ADC
		 //Access device structure and to access node id
		/*setting properties of ADC*/
		#define ADC_RESOLUTION 	12
		#define ADC_CHANNEL     0
		#define ADC_PORT        SAADC_CH_PSELP_PSELP_AnalogInput0	 //PIN on chip P0.02
		#define ADC_REFERENCE   ADC_REF_VDD_1_4 					//REFERENCE VOLTAGE = VDD/4
		#define ADC_GAIN 		ADC_GAIN_1_6                        //gain = ADC_reference / 6 
		#define LED_PIN         13									//GPIO PIN P0.12 set as D0

}
//static const struct device *adc_dev = DEVICE_DT_GET(ADC_NODE);
ky026::~ky026() {

		
		#define SLEEP_TIME_MS   2000  //delay 2 sec
		#define ADC_NODE DT_NODELABEL(adc) //accessing device tree node of ADC
		
		/*setting properties of ADC*/
		#define ADC_RESOLUTION 	12
		#define ADC_CHANNEL     0
		#define ADC_PORT        SAADC_CH_PSELP_PSELP_AnalogInput0	 //PIN on chip P0.02
		#define ADC_REFERENCE   ADC_REF_VDD_1_4 					//REFERENCE VOLTAGE = VDD/4
		#define ADC_GAIN 		ADC_GAIN_1_6                        //gain = ADC_reference / 6 
		#define LED_PIN         13									//GPIO PIN P0.12 set as D0

}


	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

