#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>

//DwarfOS
#include "advent.h"
#include "advword.h" /* definition of "word" array	*/
#include "advdef.h"

#include <mcu_clock.h>
#include <heap_management_helper.h>
#include <time.h>
#include <setup_adventure.h>


void setup(void);

void printToSerialOutput(void);

McuClock * mcuClock;
HeapManagementHelper * heapHelper;

uint8_t lastTime;
char * timestamp;
uint8_t lastTime;


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
        printToSerialOutput();
//        sleep_mode();
        adjustTo1Sec();
//        if ((uint8_t) time(NULL) != lastTime) {
//
//            lastTime = time(NULL);
//            printToSerialOutput();
//            char * description_65 = getAction(1);
//            printf("%s",description_65);
//            free(description_65);
//            description_65= getLongLocation(65);
//            printf("%s",description_65);
//            free(description_65);
//            description_65= getShortLocation(65);
//            printf("%s",description_65);
//            free(description_65);
//            description_65= getObject(25);
//            printf("%s",description_65);
//            free(description_65);
//        }
    }
}

ISR(TIMER2_OVF_vect) { adjustCounter++; }

// every time a new char is received, the interrupt is triggered and the char is put into the queue
ISR(USART0_RX_vect) { putIntoQueue(UDR0); }

void printToSerialOutput(void) {


    timestamp = ctime(NULL);
    printf("%s: free Memory is: %d byte\n", timestamp, heapHelper->getFreeMemory());
    free(timestamp);
}

void setup(void) {
    setupAdvent();
    heapHelper = dOS_initHeapManagementHelper();
}