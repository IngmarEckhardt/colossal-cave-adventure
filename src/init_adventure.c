#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <avr/pgmspace.h>
#include "advent.h"
#include "advdec.h"

void scanuint8(uint8_t * pi, char * str) {
    while (*str) {
        int value[1];
        sscanf(str, "%d,", &value[0]);
        if (value[0] < 0) { bug(2); }      /* failed before EOS	*/
        else { *(pi++) = (uint8_t) value[0]; }
        while (*str++ != ',') { /* advance str pointer	*/
        }
    }
}

#define INIT_STRING_MAX_LENGTH 37
const __attribute__((__progmem__)) char locationStatusStrings[10][INIT_STRING_MAX_LENGTH] = {
        "5,1,5,5,1,1,5,17,1,1,",
        "32,0,0,2,0,0,64,2,",
        "2,2,0,6,0,2,",
        "2,2,0,0,0,0,0,4,0,2,",
        "128,128,128,128,136,136,136,128,128,",
        "128,128,136,128,136,0,8,0,2,",
        "2,128,128,136,0,0,8,136,128,0,2,2,",
        "4,0,0,0,0,1,",
        "4,0,1,1,",
        "8,8,8,8,8,8,8,8,8,"
};
const __attribute__((__progmem__)) char objectLocationStrings[6][INIT_STRING_MAX_LENGTH] = {
        "3,3,8,10,11,0,14,13,94,96,",
        "19,17,101,103,0,106,0,0,3,3,",
        "109,25,23,111,35,0,97,",
        "119,117,117,0,130,0,126,140,0,96,",
        "18,27,28,29,30,",
        "92,95,97,100,101,0,119,127,130,"
};
const __attribute__((__progmem__)) char secondObjectLocationStrings[6][INIT_STRING_MAX_LENGTH] = {
        "9,0,0,0,15,0,255,",
        "255,27,255,0,0,0,255,",
        "255,255,67,255,110,0,255,255,",
        "121,122,122,0,255,255,255,255,0,255,",
        "121,255,"
};
#define DEFAULT_VERB_MSG_INIT_STRING_MAX_LENGTH 41
const __attribute__((__progmem__)) char defaultVerbMessageStrings[3][DEFAULT_VERB_MSG_INIT_STRING_MAX_LENGTH] = {
        "0,24,29,0,33,0,33,38,38,42,14,",
        "43,110,29,110,73,75,29,13,59,59,",
        "174,109,67,13,147,155,195,146,110,13,13,"
};
const __attribute__((__progmem__)) char dwarfLocationsInitStrings[22] = "0,19,27,33,44,64,114,";
void initplay(void) {
    turns = 0;

    /* initialize location status array */
    setmem(locationStatus, (sizeof(uint8_t)) * MAXLOC, 0);
    char * intermediateString = malloc(INIT_STRING_MAX_LENGTH);
    flashHelper->loadFarStringFromFlash(intermediateString, pgm_get_far_address(locationStatusStrings[0]));
    scanuint8(&locationStatus[1], intermediateString);
    flashHelper->loadFarStringFromFlash(intermediateString, pgm_get_far_address(locationStatusStrings[1]));
    scanuint8(&locationStatus[13], intermediateString);
    flashHelper->loadFarStringFromFlash(intermediateString, pgm_get_far_address(locationStatusStrings[2]));
    scanuint8(&locationStatus[21], intermediateString);
    flashHelper->loadFarStringFromFlash(intermediateString, pgm_get_far_address(locationStatusStrings[3]));
    scanuint8(&locationStatus[31], intermediateString);
    flashHelper->loadFarStringFromFlash(intermediateString, pgm_get_far_address(locationStatusStrings[4]));
    scanuint8(&locationStatus[42], intermediateString);
    flashHelper->loadFarStringFromFlash(intermediateString, pgm_get_far_address(locationStatusStrings[5]));
    scanuint8(&locationStatus[51], intermediateString);
    flashHelper->loadFarStringFromFlash(intermediateString, pgm_get_far_address(locationStatusStrings[6]));
    scanuint8(&locationStatus[79], intermediateString);
    flashHelper->loadFarStringFromFlash(intermediateString, pgm_get_far_address(locationStatusStrings[7]));
    scanuint8(&locationStatus[95], intermediateString);
    flashHelper->loadFarStringFromFlash(intermediateString, pgm_get_far_address(locationStatusStrings[8]));
    scanuint8(&locationStatus[113], intermediateString);
    flashHelper->loadFarStringFromFlash(intermediateString, pgm_get_far_address(locationStatusStrings[9]));
    scanuint8(&locationStatus[122], intermediateString);



    /* initialize object locations */
    setmem(objectLocation, (sizeof(uint8_t)) * MAXOBJ, 0);
    flashHelper->loadFarStringFromFlash(intermediateString, pgm_get_far_address(objectLocationStrings[0]));
    scanuint8(&objectLocation[1], intermediateString);
    flashHelper->loadFarStringFromFlash(intermediateString, pgm_get_far_address(objectLocationStrings[1]));
    scanuint8(&objectLocation[11], intermediateString);
    flashHelper->loadFarStringFromFlash(intermediateString, pgm_get_far_address(objectLocationStrings[2]));
    scanuint8(&objectLocation[23], intermediateString);
    flashHelper->loadFarStringFromFlash(intermediateString, pgm_get_far_address(objectLocationStrings[3]));
    scanuint8(&objectLocation[31], intermediateString);
    flashHelper->loadFarStringFromFlash(intermediateString, pgm_get_far_address(objectLocationStrings[4]));
    scanuint8(&objectLocation[50], intermediateString);
    flashHelper->loadFarStringFromFlash(intermediateString, pgm_get_far_address(objectLocationStrings[5]));
    scanuint8(&objectLocation[56], intermediateString);

    /* initialize second (secondObjectLocation) locations */
    setmem(secondObjectLocation, (sizeof(uint8_t)) * MAXOBJ, 0);
    flashHelper->loadFarStringFromFlash(intermediateString, pgm_get_far_address(secondObjectLocationStrings[0]));
    scanuint8(&secondObjectLocation[3], intermediateString);
    flashHelper->loadFarStringFromFlash(intermediateString, pgm_get_far_address(secondObjectLocationStrings[1]));
    scanuint8(&secondObjectLocation[11], intermediateString);
    flashHelper->loadFarStringFromFlash(intermediateString, pgm_get_far_address(secondObjectLocationStrings[2]));
    scanuint8(&secondObjectLocation[23], intermediateString);
    flashHelper->loadFarStringFromFlash(intermediateString, pgm_get_far_address(secondObjectLocationStrings[3]));
    scanuint8(&secondObjectLocation[31], intermediateString);
    flashHelper->loadFarStringFromFlash(intermediateString, pgm_get_far_address(secondObjectLocationStrings[4]));
    scanuint8(&secondObjectLocation[62], intermediateString);

    free(intermediateString);
    intermediateString = malloc(DEFAULT_VERB_MSG_INIT_STRING_MAX_LENGTH);

    /* initialize default verb messages */
    flashHelper->loadFarStringFromFlash(intermediateString, pgm_get_far_address(defaultVerbMessageStrings[0]));
    scanuint8(actmsg, intermediateString);
    flashHelper->loadFarStringFromFlash(intermediateString, pgm_get_far_address(defaultVerbMessageStrings[1]));
    scanuint8(&actmsg[11], intermediateString);
    flashHelper->loadFarStringFromFlash(intermediateString, pgm_get_far_address(defaultVerbMessageStrings[2]));
    scanuint8(&actmsg[21], intermediateString);

    /* initialize various flags and other variables */
    setmem(visited, (sizeof(uint8_t)) * MAXLOC, 0);
    setmem(objectStatus, (sizeof(int)) * MAXOBJ, 0);
    setmem(&objectStatus[50], (sizeof(int)) * (MAXOBJ - 50), 0xff);
    wzdark = closed = closing = countItemsHeld = lookCount = 0;
    timeLimit = 100;
    tally = 15;
    tally2 = 0;
    newLocation = 1;
    location = oldLocation = oldLocation2 = 3;
    knifeLocation = 0;

    /*	dwarfLocations[DWARFMAX-1] = chestLocation				*/
    flashHelper->loadFarStringFromFlash(intermediateString, pgm_get_far_address(dwarfLocationsInitStrings));
    scanuint8(dwarfLocations, intermediateString);
    free(intermediateString);

    setmem(oldLocationOfDwarf,(sizeof(uint8_t))*DWARFMAX,0);
    setmem(dwarfSeenFlag,(sizeof(uint8_t))*DWARFMAX,0);
    dkill = 0;
    clock1 = 30;
    clock2 = 50;
    panic = 0;
    bonus = 0;
    numberOfDeaths = 0;
    lampWarningFlag = 0;
    foobar = 0;
    dwarfFlag = 0;
    playerWantToQuitFlag = 0;
}