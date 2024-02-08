/**
 Interfacing DS18B20 KY-001 Temperature sensor using nrf52840dk and reading temperature value in serial Terminal
 @author: Vishnu Priya P
 @PSno: 40019211
 @date: 6.11.2023
*/


#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include "D:/VISHNUPRIYA_WORKSPACE-1/zephyr-v3.2.0/zephyr/include/zephyr/drivers/adc.h"
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/printk.h>
#include "D:/VISHNUPRIYA_WORKSPACE-1/SDK52_DeviceDownload/nRF5_SDK_17.1.0_ddde560/modules/nrfx/hal/nrf_saadc.h"
#include "D:/VISHNUPRIYA_WORKSPACE-1/zephyr-v3.2.0/modules/hal/nordic/nrfx/hal/nrf_gpio.h"

#include "ky026.cpp"
#include "ky026.h"

int main(void)
{
		ky026 ky026;
		int err;
		struct adc_channel_cfg a= {
			.gain = ADC_GAIN,
			.reference = ADC_REFERENCE,
			.acquisition_time = ADC_ACQ_TIME_DEFAULT,
			.channel_id = ADC_CHANNEL,
			#ifdef CONFIG_ADC_NRFX_SAADC
			.input_positive = ADC_PORT
			#endif
		};

		struct adc_sequence s ={
			/*individual channels will be added below*/
			.channels = BIT(ADC_CHANNEL),
			.buffer = sample_buffer,
			/*buffer size in bytes*/
			.buffer_size = sizeof(sample_buffer),
			.resolution = ADC_RESOLUTION,	
		};

	static const struct device *adc_dev = DEVICE_DT_GET(ADC_NODE);
	
	if(!device_is_ready(adc_dev)){
		printk("adc_dev is not ready\n\r"); //ADC IS NOT READY
	}
	//ky026::adc_channel; 
	//int adc_fun = ky026.adc_channel();
	err=adc_channel_setup(adc_dev, &a);
	//err = adc_channel_setup(adc_dev,ky026.adc_channel->&ch0_cfg);
	if(err != 0)
	{
		printk("adc_channel_setup failed with error %d.\n\r", err); //err not equal to 0
		return 0;

	}

	while (1) 
	{
		/*ADC Read API for checking ADC read is suceess or fail*/
		//ky026::adc_sequence_1;
		//int sequence_fun = ky026.adc_sequence_1();
		err = adc_read(adc_dev, &s);
		//err = adc_read(adc_dev, ky026.adc_sequence_1->sequence);
		if(err !=0){
			printk("ADC reading failed with error %d.\n\r",err);
			return 0;
		}


		//To get RAW Analog value from buffer and printing to check the Analog range of flame sensor
		int32_t mv_value = sample_buffer[0];
		printk("ADC - Value: %d \n\r", mv_value );
		//printk("%d \n\r", mv_value );
		//To get Voltage value and printing to check the Analog range
		int32_t adc_vref = adc_ref_internal(adc_dev);
		adc_raw_to_millivolts(adc_vref, ADC_GAIN, ADC_RESOLUTION, &mv_value);//conversion of raw analog values to milli volts
		printk("ADC - Voltage:  %d mV\n\r",mv_value);
		
		//Threshold set to if flame is detected or not
		if (mv_value < 1500) {
    	printk("fire detected : %d mV\n\r",mv_value);
		}
		else{
		printk("fire not detected : %d mV\n\r",mv_value);
		}
	

		
		// Initialize LED pin as output
    	
	
    	// Check the status of a pin (example: pin 12)

		//checking status of PIN0.12 (D0) if its HIGH or LOW
    	if (nrf_gpio_pin_read(12)) {
    	printk("Digital Pin (D0) - P0.12 is HIGH\n\r");
		
		// Turn on the LED on pin 13
		nrf_gpio_cfg_output(LED_PIN);
		nrf_gpio_pin_set(LED_PIN);
		}
    	// } 
		else {
    	printk("Digital Pin (D0) - P0.12 is LOW\n\r");
		// Initialize LED pin as output
    	
    	}
		k_msleep(SLEEP_TIME_MS);
		printk("-------------------------------------------------------------------------------------------------------------\n\r");
    	// return;
		// k_msleep(SLEEP_TIME_MS);
	}
}

