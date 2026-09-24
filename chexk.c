#include <lpc21xx.h>
void delay_ms(unsigned int dly)
{
	dly*=12000;
	while(dly--);
}
int main()
{
	IODIR0|=1<<12;
	while(1)
	{
		IOSET0=1<<12;
		delay_ms(1000);
		IOCLR0=1<<12;
		delay_ms(1000);
	}
}