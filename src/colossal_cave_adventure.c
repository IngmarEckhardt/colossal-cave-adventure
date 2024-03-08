#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <avr/io.h>

//DwarfOS
#include "advent.h"
#include "advword.h" /* definition of "word" array	*/
#include <stdlib.h>
#include <global_declarations.h>
#include <setup_adventure.h>

#include <cca_helper.h>
#include <time.h>
#include <stdio.h>


void setup(void);

void printToSerialOutput(void);


int main(void) {

    setup();

    sei();
    if (yes(65, 1, 0))
        limit = 1000;
    else
        limit = 330;
    srand(511); /* seed random	*/

    while (1) {
        turn();
        sleep_mode();
        adjustTo1Sec();
    }
}

ISR(TIMER2_OVF_vect) { cca_adjustCounter++; }


ISR(USART0_RX_vect) { putIntoQueue(UDR0); }

void printToSerialOutput(void) {
    char * timestamp = ctime(NULL);
    printf("%s: free Memory is: %d byte\n", timestamp, heapHelper->getFreeMemory());
    free(timestamp);
}

void setup(void) {
    setupAdvent();
}