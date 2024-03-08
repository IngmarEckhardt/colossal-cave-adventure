#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>

//DwarfOS
#include "advent.h"
#include "advword.h" /* definition of "word" array	*/
#include "advdef.h"
#include "objects.h"
#include "long_locations.h"
#include "short_locations.h"
#include "actions.h"
#include "cave_travel_array.h"

#include <mcu_clock.h>
#include <heap_management_helper.h>
#include <time.h>
#include <setup_adventure.h>


void setup(void);

void printToSerialOutput(void);

McuClock * mcuClock;
HeapManagementHelper * heapHelper;

char * timestamp;
uint8_t lastTime;


int main(void) {

    setup();
    char * object3 = getObject(61);
    printf("Object 61 is: %s\n", object3);
    free(object3);
    object3 = getLongLocation(61);
    printf("LongLocation 61 is: %s\n", object3);
    free(object3);
    object3 = getShortLocation(61);
    printf("ShortLocation 61 is: %s\n", object3);
    free(object3);
    object3 = getAction(61);
    printf("Action 61 is: %s\n", object3);
    object3 = getTravel(61);
    printf("Travel 61 is: %s\n", object3);
    free(object3);
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