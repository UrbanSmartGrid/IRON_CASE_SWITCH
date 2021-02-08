#ifndef	__DEF_H__
#define	__DEF_H__


#include "stdbool.h"
#include "main.h"


// HW reset
#define		SYS_RESET_H		HAL_GPIO_WritePin(SYS_RESET_GPIO_Port, SYS_RESET_Pin, GPIO_PIN_SET);
#define		SYS_RESET_L		HAL_GPIO_WritePin(SYS_RESET_GPIO_Port, SYS_RESET_Pin, GPIO_PIN_RESET);



typedef struct
{
	//---------------------//
	// временные метки
	bool	_10ms_event;
	bool	_100ms_event;
	bool	_500ms_event;
	bool	_1000ms_event;
	//---------------------//

} TIME_EVENTS;


/********************************************************************************************/
//                                    S O F T   S P I                                       //
/********************************************************************************************/
typedef	enum {PORT0, PORT1, PORT2, PORT3} PORT; 
typedef	enum {SPI_CMD_WR, SPI_CMD_RD} SPI_COMMAND;

#define	CS_P0_SELECT			HAL_GPIO_WritePin(CS_P0_GPIO_Port, CS_P0_Pin, GPIO_PIN_RESET);
#define	CS_P0_DESELECT			HAL_GPIO_WritePin(CS_P0_GPIO_Port, CS_P0_Pin, GPIO_PIN_SET);

#define	CS_P1_SELECT			HAL_GPIO_WritePin(CS_P1_GPIO_Port, CS_P1_Pin, GPIO_PIN_RESET);
#define	CS_P1_DESELECT			HAL_GPIO_WritePin(CS_P1_GPIO_Port, CS_P1_Pin, GPIO_PIN_SET);

#define	CS_P2_SELECT			HAL_GPIO_WritePin(CS_P2_GPIO_Port, CS_P2_Pin, GPIO_PIN_RESET);
#define	CS_P2_DESELECT			HAL_GPIO_WritePin(CS_P2_GPIO_Port, CS_P2_Pin, GPIO_PIN_SET);

#define	CS_P3_SELECT			HAL_GPIO_WritePin(CS_P3_GPIO_Port, CS_P3_Pin, GPIO_PIN_RESET);
#define	CS_P3_DESELECT			HAL_GPIO_WritePin(CS_P3_GPIO_Port, CS_P3_Pin, GPIO_PIN_SET);


#define	CLK_HIGH				HAL_GPIO_WritePin(SCK_GPIO_Port, SCK_Pin, GPIO_PIN_SET);
#define	CLK_LOW					HAL_GPIO_WritePin(SCK_GPIO_Port, SCK_Pin, GPIO_PIN_RESET);

#define	MOSI_HIGH				HAL_GPIO_WritePin(MOSI_GPIO_Port, MOSI_Pin, GPIO_PIN_SET);
#define	MOSI_LOW				HAL_GPIO_WritePin(MOSI_GPIO_Port, MOSI_Pin, GPIO_PIN_RESET);

#define	MISO_VALUE				HAL_GPIO_ReadPin(MISO_GPIO_Port, MISO_Pin)



/********************************************************************************************/
//                               KSZ8863 REGISTER ADDRESS                                   //
/********************************************************************************************/
#define	REG_CHIP_ID1	0x01



#endif // __DEF_H__