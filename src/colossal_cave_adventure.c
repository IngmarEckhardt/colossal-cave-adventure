#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <stdio.h>
#include <stdlib.h>
// DwarfOS
#include <time.h>
#include <heap_management_helper.h>
#include <avr/pgmspace.h>
// Adventure
#include "advent.h"  /* #define preprocessor equates	*/
#include "advdec.h"
#include "advdef.h"


const uint8_t adjustToSecondValue = ADJUST_TO_SECOND_VALUE;

int main(void) {

    setupAdvent();
    initplay();
//    debugFlag = 1;
    sei();

    if (yesOrNoQuestion(65, 1, 0)) {
        timeLimit = 1000;
    } else {
        timeLimit = 330;
    }
    srand(511); /* seed random	*/

    while (1) {
        turn();
        printToSerialOutput();
        sleep_mode();
        adjustTo1Sec();
    }
}

ISR(TIMER2_OVF_vect) { cca_adjustCounter++; } // getting a clock and waking up from sleep mode


ISR(USART0_RX_vect) { inputQueue->enqueue(UDR0, inputQueue); } // put into stdin buffer if a sign is available/interrupt is triggered


// general inits
void adjustTo1Sec(void) {
    if (cca_adjustCounter == adjustToSecondValue) {
        mcuClock->incrementClockOneSec();
        cca_adjustCounter = 0;
    }
}

int put_char(char c, FILE * stream) {
    uartHelper->usartTransmitChar(c);
    return 0;
}

int get_char(FILE * stream) { return inputQueue->get_char(inputQueue); }

static FILE ccaStdOut = FDEV_SETUP_STREAM(put_char, NULL, _FDEV_SETUP_WRITE);
static FILE ccaStdIn = FDEV_SETUP_STREAM(NULL, get_char, _FDEV_SETUP_READ);

void setupAdvent(void) {
    stringRepository = dOS_initStringRepository(0);
    uartHelper = dOS_initUartHelper();
    inputQueue = cca_initInputQueue();
    flashHelper = dOS_initFlashHelper();
    setupMcu(&mcuClock);
    stdin = &ccaStdIn;
    stdout = &ccaStdOut;
    UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0); // Enable receiver and transmitter and Interrupt additionally
}

#define MEMORY_STRING_LENGTH 19
const __attribute__((__progmem__)) char memoryStringOnFlash[MEMORY_STRING_LENGTH] = ": free Memory is: ";
void printToSerialOutput(void) {
    HeapManagementHelper * heapHelper = dOS_initHeapManagementHelper();
    int16_t freeMem =  heapHelper->getFreeMemory();
    free(heapHelper);

    char * timestamp = ctime(NULL);
    char * memoryString = malloc(MEMORY_STRING_LENGTH);
    flashHelper->loadFarStringFromFlash(memoryString, pgm_get_far_address(memoryStringOnFlash));
    printf("%s%s%d\n", timestamp, memoryString, freeMem);
    free(timestamp);
    free(memoryString);
}

// ToDo: add function to save game into eeprom