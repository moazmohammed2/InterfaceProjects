#include "StdTypes.h"
#include "DIO_Int.h"
#include "ECU_Int.h"
#include "ECU_Cfg.h"
#include "ECU_Priv.h"



void SEG_Init(void)
{
	//future use 
}

void SEGMENT_DigActiv(SEG_DIGS_t SegDig)
{
	switch(SegDig)
	{
		case DIG1:
		DIO_WritePin(PINC6,HIGH);
		break;
		case DIG2:
		DIO_WritePin(PINC7,HIGH);
		break;
	}
};

void SEGMENT_DigDeActiv(SEG_DIGS_t SegDig)
{
	switch(SegDig)
	{
		case DIG1:
		DIO_WritePin(PINC6,LOW);
		break;
		case DIG2:
		DIO_WritePin(PINC7,LOW);
		break;
	}
};
void Segment_Display(u8 n)
{
	const u8 arr[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	SEGMENT_DigActiv(DIG1);
	DIO_WritePort(Segment_PORT,arr[n%10]<<1);
	SEGMENT_DigDeActiv(DIG2);
	_delay_ms(1);
	
	SEGMENT_DigActiv(DIG2);
	DIO_WritePort(Segment_PORT,arr[n/10]<<1);
	SEGMENT_DigDeActiv(DIG1);
	_delay_ms(1);
}



BUTTON_STATUS_t BUTTON_Status(BUTTON_t button)
{
	BUTTON_STATUS_t buttonStatus=UNPRESSED;
	
	#if MODE==DIRECT_MODE
	
	if(!DIO_ReadPin(buttonPinsDirectMode[button]))
	{
		buttonStatus=PRESSED;
	}
	else
	{
		buttonStatus=UNPRESSED;
	}
	#elif MODE==MATRIX_MODE
	{
		//Postponed 
	}	
#endif


	return buttonStatus;
	
}



//relay 
//Make sure than the switch is on the hardware side 
void RELAY_On(RelayNum_t relay)
{
	switch(relay)
	{
		case RELAY1:
		{
			DIO_WritePin(PINC4,HIGH);
		}
		break;
		case RELAY2:
		{
			DIO_WritePin(PINC3,HIGH);
		}
		break;
	}
}

void RELAY_Off(RelayNum_t relay)
{
	switch(relay)
	{
		case RELAY1:
		{
			DIO_WritePin(PINC4,LOW);
		}
		break;
		case RELAY2:
		{
			DIO_WritePin(PINC3,LOW);
		}
		break;
	}
}