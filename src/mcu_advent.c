#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <avr/io.h>

//DwarfOS
#include <setup.h>
#include <ascii_helper.h>
#include <mcu_clock.h>
#include <uart_helper.h>
#include <heap_management_helper.h>
#include <time.h>
#include <stdio.h>

static const int INPUT_BUFFER_START_SIZE = 7;
McuClock * mcuClock;

char * inputBuffer;
uint8_t indexPut = 0;
uint8_t indexRead = 0;
uint8_t inputBufferSize;
uint8_t lastTime;

volatile uint8_t adjustCounter = 0;

static int put_char(char c, FILE * stream);

int get_char(FILE * stream);

static FILE myStdOut = FDEV_SETUP_STREAM(put_char, NULL, _FDEV_SETUP_WRITE);
static FILE myStdIn = FDEV_SETUP_STREAM(NULL, get_char, _FDEV_SETUP_READ);
#ifndef NDEBUG
HeapManagementHelper * heapHelper;
AsciiHelper * asciiHelper;
UartHelper * uartHelper;


void printMemoryToSerialOutput(void);

#endif


void setupAdvent(void);

void adjustTo1Sec(void);

int calculateTimeDifference(int a, int b);


uint8_t
resizeInputBuffer(char ** inputBufferPtr, uint8_t nextWriteIndex, uint8_t nextReadIndex, uint8_t actualBufferSize);

int main(void) {
    setupMcu(&mcuClock);
    setupAdvent();

    sei();
    while (1) {

        sleep_mode();
        adjustTo1Sec();



        if ((uint8_t) time(NULL) != lastTime) {
            lastTime = time(NULL);
#ifndef NDEBUG
            printMemoryToSerialOutput();
#endif
        }
    }
}

uint8_t resizeInputBuffer(char ** inputBufferPtr, uint8_t nextWriteIndex, uint8_t nextReadIndex, uint8_t actualBufferSize) {

    if (((nextWriteIndex + actualBufferSize - nextReadIndex) % actualBufferSize) >= (actualBufferSize - 1) &&
        actualBufferSize <= (UINT8_MAX / 2)) {
        char * newBuffer = (char *) realloc(*inputBufferPtr, (actualBufferSize * 2) * sizeof(char));
        if (newBuffer == NULL) {
            return actualBufferSize;
        }
        *inputBufferPtr = newBuffer;
        actualBufferSize *= 2;
    } else if (((nextWriteIndex + actualBufferSize - nextReadIndex) % actualBufferSize) < (actualBufferSize / 4) &&
               actualBufferSize >= (INPUT_BUFFER_START_SIZE * 2)) {
        char * newBuffer = (char *) realloc(*inputBufferPtr, (actualBufferSize / 2) * sizeof(char));
        if (newBuffer == NULL) {
            return actualBufferSize;
        }
        *inputBufferPtr = newBuffer;
        actualBufferSize /= 2;
    }
    return actualBufferSize;

}


ISR(TIMER2_OVF_vect) { adjustCounter++; }

ISR(USART0_RX_vect) {
    inputBuffer[indexPut++ % inputBufferSize] = UDR0;
    inputBufferSize = resizeInputBuffer(&inputBuffer, indexPut, indexRead, inputBufferSize);
}

void setupAdvent(void) {

    stdin = &myStdIn;
    stdout = &myStdOut;
#ifndef NDEBUG
    heapHelper = dOS_initHeapManagementHelper();
    asciiHelper = dOS_initAsciiHelper();
    uartHelper = dOS_initUartHelper();
#endif
    // Enable receiver and transmitter and Interrupt additionally
    UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);
    inputBuffer = (char *) malloc(INPUT_BUFFER_START_SIZE * sizeof(char));
}


void adjustTo1Sec(void) {
    if (adjustCounter == ADJUST_TO_SECOND_VALUE) {
        mcuClock->incrementClockOneSec();
        adjustCounter = 0;
    }
}

void printMemoryToSerialOutput(void) {
    char memoryStringArray[5];
    memoryStringArray[4] = '\0';

    uint16_t memoryAmount = heapHelper->getFreeMemory();

    asciiHelper->integerToAscii(memoryStringArray, memoryAmount, 4, 0);
    printf("free Memory is: %s byte\n", memoryStringArray);
    char buffer[inputBufferSize+14];

    gets(buffer);
    printf("You entered: %s\n", buffer);
}

int put_char(char c, FILE * stream) {
    uartHelper->usartTransmitChar(c);
    return 0;
}

int get_char(FILE * stream) {
    while (indexRead == indexPut) {
        if (calculateTimeDifference(adjustCounter, lastTime) > 10) {
            return EOF;
        }
    }
    lastTime = adjustCounter;
    return inputBuffer[indexRead++ % inputBufferSize];
}

int calculateTimeDifference(int a, int b) {
    int diff = a - b;
    if (diff < 0) {
        diff += ADJUST_TO_SECOND_VALUE;
    }
    return diff % ADJUST_TO_SECOND_VALUE;
}