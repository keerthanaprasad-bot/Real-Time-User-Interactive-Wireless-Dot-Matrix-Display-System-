#include <LPC21xx.h>
#include "fixed_string.h"
#include "defines.h"
#include "delay.h"
char rx_data = 0;
int tx_index = 0;

char menu[] =
"\r\n------ DOT MATRIX MENU ------\r\n"
"1. FIXED STRING\r\n"
"2. FIXED STRING WITH BLINKING\r\n"
"3. STRING WITH SCROLLING\r\n"
"4. TIME DISPLAY\r\n"
"5. RTC DISPLAY WITH SCROLLING\r\n"
"6. TEMPERATURE DISPLAY\r\n"
"7. TEXT EDIT MODE\r\n"
"8. TIME EDIT MODE\r\n"
"9. EXIT\r\n"
"Enter Choice:\r\n";

void UART0_ISR(void) __irq
{
    unsigned int iir;

    iir = U0IIR;

    // RX interrupt
    if((iir & 0x04) == 0x04)
    {
        rx_data = U0RBR;
    }
    // TX interrupt
    if((iir & 0x02) == 0x02)
    {
        if(menu[tx_index] != '\0')
        {
            U0THR = menu[tx_index++];
        }
    }

    VICVectAddr = 0;
}

void fixed_string()
{
    display_str("ARIF",500);
}

void blinking_string()
{    
	  //Display ARIF
    display_str("ARIF",500);

		//Turn OFF display
		CLEARBYTE(IOCLR0,0xFF);   //rows off
		delay_ms(300);
}

void scrolling_string()
{
	 
	  u8 i,user_str[] = "   V25HE4 BATCH IS TOOO GOOD BATCH!   ";
    for(i=0;i<38-3;i++)
		{
				display_str(user_str+i,10);
		}		
}
void UART_SendMenu()
{
    tx_index = 0;
    U0THR = menu[tx_index++];
}
