
#ifndef ECU_INT_H_
#define ECU_INT_H_

typedef enum{
	DIG1,
	DIG2
}SEG_DIGS_t;

#define Segment_PORT PA
void Segment_Display(u8 n);

void SEGMENT_DigDeActiv(SEG_DIGS_t SegDig);
void SEGMENT_DigActiv(SEG_DIGS_t SegDig);

void SEG_Init(void);


typedef enum{
	PRESSED,
	UNPRESSED
	}BUTTON_STATUS_t;

typedef enum{
	sw1,
	sw2,
	sw3,
	sw4,
	sw5,
	sw6,
	sw7,
	sw8,
	sw9,
	sw10,
	sw11,
	sw12,
	sw13,
	sw14,
	sw15,
	sw16
	}BUTTON_t;
BUTTON_STATUS_t BUTTON_Status(BUTTON_t button);

typedef enum{
	RELAY1,
	RELAY2
	}RelayNum_t;
void RELAY_On(RelayNum_t relay);
void RELAY_Off(RelayNum_t relay);

#endif /* ECU_INT_H_ */