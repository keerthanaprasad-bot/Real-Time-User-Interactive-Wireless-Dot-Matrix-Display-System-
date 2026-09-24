#include <LPC21xx.H>

#include "fixed_string.h"
#include "sipo_74hc164.h"

//#define DBUG

int main()
{
	Init_SIPO();
	Init_dotmatrix_anodes();

	while(1)
	{
		//Display ARIF
		display_str("ARIF",500);

		//Turn OFF display
		CLEARBYTE(IOCLR0,0xFF);   //rows off
		delay_ms(300);

		//Display MAHI
		display_str("MAHI",500);

		//Turn OFF display
		CLEARBYTE(IOCLR0,0xFF);
		delay_ms(300);
	}
}
