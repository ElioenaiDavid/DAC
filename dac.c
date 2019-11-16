/*
 * dac.c
 *
 *  Created on: 15 nov. 2019
 *      Author: David
 */
#include <MKL25Z4.h>
#include "dac.h"

void DAC0_init(void) {
SIM->SCGC6 |= 0x80000000; /* clock to DAC module */
DAC0->C1 = 0; /* disable the use of buffer */
DAC0->C0 = 0x80 | 0x20; /* enable DAC and use software trigger */
}
/* Delay n milliseconds
* The CPU core clock is set to MCGFLLCLK at 41.94 MHz in SystemInit().
*/
void delayMs(int n) {
int i;
int j;
for(i = 0 ; i < n; i++)
for (j = 0; j < 7000; j++) {}
}
void ONDA(int p){

	DAC0->DAT[0].DATL = p & 0xff; /* write low byte */
	DAC0->DAT[0].DATH = (p >> 8) & 0x0f;/* write high byte */
	delayMs(1); /* delay 1ms */


}
