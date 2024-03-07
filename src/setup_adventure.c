#include <stdio.h>
#include <avr/io.h>
#include <string.h>

#include <setup_adventure.h>
#include <setup.h>
#include <uart_helper.h>
#include <advent.h>
#include <advdef.h>


#define setmem(l, s, c) memset(l, c, s)

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


/* ************************************************************	*/

/*
	Initialize integer arrays with sscanf
*/
void scanint(int *pi, char *str)
{
    while (*str) {
        if ((sscanf(str, "%d,", pi++)) < 1)
            bug(41);      /* failed before EOS	*/
        while (*str++ != ',') /* advance str pointer	*/
            ;
    }
}

/*
	Initialization of adventure play variables
*/
void initplay(void)
{
    turns = 0;

    /* initialize location status array */
    setmem(cond, (sizeof(int)) * MAXLOC, 0);
    scanint(&cond[1], "5,1,5,5,1,1,5,17,1,1,");
    scanint(&cond[13], "32,0,0,2,0,0,64,2,");
    scanint(&cond[21], "2,2,0,6,0,2,");
    scanint(&cond[31], "2,2,0,0,0,0,0,4,0,2,");
    scanint(&cond[42], "128,128,128,128,136,136,136,128,128,");
    scanint(&cond[51], "128,128,136,128,136,0,8,0,2,");
    scanint(&cond[79], "2,128,128,136,0,0,8,136,128,0,2,2,");
    scanint(&cond[95], "4,0,0,0,0,1,");
    scanint(&cond[113], "4,0,1,1,");
    scanint(&cond[122], "8,8,8,8,8,8,8,8,8,");

    /* initialize object locations */
    setmem(place, (sizeof(int)) * MAXOBJ, 0);
    scanint(&place[1], "3,3,8,10,11,0,14,13,94,96,");
    scanint(&place[11], "19,17,101,103,0,106,0,0,3,3,");
    scanint(&place[23], "109,25,23,111,35,0,97,");
    scanint(&place[31], "119,117,117,0,130,0,126,140,0,96,");
    scanint(&place[50], "18,27,28,29,30,");
    scanint(&place[56], "92,95,97,100,101,0,119,127,130,");

    /* initialize second (fixed) locations */
    setmem(fixed, (sizeof(int)) * MAXOBJ, 0);
    scanint(&fixed[3], "9,0,0,0,15,0,-1,");
    scanint(&fixed[11], "-1,27,-1,0,0,0,-1,");
    scanint(&fixed[23], "-1,-1,67,-1,110,0,-1,-1,");
    scanint(&fixed[31], "121,122,122,0,-1,-1,-1,-1,0,-1,");
    scanint(&fixed[62], "121,-1,");

    /* initialize default verb messages */
    scanint(actmsg, "0,24,29,0,33,0,33,38,38,42,14,");
    scanint(&actmsg[11], "43,110,29,110,73,75,29,13,59,59,");
    scanint(&actmsg[21], "174,109,67,13,147,155,195,146,110,13,13,");

    /* initialize various flags and other variables */
    setmem(visited, (sizeof(int)) * MAXLOC, 0);
    setmem(prop, (sizeof(int)) * MAXOBJ, 0);
    setmem(&prop[50], (sizeof(int)) * (MAXOBJ - 50), 0xff);
    wzdark = closed = closing = holding = detail = 0;
    limit = 100;
    tally = 15;
    tally2 = 0;
    newloc = 1;
    loc = oldloc = oldloc2 = 3;
    knfloc = 0;
    chloc = 114;
    chloc2 = 140;
    /*	dloc[DWARFMAX-1] = chloc				*/
    scanint(dloc, "0,19,27,33,44,64,114,");
    scanint(odloc, "0,0,0,0,0,0,0,");
    dkill = 0;
    scanint(dseen, "0,0,0,0,0,0,0,");
    clock1 = 30;
    clock2 = 50;
    panic = 0;
    bonus = 0;
    numdie = 0;
    daltloc = 18;
    lmwarn = 0;
    foobar = 0;
    dflag = 0;
    gaveup = 0;
}

void setupAdvent(void) {
    setupMcu(&mcuClock);

    uartHelper = dOS_initUartHelper();
    inputQueue = cca_initInputQueue(&adjustCounter);
    stdin = &myStdIn;
    stdout = &myStdOut;
    // Enable receiver and transmitter and Interrupt additionally
    UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);
    initplay();
}