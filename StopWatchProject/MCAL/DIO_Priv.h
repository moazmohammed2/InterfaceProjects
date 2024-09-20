

#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_

/* this extern cuz the dio_int.h is used by the all and i want this array to be used by just me that's why it's here in the priv.h */

#define  DIO_REG_NUMS 3
#define PORT_NUMS 4

extern const DIO_PinStatus_t DIO_PinsStatusArray[TOTAL_PINS];


static void DIO_InitPin(DIO_Pin_t pin,DIO_PinStatus_t status);

#endif /* DIO_PRIV_H_ */