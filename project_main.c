#include <LPC21xx.h>
#include <string.h>
#include "fixed_string.h"
#include "uart_interrupt.h"
#include "spi.h"
#include "defines.h"
#include "types.h"
#include "adc.h"
#include "dot_matrix.h"
#include "adc_defines.h"
#include "spi.h"																	 
#include "spi_eeprom.h"
#include "rtc.h"
void spi_eeprom_load(void);
u8 t;
extern u8 f;
extern u8 tx_index;
extern u8 rx_buf[128];
u8 msg_flag=0;
u8 cnt=0;
extern u8 index_val,new_var,ch,t_flag,r_flag,rec_buff[100],updated_str[100];
int main()
{
        Init_SIPO();
       	Init_SPI0();
       	Init_dotmatrix();
	    UART0_init() ;
        RTC_Init();
        Init_ADC(CH1);
		IODIR0&=~(1<<10);
		IOCLR0=1<<10;
		spi_eeprom_load();
        while(1)
        {
			
			if(f==1)
			{
				f=0;
				if(rec_buff[0]!='!')
				{
					UART0_Str("\r\nInvalid Character\r\n");
					UART0_Str("\r\nEnter ! to Display menu and to change the mode\r\n");	
				}
			}
			if((IOPIN0 & (1<<10)) && cnt==0)
			{
				UART0_Str("\r\nEnter ! to Display menu and to change the mode\r\n");
				cnt=1;
			}
			t = ByteRead_25LC512(0x0001);
				index_val=0;
                if(rec_buff[0]=='!')
                {       r_flag=0;
						f=0;
				        memset(rec_buff,'\0',100);
                        UART_SendMenu();
                        CLEARBYTE(IOCLR0,0xFF);
						index_val=0;
                        while(r_flag!=1);
						r_flag=0;
						f=0;
                        if(rec_buff[0] >= '1' && rec_buff[0]<= '6')
                        {
                               ByteWrite_25LC512(0x0001,rec_buff[0]);
								UART0_Str("\r\nEnter ! to Display menu and to change the mode\r\n");				
							
                        }
						t=rec_buff[0];
						msg_flag=0;
						index_val=0;
                }
               switch(t)
                {
                        case '1':fixed_string();
                                break;

                        case '2':blinking_string();
                              	break;

                        case '3':scrolling_string();
                                break;

                        case '4':display_m_s();
                                break;
 
                        case '5':display_rtc();
                                break;
 
                        case '6': lm35();
								break;

						case '7':text_edit_mode();
								UART0_Str("Text Edited successful\r\n");
								UART0_Str("\r\nEnter ! to Display menu and to change the mode\r\n");
								break;

						case '8':time_edit_mode();
							//	UART0_Str("Time edit successful\r\n");
								UART0_Str("\r\nEnter ! to Display menu and to change the mode\r\n");
								index_val=0;
								break;

						case '9':
								break;
                }
        }
}
