

#ifndef STOPWATCH_INT_H_
#define STOPWATCH_INT_H_
typedef enum{
	NormalMode,
	AdjuctMode
}modeButtStatus_t;
typedef enum{
	Pause,
	Resume
}firsButtStatus_t;

extern modeButtStatus_t modeButt;
extern firsButtStatus_t firsButt;
extern u8 displayedNum;


void STOPWATCH_Runnable(void);
void STOPWATCH_Init(void );




#endif /* STOPWATCH_INT_H_ */