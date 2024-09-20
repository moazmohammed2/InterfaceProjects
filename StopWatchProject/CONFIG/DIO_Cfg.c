#include "StdTypes.h"
#include "DIO_Int.h"
#include "DIO_Cfg.h"

/* const here to make the array more secure cuz even the developer has the prototype of the array [the extern of it]
 they can't assign in it cuz it's read only location the second thing is to save the ram cuz at this case it will be
 downloaded in the rodata in flash  */

const DIO_PinStatus_t DIO_PinsStatusArray[TOTAL_PINS]={
	OUTPUT,      /* Port A Pin 0 ADC0*/
	OUTPUT,      /* Port A Pin 1 ADC1*/
	OUTPUT,      /* Port A Pin 2 */
	OUTPUT,      /* Port A Pin 3 */
	OUTPUT,      /* Port A Pin 4 */
	OUTPUT,      /* Port A Pin 5 */
	OUTPUT,      /* Port A Pin 6 */
	OUTPUT,      /* Port A Pin 7 ADC7*/
	OUTPUT,      /* Port B Pin 0   / */
	OUTPUT,      /* Port B Pin 1   /*/
	OUTPUT,		 /* Port B Pin 2 / INT2*/
	OUTPUT,		 /* Port B Pin 3   /OC0*/
	INPULL,		 /* Port B Pin 4 /ss*/
	INPULL,		 /* Port B Pin 5 //mosi*/
	INPULL,		 /* Port B Pin 6 /miso*/
	INPULL,		 /* Port B Pin 7 clk*/
	OUTPUT,		 /* Port C Pin 0 */
	OUTPUT,		 /* Port C Pin 1 */
	OUTPUT,		 /* Port C Pin 2 */
	OUTPUT,		 /* Port C Pin 3 */
	OUTPUT,		 /* Port C Pin 4 */
	OUTPUT,		 /* Port C Pin 5 */
	OUTPUT,		 /* Port C Pin 6 */
	OUTPUT,		 /* Port C Pin 7 */
	INPULL,		 /* Port D Pin 0 */
	INPULL,		 /* Port D Pin 1 */
    INPULL,      /* Port D Pin 2 /INT0*/
	INPULL,      /* Port D Pin 3 / INT1 */
	INPULL,		 /* Port D Pin 4  OC1B*/
	OUTPUT,		 /* Port D Pin 5 OC1A*/
	OUTPUT,		 /* Port D Pin 6 /   ICP*/
	OUTPUT		 /* Port D Pin 7 */
};