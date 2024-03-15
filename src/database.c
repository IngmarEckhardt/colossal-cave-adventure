
/*	program DATABASE.C					*\
\*	WARNING: "advent.c" allocates GLOBAL storage space by	*\
\*		including "advdef.h".				*\
\*		All other modules use "advdec.h".		*/

#include <stdio.h> /* drv = 1.1st file 2.def 3.A	*/
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <avr/pgmspace.h>

#include "advent.h"
#include "advdec.h"


/*
	Routine to fill locationRoutingInfos array for a given location
*/
void getRoutingInfos(int location) {
    char travelString[145] = {0}; /* max length of any cave pos = 144 bytes */
    char * charPointer;
    long interimResult;

    if (location <= 0 || location >= MAXLOC) { bug(42); }


    char * cave = getCave(location);
    if (cave == NULL) { bug(1); }
    if (strlen(cave) > sizeof(travelString)) { bug(43); }
    strcpy(travelString, cave);
    free(cave);

    while ((charPointer = strrchr(travelString, ','))) { *charPointer = '\0'; } /* terminate substring	*/

    charPointer = &travelString[0];
    uint8_t limit = MAXTRAV - 1;
    for (uint8_t i = 0; i < limit; i++) {

        interimResult = atol(charPointer); /* convert to long int	*/

        locationRoutingInfos[i].condition = (int) (interimResult % 1000L);
        interimResult /= 1000L;
        locationRoutingInfos[i].verbForDest = (int) (interimResult % 1000L);
        interimResult /= 1000L;
        locationRoutingInfos[i].destination = (int) (interimResult % 1000L);

        while (*(charPointer++)) {} /* to next substring	*/

        if (!(*charPointer)) {
            locationRoutingInfos[++i].destination = -1; /* end of array	*/

            if (debugFlag) {
                for (uint8_t j = 0; j < MAXTRAV; j++) {
                    printf("cave[%d] = %d %d %d\n", location, locationRoutingInfos[j].destination,
                           locationRoutingInfos[j].verbForDest, locationRoutingInfos[j].condition);
                }
            }
            return; /* terminate for loop	*/
        }
    }
    bug(33);
}

/*
	Routine to request a yesOrNoQuestion or no answer to a question.
*/
int yesOrNoQuestion(int question, int yesReactionMsg, int noReactionMsg) {
    char answer[80];

    if (question) { speakReaction(question); }

    fputs("> ", stdout);
    fflush(stdout);

    if (NULL == fgets(answer, 80, stdin)) { bug(3); }

    if (tolower(answer[0]) == 'n') {
        if (noReactionMsg) { speakReaction(noReactionMsg); }
        return 0;
    }

    if (yesReactionMsg) { speakReaction(yesReactionMsg); }
    return 1;
}

/*
	Print a location description from "advent4.txt"
*/
void speakReaction(int actionMsgNumber) {

    char * message = getAction(actionMsgNumber);
    fputs(message, stdout);
    free(message);
}

/*
	Print an item message for a given state from "advent3.txt"
*/
void printItemMessage(int item, int state) {

    if (item > 64) { bug(40);}

    char * itemString = getObject(item);

    if (itemString == NULL) { bug(31); }
    else {
        char character;
        uint8_t n = state + 2;

        //move the string pointer to the sign after the (second + state) '/' or report a bug if null terminated before
        while (n--) {
            while ((character = *itemString++) != '/') { if (character == '\0') { bug(32); }}
        }

        //print the string until the next '/'
        for (uint8_t i = 0; itemString[i] != '\0' && itemString[i] != '/'; i++) { putchar(itemString[i]); }
    }
    free(itemString);
}

/*
	Print a long location description from "advent1.txt"
*/
void describeLongLocation(int location) {

    char * message = getLongLocation(location);
    fputs(message, stdout);
    free(message);
}

/*
	Print a short location description from "advent2.txt"
*/
void describeShortLocation(int location) {

    char * message = getShortLocation(location);
    fputs(message, stdout);
    free(message);
}

/*
	look-up vocabulary word in lex-ordered table.  words may have
	two entries with different codes. if minimum acceptable value
	= 0, then return minimum of different codes.  last word CANNOT
	have two entries(due to binary sort).
	word is the word to look up.
	minValue  is the minimum acceptable value,
		if != 0 return %1000
*/
int lookUpVocabulary(char * word, int minValue) {
    int firstWordIndex, secondWordIndex;
    int16_t firstWordCode;
    int16_t secondWordCode;

    if ((firstWordIndex = searchWordIndex(word, MAXWC)) >= 0) {

        secondWordIndex = searchWordIndex(word, MAXWC - 1);

        if (secondWordIndex < 0) {
            secondWordCode = firstWordCode = (int16_t) getCode(firstWordIndex);
        } else {
            firstWordCode = (int16_t) getCode(firstWordIndex);
            secondWordCode = (int16_t) getCode(secondWordIndex);
        }

        if (!minValue) { return firstWordCode < secondWordCode ? firstWordCode : secondWordCode; }

        if (minValue <= firstWordCode) { return firstWordCode % 1000; }
        else if (minValue <= secondWordCode) { return secondWordCode % 1000; }
        else { return -1; }
    } else {
        return -1;
    }
}

