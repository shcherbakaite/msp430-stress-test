#include <msp430.h>

#include "wait.h"


#define     LED1                  BIT0
#define     LED2                  BIT6
#define     LED_DIR               P1DIR
#define     LED_OUT               P1OUT

#define TIME_ON 2
#define TIME_OFF 2

#define TIMES_COUNT (130)

#define UNIT 1
#define DASH 3*UNIT
#define DOT UNIT
#define SYMBOL 3*UNIT
#define WORD 7*UNIT

int times[TIMES_COUNT] = {
    //D
    DASH, UNIT,
    DOT, UNIT,
    DOT, SYMBOL,
    //A

    DOT, UNIT,
    DASH, SYMBOL,
    //N

    DASH, UNIT,
    DOT, SYMBOL,
    //G

    DASH, UNIT,
    DASH, UNIT,
    DOT, SYMBOL,
    //E

    DOT, SYMBOL,
    //R

    DOT, UNIT,
    DASH, UNIT,
    DOT, WORD,

     //D
    DASH, UNIT,
    DOT, UNIT,
    DOT, SYMBOL,
    //A

    DOT, UNIT,
    DASH, SYMBOL,
    //N

    DASH, UNIT,
    DOT, SYMBOL,
    //G

    DASH, UNIT,
    DASH, UNIT,
    DOT, SYMBOL,
    //E

    DOT, SYMBOL,
    //R

    DOT, UNIT,
    DASH, UNIT,
    DOT, WORD,

    // H
    DOT, UNIT,
    DOT, UNIT,
    DOT, UNIT,
    DOT, SYMBOL,
    //I

    DOT, UNIT,
    DOT, SYMBOL,
    //G

    DASH, UNIT,
    DASH, UNIT,
    DOT, SYMBOL,
    //H

    DOT, UNIT,
    DOT, UNIT,
    DOT, UNIT,
    DOT, WORD,

    //V

    DOT, UNIT,
    DOT, UNIT,
    DOT, UNIT,
    DASH, SYMBOL,
    //O

    DASH, UNIT,
    DASH, UNIT,
    DASH, SYMBOL,
    //L

    DOT, UNIT,
    DASH, UNIT,
    DOT, UNIT,
    DOT, SYMBOL,
    //T

    DASH, SYMBOL,
    //A

    DOT, UNIT,
    DASH, SYMBOL,
    //G

    DASH, UNIT,
    DASH, UNIT,
    DOT, SYMBOL,
    //E

    DOT, WORD,

    // !
    DASH, UNIT,
    DOT, UNIT,
    DASH, UNIT,
    DOT, UNIT,
    DASH, UNIT,
    DASH, WORD


};

#if defined(__IAR_SYSTEMS_ICC__)
int16_t __low_level_init(void) {
    // Stop WDT (Watch Dog Timer)
    WDTCTL = WDTPW + WDTHOLD;
    return(1);
}

#endif

void setup_led(void) {
    LED_DIR |= LED1; // set LED DIR to output
    LED_OUT &= ~LED1;
}

void led_on() {
    LED_OUT |= LED1; // turn LED on
}

void led_off() {
    LED_OUT &= ~LED1; // turn LED off
}

void setup_output() {
    P2DIR |= BIT0;
}

void output_on() {
    P2OUT |= BIT0;
}

void output_off() {
    P2OUT &= ~BIT0;
}

void main(void)
{
    WDTCTL = WDTPW + WDTHOLD; //Stop watchdog timer
 
	_enable_interrupt();

    // Set up the LCD
    setup_led();
    setup_output();

    wait(10);
    
    int i = 0;

    while(1) {
        led_on();
        output_on();
        wait(times[i++ % TIMES_COUNT]*100);
        led_off();
        output_off();
        wait(times[i++ % TIMES_COUNT]*100);
    }
}
