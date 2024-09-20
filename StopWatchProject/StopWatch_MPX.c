//work on kit 

#include "StdTypes.h"
#include "DIO_Int.h"
#include "ECU_Int.h"


typedef enum{
	NormalMode,
	AdjuctMode
}modeButtStatus_t;
typedef enum{
	Pause,
	Resume
}firsButtStatus_t;
int main()
{
	DIO_Init();
	SEG_Init();
	
	u16 x=0;
	u8 displayedNum=30,oneNum,tensNum,ModifiedNum=30;
	modeButtStatus_t modeButt=NormalMode;
	firsButtStatus_t firsButt =Pause;



	while(1)
	{
		if(modeButt==NormalMode)
		{
			if(firsButt==Resume)
			{
				displayedNum--;
				
			}
			else
			{
				//do nothing
			}
			for(x=0;x<600;x++)
			{
				Segment_Display(displayedNum);
				if(displayedNum==0)
				{
					/*NOte that there's a corner case here cuz while this for loop is executed any button is being pressed meanwhile
					 the processor won't notice that - skip it it's not that big deal        */
					for(x=0;x<300;x++)
					{
						SEGMENT_DigActiv(DIG2);
						Segment_Display(displayedNum);
					}
					displayedNum=ModifiedNum;
				}
				
				if(BUTTON_Status(sw1)==PRESSED)
				{
					firsButt^=1;
					//debouncing
					_delay_ms(10);
					//busy wait
					while(BUTTON_Status(sw1)==PRESSED)
					{
						Segment_Display(displayedNum);
					}
					//to change the flag right after raising my hand from the button without waiting the delay (the for loop) to end
					break;
				}
				if(BUTTON_Status(sw2)==PRESSED)
				{
					displayedNum=ModifiedNum;
					firsButt=Pause;
					while(BUTTON_Status(sw2)==PRESSED)
					{
						Segment_Display(displayedNum);
					}
					break;
				}
				if(BUTTON_Status(sw3)==PRESSED)
				{
					modeButt=AdjuctMode;
					while(BUTTON_Status(sw3)==PRESSED)
					{
						Segment_Display(displayedNum);
					}
					break;
				}
			}
		}
		else
		{
			//second mode
			oneNum=displayedNum%10;
			tensNum=displayedNum/10;
			if(BUTTON_Status(sw1)==PRESSED)
			{
				oneNum=oneNum+1;
				if(oneNum>9)
				{
					oneNum=0;
				}
				displayedNum=tensNum*10+oneNum;
				while(BUTTON_Status(sw1)==PRESSED)
				{
					Segment_Display(displayedNum);
				}
			}
			if(BUTTON_Status(sw2)==PRESSED)
			{
				tensNum=tensNum+1;
				if(tensNum>9)
				{
					tensNum=0;
				}
				displayedNum=tensNum*10+oneNum;
				while(BUTTON_Status(sw2)==PRESSED)
				{
					Segment_Display(displayedNum);
				}
			}
			Segment_Display(displayedNum);
			if(BUTTON_Status(sw3)==PRESSED)
			{
				modeButt=NormalMode;
				firsButt=Pause;
				ModifiedNum=displayedNum;
				while(BUTTON_Status(sw3)==PRESSED)
				{
					Segment_Display(displayedNum);
				}
			}
		}
		
	}
}