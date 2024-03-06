#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>

//DwarfOS
#include <setup.h>
#include <mcu_clock.h>
#include <heap_management_helper.h>
#include <time.h>
#include <setup_advent.h>
#include <short_location_descriptions.h>
#include <long_location_descriptions.h>
#include <object_descriptions.h>
#include <actions_descriptions.h>

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
    char * testBuffer = malloc(30*sizeof(char));
    while (1) {

        sleep_mode();
        adjustTo1Sec();
        if ((uint8_t) time(NULL) != lastTime) {

            lastTime = time(NULL);
            printToSerialOutput();
            strcpy_P(testBuffer, shortDescriptions[0]);
            printf("%s", testBuffer);
        }
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
    setupMcu(&mcuClock); // general setup DwarfOS
    setupAdvent();
    heapHelper = dOS_initHeapManagementHelper();
}