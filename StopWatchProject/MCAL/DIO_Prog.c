#include "StdTypes.h"
#include "MemMap.h"
#include "DIO_Int.h"
#include "DIO_Priv.h"
#include "DIO_Cfg.h"


void DIO_Init(void)
{
	DIO_Pin_t i;
	for(i=PINA0;i<TOTAL_PINS;i++)
	{
		DIO_InitPin(i,DIO_PinsStatusArray[i]);
	}
	
}



// static void DIO_InitPin(DIO_Pin_t pin,DIO_PinStatus_t status)
// {
// 	DIO_Port_t port=pin/8;
// 	u8 pin_num=pin%8;
// 	switch(status)
// 	{
// 		case OUTPUT:
// 		switch(port)
// 		{
// 			case PA:
// 			SET_BIT(DDRA,pin_num);
// 			CLR_BIT(PORTA,pin_num);
// 			break;
// 			case PB:
// 			SET_BIT(DDRB,pin_num);
// 			CLR_BIT(PORTB,pin_num);
// 			break;
// 			case PC:
// 			SET_BIT(DDRC,pin_num);
// 			CLR_BIT(PORTC,pin_num);
// 			break;
// 			case PD:
// 			SET_BIT(DDRD,pin_num);
// 			CLR_BIT(PORTD,pin_num);
// 			break;
// 		}
// 		break;
// 		case INFREE:
// 		switch(port)
// 		{
// 			case PA:
// 			CLR_BIT(DDRA,pin_num);
// 			CLR_BIT(PORTA,pin_num);
// 			break;
// 			case PB:
// 			CLR_BIT(DDRB,pin_num);
// 			CLR_BIT(PORTB,pin_num);
// 			break;
// 			case PC:
// 			CLR_BIT(DDRC,pin_num);
// 			CLR_BIT(PORTC,pin_num);
// 			break;
// 			case PD:
// 			CLR_BIT(DDRD,pin_num);
// 			CLR_BIT(PORTD,pin_num);
// 			break;
// 		}
// 		break;
// 		case INPULL:
// 		switch(port)
// 		{
// 			case PA:
// 			CLR_BIT(DDRA,pin_num);
// 			SET_BIT(PORTA,pin_num);
// 			break;
// 			case PB:
// 			CLR_BIT(DDRB,pin_num);
// 			SET_BIT(PORTB,pin_num);
// 			break;
// 			case PC:
// 			CLR_BIT(DDRC,pin_num);
// 			SET_BIT(PORTC,pin_num);
// 			break;
// 			case PD:
// 			CLR_BIT(DDRD,pin_num);
// 			SET_BIT(PORTD,pin_num);
// 			break;
// 		}
// 		break;
// 	}
// }
 volatile u8 *reg[PORT_NUMS][DIO_REG_NUMS]={{&DDRA,&PORTA,&PINA},{&DDRB,&PORTB,&PINB},{&DDRC,&PORTC,&PINC},{&DDRD,&PORTD,&PIND}};
static void DIO_InitPin(DIO_Pin_t pin,DIO_PinStatus_t status)
{
	 DIO_Port_t port=pin/8;
	 u8 pin_num=pin%8;
	switch(status)
	{
		case OUTPUT:
		SET_BIT(*(reg[port][0]),pin_num);
		CLR_BIT(*(reg[port][1]),pin_num);
		break;
		case INFREE:
		CLR_BIT(*(reg[port][0]),pin_num);
		CLR_BIT(*(reg[port][1]),pin_num);
		break;
		case INPULL:
		CLR_BIT(*(reg[port][0]),pin_num);
		SET_BIT(*(reg[port][1]),pin_num);
		break;
	}
}

void DIO_WritePin(DIO_Pin_t pin,DIO_PinVoltage_t volt)
{
	DIO_Port_t port=pin/8;
	u8 pin_num=pin%8;
	switch(volt)
	{
		case HIGH:
		switch(port)
		{
			case PA:
		
			SET_BIT(PORTA,pin_num);
			break;
			case PB:
			
			SET_BIT(PORTB,pin_num);
			break;
			case PC:
			
			SET_BIT(PORTC,pin_num);
			break;
			case PD:
			
			SET_BIT(PORTD,pin_num);
			break;
		}
		break;
		case LOW:
		switch(port)
		{
			case PA:
			
			CLR_BIT(PORTA,pin_num);
			break;
			case PB:
		
			CLR_BIT(PORTB,pin_num);
			break;
			case PC:
			
			CLR_BIT(PORTC,pin_num);
			break;
			case PD:
			
			CLR_BIT(PORTD,pin_num);
			break;
		}
		break;
	}
}

DIO_PinVoltage_t DIO_ReadPin(DIO_Pin_t pin)
{
	DIO_Port_t port=pin/8;
	u8 pin_num=pin%8;
	DIO_PinVoltage_t volt=LOW;
	
	switch(port)
	{
		case PA:
		
		volt=READ_BIT(PINA,pin_num);
		break;
		case PB:
		
		volt=READ_BIT(PINB,pin_num);
		break;
		case PC:
		
		volt=READ_BIT(PINC,pin_num);
		break;
		case PD:
		
		volt=READ_BIT(PIND,pin_num);
		break;
	}
	
	return volt;
	
	
}



void DIO_TogglePin(DIO_Pin_t pin)
{
	DIO_Port_t port=pin/8;
	u8 pin_num=pin%8;
	
	switch(port)
	{
		case PA:
		
		TOG_BIT(PORTA,pin_num);
		break;
		case PB:
		
		TOG_BIT(PORTB,pin_num);
		break;
		case PC:
		
		TOG_BIT(PORTC,pin_num);
		break;
		case PD:
		
		TOG_BIT(PORTD,pin_num);
		break;
	}
	
	
}

void DIO_WritePort(DIO_Port_t port,u8 data)
{
	switch(port)
	{
		case PA:
		PORTA=data;
		break;
		case PB:
		PORTB=data;
		break;
		case PC:
		
		PORTC=data;
		break;
		case PD:
		
		PORTD=data;
		break;
	}
	
}

u8 DIO_ReadPort(DIO_Port_t port)
{
	u8 data=0;
	switch(port)
	{
		case PA:
		data=PORTA;
		break;
		case PB:
		data=PORTB;
		break;
		case PC:
		
		data=PORTC;
		break;
		case PD:
		
		data=PORTD;
		break;
	}
	return data;
	
}