#include "StdTypes.h"
#include "DIO_Int.h"
#include "ECU_Int.h"
#include "ECU_Cfg.h"
#include "ECU_Priv.h"





//this array only for the buttons of the first row[activated switches at the direct mode ] 
DIO_Pin_t buttonPinsDirectMode[ACTIVE_SWITCHES]={PIND2,PIND3,PIND4,PIND5};