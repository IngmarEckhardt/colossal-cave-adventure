
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
//#include "advent1.h"
//#include "advent2.h"
//#include "advent3.h"
//#include "advent4.h"



/*
	Routine to fill travel array for a given location
*/
void gettrav(int loc) {
    char atrav[145] = {0}; /* max length of any cave pos = 144 bytes */
    char * aptr;
    long t;
    int i;

    if (loc <= 0 || loc >= MAXLOC) {
        bug(42);
    }


    char * cave = getCave(loc);
    if (cave == NULL) {
        bug(1);
    }

//	if (strlen(cave[location - 1]) > sizeof(atrav))
//	if (strlen(cave) > sizeof(atrav)) {
//        bug(43);
//    }


//	strcpy(atrav, cave[location - 1]);
    strcpy(atrav, cave);
    free(cave);

    while ((aptr = strrchr(atrav, ','))) {
        *aptr = '\0'; /* terminate substring	*/
    }

    aptr = &atrav[0];
    for (i = 0; i < MAXTRAV - 1; ++i) {

        t = atol(aptr); /* convert to long int	*/

        travel[i].tcond = (int) (t % 1000L);
        t /= 1000L;
        travel[i].tverb = (int) (t % 1000L);
        t /= 1000L;
        travel[i].tdest = (int) (t % 1000L);

        while (*(aptr++)) {} /* to next substring	*/

        if (!(*aptr)) {
            travel[++i].tdest = -1; /* end of array	*/

            if (debugFlag) {
                for (i = 0; i < MAXTRAV; ++i) {
                    printf("cave[%d] = %d %d %d\n", loc,
                           travel[i].tdest, travel[i].tverb, travel[i].tcond);
                }
            }
            return; /* terminate for loop	*/
        }
    }
    bug(33);
}

/*
	Routine to request a yes or no answer to a question.
*/
int yes(int msg1, int msg2, int msg3) {
    char answer[80];

    if (msg1) {
        rspeak(msg1);
    }
    fputs("> ", stdout);
    fflush(stdout);
    if (NULL == fgets(answer, 80, stdin)) {
        exit(0);
    }
    if (tolower(answer[0]) == 'n') {
        if (msg3) {
            rspeak(msg3);
        }
        return 0;
    }
    if (msg2) {
        rspeak(msg2);
    }
    return 1;
}

/*
	Print a location description from "advent4.txt"
*/
void rspeak(int msg) {

    //	fputs(adventtxt4[msg - 1], stdout);

    char * message = getAction(msg);
    fputs(message, stdout);
    free(message);
//	return;
}

/*
	Print an item message for a given state from "advent3.txt"
*/
void pspeak(int item, int state) {

//	const char *p;
    char * p;

    if (item > 64) {
        bug(40);
        return;
    }

//	p = adventtxt3[item - 1];
    p = getObject(item);

    if (p == NULL) {
        bug(31);
    } else {
        int c;
        int n = state + 2;

        while (n--) {
            while ((c = *p++) != '/') {
                if (c == '\0') {
                    bug(32);
                }
            }
        }
        for (n = 0; p[n] != '\0' && p[n] != '/'; n++)
            putchar(p[n]);
    }
    free(p);
}

/*
	Print a long location description from "advent1.txt"
*/
void desclg(int loc) {

//	fputs(adventtxt1[location - 1], stdout);
    char * message = getLongLocation(loc);
    fputs(message, stdout);
    free(message);

}

/*
	Print a short location description from "advent2.txt"
*/
void descsh(int loc) {

//	fputs(adventtxt2[location - 1], stdout);
    char * message = getShortLocation(loc);
    fputs(message, stdout);
    free(message);
}

/*
	look-up vocabulary word in lex-ordered table.  words may have
	two entries with different codes. if minimum acceptable value
	= 0, then return minimum of different codes.  last word CANNOT
	have two entries(due to binary sort).
	word is the word to look up.
	val  is the minimum acceptable value,
		if != 0 return %1000
*/
int vocab(char * word, int val) {
    int v1, v2;

    if ((v1 = binary(word, MAXWC)) >= 0) {
        v2 = binary(word, MAXWC - 1);
        if (v2 < 0) {
            v2 = v1;
        }
        int16_t codeV1 = (int16_t) loadCode(v1);
        int16_t codeV2 = (int16_t) loadCode(v2);
        if (!val) {
//			return wc[v1].acode < wc[v2].acode ? wc[v1].acode : wc[v2].acode;
            return codeV1 < codeV2 ? codeV1 : codeV2;
        }
//		if (val <= wc[v1].acode)
        if (val <= codeV1) {
//			return wc[v1].acode % 1000;
            return codeV1 % 1000;
//		else if (val <= wc[v2].acode)
        } else if (val <= codeV2) {
//			return wc[v2].acode % 1000;
            return codeV2 % 1000;
        } else {
            return -1;
        }
    } else {
        return -1;
    }
}

int binary(char * w, int maxwc) {
    int lo, mid, hi, check;

    lo = 0;
    hi = maxwc - 1;
    while (lo <= hi) {
        mid = (lo + hi) / 2;

//		if ((check = strcmp(w, wctable[mid].aword)) < 0)
        if ((check = compareWord(w, mid)) < 0) {
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
int dark(void) { return !(locationStatus[location] & LIGHT) && (!objectStatus[LAMP] || !here(LAMP)); }

/*
	Routine to tell if an item is present.
*/
int here(int item) { return objectLocation[item] == location || toting(item); }

/*
	Routine to tell if an item is being carried.
*/
int toting(int item) { return objectLocation[item] == UINT8_MAX; }

/*
	Routine to tell if a location causes
	a forced move.
*/
int forced(int atloc) { return locationStatus[atloc] == 2; }

/*
	Routine true x% of the time.
*/
int pct(int x) { return rand() % 100 < x; }

/*
	Routine to tell if player is on
	either side of a two sided object.
*/
int at(int item) { return objectLocation[item] == location || secondObjectLocation[item] == location; }

/*
	Routine to destroy an object
*/
void dstroy(int obj) { move(obj, 0); }

/*
	Routine to move an object
*/
void move(int obj, int where) {
    int from;

    from = (obj < MAXOBJ) ? objectLocation[obj] : secondObjectLocation[obj - MAXOBJ];
    if (from > 0 && from <= 300) {
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
	value used to set the negated objectStatus values
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
        if (dwarfLocations[i] == location) {
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
    i = objectStatus[BOTTLE];
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