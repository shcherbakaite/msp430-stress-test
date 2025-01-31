/***************************************************************************
 *                                                                         *
 *   Copyright (C) 2010-2011, MedIT (RWTH)                                 *
 *   Authors: Marius Cordts, Daniel Rüschen                                *
 *   Contact: { marius.cordts, daniel.rueschen } @ rwth-aachen.de          *
 *                                                                         *
 ***************************************************************************/
 
#include "wait.h"
#include <msp430.h>
 
void wait(unsigned int ms) {
 	// CLK = ACLK, Input Divider = 1/8, UP Mode
    // MC0 - count up, TASSEL_2 - SMCLK
    TACTL = TASSEL_2 | MC0;
 	
 	// 1kHZ Clock
 	TACCR0 = 1000;
 	
 	while (ms != 0) {
 		while (!(TACTL & TAIFG)) ; // Continues every ms
 		TAR = 0;
 		TACTL &= ~(TAIFG);
 		--ms;
 	}
 	TACTL |= TACLR;
}