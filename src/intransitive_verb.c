#include <stdio.h> /* drv = 1.1st file 2.def 3.A	*/
#include <stdlib.h>
#include <avr/pgmspace.h>
#include "advent.h"
#include "advdec.h"


#define SIZE_NOT_IMPLEMENTED_STRING 39
const __attribute__((__progmem__)) char notImplementedString[SIZE_NOT_IMPLEMENTED_STRING] = "This intransitive not implemented yet\n";
/*
	Routines to process intransitive verbs
*/
void intransitiveVerb(void) {
    switch (actualVerb) {
        case DROP:
        case SAY:
        case WAVE:
        case CALM:
        case RUB:
        case THROW:
        case FIND:
        case FEED:
        case BREAK:
        case WAKE: {
            needObject();
            break;
        }
        case TAKE: {
            ivTake();
            break;
        }
        case OPEN:
        case LOCK: {
            ivOpen();
            break;
        }
        case NOTHING: {
            speakReaction(54);
            break;
        }
        case ON:
        case OFF:
        case POUR: {
            transitiveVerb();
            break;
        }
        case WALK: {
            speakDefaultAnswerTo(actualVerb);
            break;
        }
        case KILL: {
            ivKill();
            break;
        }
        case EAT: {
            ivEat();
            break;
        }
        case DRINK: {
            ivDrink();
            break;
        }
        case QUIT: {
            ivQuit();
            break;
        }
        case FILL: {
            ivFill();
            break;
        }
        case BLAST: {
            tvBlast();
            break;
        }
        case SCORE: {
            calcScore();
            break;
        }
        case FOO: {
            ivFoo();
            break;
        }
        case SUSPEND: {
            break;
        }
        case INVENTORY: {
            ivInventory();
            break;
        }
        default: {
            char * intermediateString = malloc(SIZE_NOT_IMPLEMENTED_STRING);
            flashHelper->loadFarStringFromFlash(intermediateString, pgm_get_far_address(notImplementedString));
            printf("%s", intermediateString);
            free(intermediateString);
        }

    }
}

/*
	CARRY, TAKE etc.
*/
void ivTake(void) {
    int anobj, item;

    anobj = 0;
    for (item = 1; item < MAXOBJ; ++item) {
        if (objectLocation[item] == actualLocation) {
            if (anobj != 0) {
                needObject();
                return;
            }
            anobj = item;
        }
    }
    if (anobj == 0 || (dcheck() && dwarfFlag >= 2)) {
        needObject();
        return;
    }
    actualObject = anobj;
    tvTake();
}

/*
	OPEN, LOCK, UNLOCK
*/
void ivOpen(void) {
    if (here(CLAM)) { actualObject = CLAM; }

    if (here(OYSTER)) { actualObject = OYSTER; }

    if (isOnEitherSideOfTwoSidedObject(DOOR)) { actualObject = DOOR; }

    if (isOnEitherSideOfTwoSidedObject(GRATE)) { actualObject = GRATE; }

    if (here(CHAIN)) {
        if (actualObject != 0) {
            needObject();
            return;
        }
        actualObject = CHAIN;
    }
    if (actualObject == 0) {
        speakReaction(28);
        return;
    }
    tvOpen();
}

/*
	ATTACK, KILL etc
*/
void ivKill(void) {
    alternativeObject = 0;
    if (dcheck() && dwarfFlag >= 2) { actualObject = DWARF; }

    if (here(SNAKE)) { addObjectIntransitiv(SNAKE); }

    if (isOnEitherSideOfTwoSidedObject(DRAGON) && stateOfObject[DRAGON] == 0) { addObjectIntransitiv(DRAGON); }

    if (isOnEitherSideOfTwoSidedObject(TROLL)) { addObjectIntransitiv(TROLL); }

    if (here(BEAR) && stateOfObject[BEAR] == 0) { addObjectIntransitiv(BEAR); }

    if (alternativeObject != 0) {
        needObject();
        return;
    }
    if (actualObject != 0) {
        tvKill();
        return;
    }
    if (here(BIRD) && actualVerb != THROW) { actualObject = BIRD; }

    if (here(CLAM) || here(OYSTER)) { addObjectIntransitiv(CLAM); }

    if (alternativeObject != 0) {
        needObject();
        return;
    }
    tvKill();
}

/*
	EAT
*/
void ivEat(void) {
    if (!here(FOOD)) {
        needObject();
    } else {
        actualObject = FOOD;
        tvEat();
    }
}

/*
	DRINK
*/
void ivDrink(void) {
    if (liqloc(actualLocation) != WATER && (liq() != WATER || !here(BOTTLE))) {
        needObject();
    } else {
        actualObject = WATER;
        tvDrink();
    }
}

/*
	QUIT
*/
void ivQuit(void) {
    if ((playerWantToQuitFlag = yesOrNoQuestion(22, 54, 54))) { normalEnd(); }
}

/*
	FILL
*/
void ivFill(void) {
    if (!here(BOTTLE)) {
        needObject();
    } else {
        actualObject = BOTTLE;
        tvFill();
    }
}

/*
	Handle fee fie foe foo...
*/
void ivFoo(void) {
    int k, msg;

    k = lookUpVocabulary(word1, 3000);
    msg = 42;
    if (foobar != 1 - k) {
        if (foobar != 0) { msg = 151; }
        speakReaction(msg);
        return;
    }

    foobar = k;
    if (k != 4) { return; }

    foobar = 0;
    if (objectLocation[EGGS] == 92 || (isInInventory(EGGS) && actualLocation == 92)) {
        speakReaction(msg);
        return;
    }

    if (objectLocation[EGGS] == 0 && objectLocation[TROLL] == 0 && stateOfObject[TROLL] == 0) {
        stateOfObject[TROLL] = 1;
    }

    if (here(EGGS)) { k = 1; }
    else if (actualLocation == 92) { k = 0; }
    else { k = 2; }

    move(EGGS, 92);
    printItemMessage(EGGS, k);
    return;
}

/*
	read etc...
*/
/*  no room for this...
ivread()
{
	if (here(MAGAZINE))
		object = MAGAZINE;
	if (here(TABLET))
		object = object*100 + TABLET;
	if (here(MESSAGE))
		object = object*100 + MESSAGE;
	if (object > 100 || object == 0 || dark()) {
		needObject();
		return;
	}
	tvRead();
}
*/

/*
	INVENTORY
*/
void ivInventory(void) {
    int i, msg;

    msg = 98;
    for (i = 1; i <= 64; ++i) {
        if (i == BEAR || !isInInventory(i)) {
            continue;
        }
        if (msg) {
            speakReaction(99);
        }
        msg = 0;
        printItemMessage(i, -1);
    }
    if (isInInventory(BEAR)) {
        msg = 141;
    }
    if (msg) {
        speakReaction(msg);
    }
}

/*
	ensure uniqueness as objects are searched
	out for an intransitive verb
*/
void addObjectIntransitiv(int object) {
    if (alternativeObject != 0) {
        return;
    }
    if (actualObject != 0) {
        alternativeObject = -1;
        return;
    }
    actualObject = object;
}
