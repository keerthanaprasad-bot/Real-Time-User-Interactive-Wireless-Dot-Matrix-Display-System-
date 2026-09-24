#include <LPC21xx.H>


//#include "dotmatrix_driver.h"

#include "sipo_74hc164.h"
#include "types.h"


void Init_SIPO(void);

void Init_dotmatrix_anodes(void);
//display_str(user_str+i,);
void display_char(u8 ch,u32 delay,u8);
void display_str(u8 *str,u32 delay);

//#define DBUG


int main()

{

	u8 i;
	u8 user_str[]="   V25HE4 BATCH IS TOOO GOOD BATCH!   ";

	Init_SIPO();

	Init_dotmatrix_anodes();

	while(1)

	{

		#ifdef DEBUG

		display_char('A',500,DM1);

		display_char('V',500,DM3);

		display_char('H',500,DM2);

		display_char('Z',500,DM4);

		display_str("HELP",500);

		display_str("LUCK",500);

		display_str("LOCK",500);

		#endif

		for(i=0;i<38-3;i++)

		{
			display_str(user_str+i,10);
			}
		}
	}
