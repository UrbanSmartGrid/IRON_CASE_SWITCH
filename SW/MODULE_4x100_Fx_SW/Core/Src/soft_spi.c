#include "def.h"


/******************************************************************************/
void SPI_WRITE(uint8_t data, uint8_t length)
{
	while(length)
	{
		CLK_LOW
		
		if(data&0x80)
			MOSI_HIGH
		else
			MOSI_LOW
				
		CLK_HIGH
			
		length--;
		data <<= 1;
	}
}


/******************************************************************************/
void SPI_READ(uint8_t *data, uint8_t length)
{
	*data = 0;
	
	while(length)
	{
		CLK_LOW
			
		if(MISO_VALUE == GPIO_PIN_SET)
			*data |= 0x01;
			
		CLK_HIGH
			
		length--;			
			
		if(length==0)
			break;
			
		*data <<= 1;
	}
}


/******************************************************************************/
uint8_t ReadWriteReg(PORT port, SPI_COMMAND command, uint8_t reg, uint8_t value)
{
	uint8_t ret_value = 0;
	
	
	CLK_HIGH
	
	switch(port)
	{
		//---------------------------//
		case PORT0:	CS_P0_SELECT	break;
		//---------------------------//
		case PORT1:	CS_P1_SELECT	break;
		//---------------------------//
		case PORT2:	CS_P2_SELECT	break;
		//---------------------------//
		case PORT3:	CS_P3_SELECT	break;
	}
	
	
	switch(command)
	{
		//---------------------------//
		case SPI_CMD_WR:
		{
			SPI_WRITE(0x40, 7);
			SPI_WRITE(reg, 8);
			
			// TR
			CLK_LOW
			CLK_HIGH
			
			SPI_WRITE(value, 8);
		}
		break;
		//---------------------------//
		case SPI_CMD_RD:
		{
			SPI_WRITE(0x60, 7);
			SPI_WRITE(reg, 8);
			
			// TR
			CLK_LOW
			CLK_HIGH
				
			SPI_READ(&value, 8);
			
			ret_value = value;			
		}
		break;
	}
	
	CS_P0_DESELECT
	CS_P1_DESELECT
	CS_P2_DESELECT
	CS_P3_DESELECT
	
		
	return ret_value;
}

