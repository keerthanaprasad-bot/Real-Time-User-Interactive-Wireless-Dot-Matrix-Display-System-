#include "types.h"
#include "adc.h"
#include "adc_defines.h"
#include "uart.h"
#include "delay.h"
#include "dot_matrix.h"

f32 eAR;
u32 adcDVal;
void Init_SIPO(void);

int main(void) 
{	
	UART0_Init();
  Init_ADC(CH1);
	 Init_SIPO();
   // Init_SPI0();
    Init_dotmatrix();
	
	while(1) 
	{
   /* aR0=Read_ADC(CH1);
		UART0_TxString("Voltage: ");
		UART0_Int(aR0);
		UART0_TxString("\r\n");*/
		
		Read_ADC(CH1,&eAR,&adcDVal);
		
		Displaytemperature(eAR*100,500);

		UART0_TxString("Temp: ");
		UART0_Int(eAR*100);
		UART0_TxString("\r\n");
		delay_ms(1000);

		
	}
}
