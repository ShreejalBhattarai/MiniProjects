//7-seg control register
#define SEG_CTL  *((uint32_t *) 0x43c10000)

//7-seg digit data register
#define SEG_DATA *((uint32_t *) 0x43C10004)

//7-seg decimal point data reg
#define SEG_DP *((uint32_t *) 0x43C10014)

// Displays the passed 16-bit value on the 7-seg in hexidecimal
void display_num(uint16_t n)
{
	int i=0;
	uint32_t temp=0;

	//set display enabled in standard (hex) mode
	SEG_CTL = 1;

	for(i=0;i<4;i++)
	{
		temp |= (n&0xF)<<(i*8); //put digit data in appropriate bitfield
		n>>=4; //shift out least significant digit
	}

	//disable all decimal points
	temp|=0x80808080;

	SEG_DATA = temp;

}

#include <stdint.h>
/*********
 
 _
| 

Segments Illuminated: E,G
Value to write to Data register: 0b0101111 == 0x2F

 _
|_
|_

Segments Illuminated: A,D,E,F,G
Value to write to Data register: 0b0000110 == 6

 _
|_|
| |

Segments Illuminated: A,B,C,E,F,G
Value to write to Data register: 0b0001000 == 8
 
|
|_

Segments Illuminated: D,E,F
Value to write to Data register: 0b1000111 == 0x47

*********/

#define R_DIG 0x2F
#define E_DIG 6
#define A_DIG 8
#define L_DIG 0x47


//Displays "rEAL" on the 7-seg disp using the numbers calculated above
void display_REAL(void)
{
	//temporary variable used so we only write to the seg data_reg once
	uint32_t temp;
	SEG_CTL = 3; //enable display in custom mode

	//clear data in register
	temp = 0;

	//write digit data to corresponding bitfields
	temp |= R_DIG<<24; //bits 30-24
	temp |= E_DIG<<16; //bits 22-16
	temp |= A_DIG<<8; //bits 14-8
	temp |= L_DIG; //bits 6-0

	//disable all decimal points
	temp|=0x80808080;


	//write to segment data register
	SEG_DATA = temp;
}

#define SW_DATA		*((uint32_t *)0x41220000)
#define BTN_DATA	*((uint32_t *)0x41200000)


int main(void)
{

	for(;;)
	{
		if(BTN_DATA&1) //if first button is pressed
			display_REAL(); //display "rEAL"
		else
			display_num(SW_DATA&0xFFF); //display Switch value
	}


	return 1;

}