#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>
//DwarfOS
#include <heap_management_helper.h>
#include <time.h>
#include <setup_advent.h>

#ifndef NDEBUG
#define STRING_BUFFER_SIZE 81
uint8_t lastTime;
HeapManagementHelper * heapHelper;
char * strings;
char * timestamp;
void printMemoryToSerialOutput(void);
#endif

int main(void) {
    setupAdvent();
#ifndef NDEBUG
    strings = malloc(STRING_BUFFER_SIZE * sizeof(char));
    heapHelper = dOS_initHeapManagementHelper();
#endif
    sei();
    while (1) {

        sleep_mode();
        adjustTo1Sec();

#ifndef NDEBUG
        if ((uint8_t) time(NULL) != lastTime) {

            lastTime = time(NULL);
            printMemoryToSerialOutput();
        }
#endif
    }
}

ISR(TIMER2_OVF_vect) { adjustCounter++; }

ISR(USART0_RX_vect) { putIntoQueue(UDR0); }

void printMemoryToSerialOutput(void) {
    strings[0] = '\0';
    fgets(strings, STRING_BUFFER_SIZE, stdin);
    timestamp = ctime(NULL);

    if (*strings) {
        printf("%s: you entered: %s\n", timestamp, strings);
    }
    else {
        printf("%s: free Memory is: %d byte\n", timestamp, heapHelper->getFreeMemory());
    }
    free(timestamp);
}