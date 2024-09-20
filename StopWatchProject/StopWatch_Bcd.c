//the 7segment used is 7segment Bcd one 

#include "StdTypes.h"
#include "MemMap.h"

typedef enum{
	NormalMode,
	AdjuctMode
}modeButtStatus_t;
typedef enum{
	Pause,
	Resume
	}firsButtStatus_t;
void Segment_Display_BCD(u8 n)
{
	u8 oneNum=n%10;
	u8 tenNum=n/10;
	PORTA=oneNum|tenNum<<4;
	
	
}
int main()
{
	u8 displayedNum=30,x=0,oneNum,tensNum,ModifiedNum=30;
	modeButtStatus_t modeButt=NormalMode;
	firsButtStatus_t firsButt =Pause;
	DDRA=0xff;
	DDRC=0;
	PORTC=0xff;
	while(1)
	{
		
		if(modeButt==NormalMode)
		{
			if(firsButt==Resume)
			{
				displayedNum--;
				if(displayedNum==0)
				{
					displayedNum=31;
				}
				
			}
			else
			{
				//do nothing
			}
			Segment_Display_BCD(displayedNum);
			for(x=0;x<10;x++)
			{
				if(!READ_BIT(PINC,0))
				{
					firsButt^=1;
					//debouncing
					_delay_ms(10);
					//busy wait
					while(!READ_BIT(PINC,0));
					//to change the flag right after raising my hand from the button without waiting the delay (the for loop) to end
					break;
				}
				if(!READ_BIT(PINC,1))
				{
					displayedNum=ModifiedNum;
					firsButt=Pause;
					while(!READ_BIT(PINC,1));
					break;
				}
				if(!READ_BIT(PINC,2))
				{
					modeButt=AdjuctMode;
					while(!READ_BIT(PINC,2));
					break;
				}
				_delay_ms(10);
			}
		}
		else
		{
			//second mode
			oneNum=displayedNum%10;
			tensNum=displayedNum/10;
			if(!READ_BIT(PINC,0))
			{
				oneNum=oneNum+1;
				if(oneNum>9)
				{
					oneNum=0;
				}
				displayedNum=tensNum*10+oneNum;
				while(!READ_BIT(PINC,0));
			}
			if(!READ_BIT(PINC,1))
			{
				tensNum=tensNum+1;
				if(tensNum>9)
				{
					tensNum=0;
				}
				displayedNum=tensNum*10+oneNum;
				while(!READ_BIT(PINC,1));
			}
			Segment_Display_BCD(displayedNum);
			if(!READ_BIT(PINC,2))
			{
				modeButt=NormalMode;
				firsButt=Pause;
				ModifiedNum=displayedNum;
				while(!READ_BIT(PINC,2));
			}
		}
		
	}
}

