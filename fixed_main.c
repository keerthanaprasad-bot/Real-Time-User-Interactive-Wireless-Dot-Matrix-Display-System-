#include <LPC21xx.H>

#include "fixed_string.h"
#include "sipo_74hc164.h"

//#define DBUG
int main()
{
	Init_SIPO();
	Init_dotmatrix();
	while(1)
	{
		display_str("ARIF",500);
		//display_str("MAHI",500);
	}
}