//performs the binary search
int searchWordIndex(char * word, int amountToSearchThrough) {
    int lo, mid, hi, check;

    lo = 0;
    hi = amountToSearchThrough - 1;
    while (lo <= hi) {
        mid = (lo + hi) / 2;

        if ((check = compareWord(word, mid)) < 0) {
            hi = mid - 1;
        } else if (check > 0) {
            lo = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

/*
	Utility Routines
*/

/*
	Routine to test for darkness
*/
int dark(void) { return !(locationStatus[actualLocation] & LIGHT) && (!stateOfObject[LAMP] || !here(LAMP)); }

/*
	Routine to tell if an item is present.
*/
int here(int item) { return objectLocation[item] == actualLocation || isInInventory(item); }

/*
	Routine to tell if an item is being carried.
*/
int isInInventory(int item) { return objectLocation[item] == UINT8_MAX; }

/*
	Routine to tell if a location causes
	a isForcingAMove move.
*/
int isForcingAMove(int location) { return locationStatus[location] == 2; }

/*
	Routine true x% of the time.
*/
int isRandomlyTrue(int percentageOfTrueAnswers) { return rand() % 100 < percentageOfTrueAnswers; }

/*
	Routine to tell if player is on
	either side of a two-sided object.
*/
int isOnEitherSideOfTwoSidedObject(int objectToInvestigate) { return objectLocation[objectToInvestigate] == actualLocation || secondObjectLocation[objectToInvestigate] == actualLocation; }

/*
	Routine to destroy an object
*/
void destroy(int object) { move(object, 0); }

/*
	Routine to move an object
*/
void move(int obj, int where) {
    int from;

    from = (obj < MAXOBJ) ? objectLocation[obj] : secondObjectLocation[obj - MAXOBJ];
    if (from > 0 && from <= MAXLOC) {
        carry(obj, from);
    }
    drop(obj, where);
}

/*
	Juggle an object
	currently a no-op
*/
void juggle(int loc) { (void) loc; }

/*
	Routine to carry an object
*/
void carry(int obj, int where) {
    (void) where;

    if (obj < MAXOBJ) {
        if (objectLocation[obj] == UINT8_MAX) { return; }
        objectLocation[obj] = UINT8_MAX;
        ++countItemsHeld;
    }
}

/*
	Routine to drop an object
*/
void drop(int obj, int where) {
    if (obj < MAXOBJ && countItemsHeld > 0) {
        if (objectLocation[obj] == UINT8_MAX) { --countItemsHeld; }
        objectLocation[obj] = where;
    } else {
        secondObjectLocation[obj - MAXOBJ] = where;
    }
}

/*
	routine to move an object and return a
	value used to set the negated statusOfObject values
	for the repository.
*/
int put(int obj, int where, int pval) {
    move(obj, where);
    return (-1) - pval;
}

/*
	Routine to check for presence
	of dwarves..
*/
int dcheck(void) {
    int i;

    for (i = 1; i < (DWARFMAX - 1); ++i) {
        if (dwarfLocations[i] == actualLocation) {
            return i;
        }
    }
    return 0;
}

/*
	Determine liquid in the bottle
*/
int liq(void) {
    int i, j;
    i = stateOfObject[BOTTLE];
    j = -1 - i;
    return liq2(i > j ? i : j);
}

/*
	Determine liquid at a location
*/
int liqloc(int loc) {
    if (locationStatus[loc] & LIQUID) {
        return liq2(locationStatus[loc] & WATOIL);
    }

    return liq2(1);
}

/*
	Convert  0 to WATER
		 1 to nothing
		 2 to OIL
*/
int liq2(int pbottle) {
    return (1 - pbottle) * WATER + (pbottle >> 1) * (WATER + OIL);
}

/*
	Fatal error routine
*/

#define FATAL_ERROR_STRING_LENGTH 23
const __attribute__((__progmem__)) char fatalErrorString[FATAL_ERROR_STRING_LENGTH] = "Fatal error number ";

void bug(int n) {
    char * intermediateString = malloc(FATAL_ERROR_STRING_LENGTH);
    flashHelper->loadFarStringFromFlash(intermediateString, pgm_get_far_address(fatalErrorString));
    printf("%s%d\n", intermediateString, n);
    free(intermediateString);

    exit(-1);
}