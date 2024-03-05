#include <stdio.h>
#include <avr/io.h>
#include <setup_advent.h>
#include <setup.h>
#include <uart_helper.h>

const uint8_t adjustToSecondValue = ADJUST_TO_SECOND_VALUE;
volatile uint8_t adjustCounter = 0;

McuClock * mcuClock;
InputQueue * inputQueue;
UartHelper * uartHelper;

void adjustTo1Sec(void) {
    if (adjustCounter == adjustToSecondValue) {
        mcuClock->incrementClockOneSec();
        adjustCounter = 0;
    }
}
void putIntoQueue(uint8_t item) {
    inputQueue->enqueue(item, inputQueue);
}


int put_char(char c, FILE * stream) {
    uartHelper->usartTransmitChar(c);
    return 0;
}

int get_char(FILE * stream) {
    int16_t c = inputQueue->get_char(inputQueue);
    return c;
}

static FILE myStdOut = FDEV_SETUP_STREAM(put_char, NULL, _FDEV_SETUP_WRITE);
static FILE myStdIn = FDEV_SETUP_STREAM(NULL, get_char, _FDEV_SETUP_READ);

void setupAdvent(void) {
    setupMcu(&mcuClock);
    uartHelper = dOS_initUartHelper();
    inputQueue = cca_initInputQueue(&adjustCounter);
    stdin = &myStdIn;
    stdout = &myStdOut;

#ifndef NDEBUG

#endif
    // Enable receiver and transmitter and Interrupt additionally
    UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);
}