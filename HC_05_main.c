#include <LPC21xx.h>
#include "fixed_string.h"
#include "uart.h"
void UART_SendMenu(void);
void fixed_string(void);

void blinking_string(void);

void scrolling_string(void);

extern char rx_data;
//extern int tx_index = 0;


int main()
{
		
    Init_SIPO();
    Init_dotmatrix();

    UART0_Init();


    while(1)
    {
				if(rx_data=='!')
				{
						UART_SendMenu();
					  rx_data=0;
				}
        if(rx_data=='1')
        {
            fixed_string();
            //UART_SendMenu();
            rx_data=0;
        }

        if(rx_data=='2')
        {
            blinking_string();
            //UART_SendMenu();
            rx_data=0;
        }

        if(rx_data=='3')
        {
            scrolling_string();
            //UART_SendMenu();
            rx_data=0;
        }
    }
}
