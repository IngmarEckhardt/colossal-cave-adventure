
/*	program VERB.C						*\
\*	WARNING: "advent.c" allocates GLOBAL storage space by	*\
\*		including "advdef.h".				*\
\*		All other modules use "advdec.h".		*/

#include <stdio.h> /* drv = 1.1st file 2.def 3.A	*/
#include <stdlib.h>
#include <avr/pgmspace.h>

#include "advent.h"
#include "advdec.h"


/*
	Routine to process a transitive verb
*/
#define VERB_NOT_IMPLEMENTED_STRING_LENGTH 35
const __attribute__((__progmem__)) char verbNotImplementedString[VERB_NOT_IMPLEMENTED_STRING_LENGTH] = "This verb is not implemented yet.\n";

void transitiveVerb(void) {
    switch (actualVerb) {
        case CALM:
        case WALK:
        case QUIT:
        case SCORE:
        case FOO:
        case BRIEF:
        case SUSPEND:
        case HOURS:
        case LOG: {
            speakDefaultAnswerTo(actualVerb);
            break;
        }
        case TAKE: {
            tvTake();
            break;
        }
        case DROP: {
            tvDrop();
            break;
        }
        case OPEN:
        case LOCK: {
            tvOpen();
            break;
        }
        case SAY: {
            tvSay();
            break;
        }
        case NOTHING: {
            speakReaction(54);
            break;
        }
        case ON: {
            tvOn();
            break;
        }
        case OFF: {
            tvOff();
            break;
        }
        case WAVE: {
            tvWave();
            break;
        }
        case KILL: {
            tvKill();
            break;
        }
        case POUR: {
            tvPour();
            break;
        }
        case EAT: {
            tvEat();
            break;
        }
        case DRINK: {
            tvDrink();
            break;
        }
        case RUB: {
            if (actualObject != LAMP) {
                speakReaction(76);
            } else {
                speakDefaultAnswerTo(RUB);
            }
            break;
        }
        case THROW: {
            tvThrow();
            break;
        }
        case FEED: {
            tvFeed();
            break;
        }
        case FIND: {
        }
        case INVENTORY: {
            tvFind();
            break;
        }
        case FILL: {
            tvFill();
            break;
        }
        case READ: {
            tvRead();
            break;
        }
        case BLAST: {
            tvBlast();
            break;
        }
        case BREAK: {
            tvBreak();
            break;
        }
        case WAKE: {
            tvWake();
            break;
        }
        default: {
            char * intermediateString = malloc(VERB_NOT_IMPLEMENTED_STRING_LENGTH);
            flashHelper->loadFarStringFromFlash(intermediateString, pgm_get_far_address(verbNotImplementedString));
            printf("%s", intermediateString);
            free(intermediateString);
        }
    }
}

/*
	CARRY TAKE etc.
*/
void tvTake(void) {
    int msg;
    int i;

    if (isInInventory(actualObject)) {
        speakDefaultAnswerTo(actualVerb);
        return;
    }
    /*
       special case objects and secondObjectLocation objects
    */
    msg = 25;
    if (actualObject == PLANT && stateOfObject[PLANT] <= 0) {
        msg = 115;
    }
    if (actualObject == BEAR && stateOfObject[BEAR] == 1) {
        msg = 169;
    }
    if (actualObject == CHAIN && stateOfObject[BEAR] != 0) {
        msg = 170;
    }
    if (secondObjectLocation[actualObject]) {
        speakReaction(msg);
        return;
    }
    /*
       special case for liquids
    */
    if (actualObject == WATER || actualObject == OIL) {
        if (!here(BOTTLE) || liq() != actualObject) {
            actualObject = BOTTLE;
            if (isInInventory(BOTTLE) && stateOfObject[BOTTLE] == 1) {
                tvFill();
                return;
            }
            if (stateOfObject[BOTTLE] != 1) {
                msg = 105;
            }
            if (!isInInventory(BOTTLE)) {
                msg = 104;
            }
            speakReaction(msg);
            return;
        }
        actualObject = BOTTLE;
    }
    if (countItemsHeld >= 7) {
        speakReaction(92);
        return;
    }
    /*
       special case for bird.
    */
    if (actualObject == BIRD && stateOfObject[BIRD] == 0) {
        if (isInInventory(ROD)) {
            speakReaction(26);
            return;
        }
        if (!isInInventory(CAGE)) {
            speakReaction(27);
            return;
        }
        stateOfObject[BIRD] = 1;
    }
    if ((actualObject == BIRD || actualObject == CAGE) && stateOfObject[BIRD] != 0) {
        carry((BIRD + CAGE) - actualObject, actualLocation);
    }
    carry(actualObject, actualLocation);
    /*
       handle liquid in bottle
    */
    i = liq();
    if (actualObject == BOTTLE && i != 0) {
        objectLocation[i] = UINT8_MAX;
    }
    speakReaction(54);
}

/*
	DROP etc.
*/
void tvDrop(void) {
    int i;

    /*
       check for dynamite
    */
    if (isInInventory(ROD2) && actualObject == ROD && !isInInventory(ROD)) {
        actualObject = ROD2;
    }
    if (!isInInventory(actualObject)) {
        speakDefaultAnswerTo(actualVerb);
        return;
    }
    /*
       snake and bird
    */
    if (actualObject == BIRD && here(SNAKE)) {
        speakReaction(30);
        if (caveIsClosed) {
            dwarfEnd();
        }
        destroy(SNAKE);
        stateOfObject[SNAKE] = -1;
    }
        /*
           coins and vending machine
        */
    else if (actualObject == COINS && here(VEND)) {
        destroy(COINS);
        drop(BATTERIES, actualLocation);
        printItemMessage(BATTERIES, 0);
        return;
    }
        /*
           bird and dragon (ouch!!)
        */
    else if (actualObject == BIRD && isOnEitherSideOfTwoSidedObject(DRAGON) && stateOfObject[DRAGON] == 0) {
        speakReaction(154);
        destroy(BIRD);
        stateOfObject[BIRD] = 0;
        if (objectLocation[SNAKE] != 0) {
            ++tally2;
        }
        return;
    }
    /*
       Bear and troll
    */
    if (actualObject == BEAR && isOnEitherSideOfTwoSidedObject(TROLL)) {
        speakReaction(163);
        move(TROLL, 0);
        move((TROLL + MAXOBJ), 0);
        move(TROLL2, 117);
        move((TROLL2 + MAXOBJ), 122);
        juggle(CHASM);
        stateOfObject[TROLL] = 2;
    }
        /*
           vase
        */
    else if (actualObject == VASE) {
        if (actualLocation == 96) {
            speakReaction(54);
        } else {
            stateOfObject[VASE] = isOnEitherSideOfTwoSidedObject(PILLOW) ? 0 : 2;
            printItemMessage(VASE, stateOfObject[VASE] + 1);
            if (stateOfObject[VASE] != 0) {
                secondObjectLocation[VASE] = UINT8_MAX;
            }
        }
    }
    /*
       handle liquid and bottle
    */
    i = liq();
    if (i == actualObject) {
        actualObject = BOTTLE;
    }
    if (actualObject == BOTTLE && i != 0) {
        objectLocation[i] = 0;
    }
    /*
       handle bird and cage
    */
    if (actualObject == CAGE && stateOfObject[BIRD] != 0) {
        drop(BIRD, actualLocation);
    }
    if (actualObject == BIRD) {
        stateOfObject[BIRD] = 0;
    }
    drop(actualObject, actualLocation);
}

/*
	LOCK, UNLOCK, OPEN, CLOSE etc.
*/
void tvOpen(void) {
    int msg, oyclam;

    switch (actualObject) {
        case CLAM: { }
        case OYSTER: {
            oyclam = (actualObject == OYSTER ? 1 : 0);
            if (actualVerb == LOCK) {
                msg = 61;
            } else if (!isInInventory(TRIDENT)) {
                msg = 122 + oyclam;
            } else if (isInInventory(actualObject)) {
                msg = 120 + oyclam;
            } else {
                msg = 124 + oyclam;
                destroy(CLAM);
                drop(OYSTER, actualLocation);
                drop(PEARL, 105);
            }
            break;
        }
        case DOOR: {
            msg = (stateOfObject[DOOR] == 1 ? 54 : 111);
            break;
        }
        case CAGE: {
            msg = 32;
            break;
        }
        case KEYS: {
            msg = 55;
            break;
        }
        case CHAIN: {
            if (!here(KEYS)) {
                msg = 31;
            } else if (actualVerb == LOCK) {
                if (stateOfObject[CHAIN] != 0) {
                    msg = 34;
                } else if (actualLocation != 130) {
                    msg = 173;
                } else {
                    stateOfObject[CHAIN] = 2;
                    if (isInInventory(CHAIN)) {
                        drop(CHAIN, actualLocation);
                    }
                    secondObjectLocation[CHAIN] = UINT8_MAX;
                    msg = 172;
                }
            } else {
                if (stateOfObject[BEAR] == 0) { msg = 41; }
                else if (stateOfObject[CHAIN] == 0) { msg = 37; }
                else {
                    stateOfObject[CHAIN] = 0;
                    secondObjectLocation[CHAIN] = 0;
                    if (stateOfObject[BEAR] != 3) { stateOfObject[BEAR] = 2; }
                    //the original calculation works also with UINT8_MAX instead of -1
                    secondObjectLocation[BEAR] = 2 -stateOfObject[BEAR];
                    msg = 171;
                }
            }
            break;
        }
        case GRATE: {
            if (!here(KEYS)) {
                msg = 31;
            } else if (caveIsClosing) {
                if (!panic) {
                    clock2 = 15;
                    ++panic;
                }
                msg = 130;
            } else {
                msg = 34 + stateOfObject[GRATE];
                stateOfObject[GRATE] = (actualVerb == LOCK ? 0 : 1);
                msg += 2 * stateOfObject[GRATE];
            }
            break;
        }
        default: {
            msg = 33;
        }
    }
    speakReaction(msg);
}

/*
	SAY etc.
*/
void tvSay(void) {
    int wtype, wval;

    computeTypeAndValue(word1, &wtype, &wval);
    printf("Okay.\n%s\n", wval == SAY ? word2 : word1);
}

/*
	ON etc.
*/
void tvOn(void) {
    if (!here(LAMP)) {
        speakDefaultAnswerTo(actualVerb);
    } else if (timeLimit < 0) {
        speakReaction(184);
    } else {
        stateOfObject[LAMP] = 1;
        speakReaction(39);
        if (locationIsDark) {
            locationIsDark = 0;
            describeLocation();
        }
    }
}

/*
	OFF etc.
*/
void tvOff(void) {
    if (!here(LAMP)) {
        speakDefaultAnswerTo(actualVerb);
    } else {
        stateOfObject[LAMP] = 0;
        speakReaction(40);
    }
}

/*
	WAVE etc.
*/
void tvWave(void) {
    if (!isInInventory(actualObject) && (actualObject != ROD || !isInInventory(ROD2))) {
        speakReaction(29);
    } else if (actualObject != ROD || !isOnEitherSideOfTwoSidedObject(FISSURE) || !isInInventory(actualObject) || caveIsClosing) {
        speakDefaultAnswerTo(actualVerb);
    } else {
        stateOfObject[FISSURE] = 1 - stateOfObject[FISSURE];
        printItemMessage(FISSURE, 2 - stateOfObject[FISSURE]);
    }
}

/*
	ATTACK, KILL etc.
*/
void tvKill(void) {
    int msg;
    int i;

    switch (actualObject) {
        case BIRD: {
            if (caveIsClosed) {
                msg = 137;
            } else {
                destroy(BIRD);
                stateOfObject[BIRD] = 0;
                if (objectLocation[SNAKE] == 19) {
                    ++tally2;
                }
                msg = 45;
            }
            break;
        }
        case 0: {
            msg = 44;
            break;
        }
        case CLAM: {
        }
        case OYSTER: {
            msg = 150;
            break;
        }
        case SNAKE: {
            msg = 46;
            break;
        }
        case DWARF: {
            if (caveIsClosed) {
                dwarfEnd();
            }
            msg = 49;
            break;
        }
        case TROLL: {
            msg = 157;
            break;
        }
        case BEAR: {
            msg = 165 + (stateOfObject[BEAR] + 1) / 2;
            break;
        }
        case DRAGON: {
            if (stateOfObject[DRAGON] != 0) {
                msg = 167;
                break;
            }
            if (!yesOrNoQuestion(49, 0, 0)) {
                return;
            }
            printItemMessage(DRAGON, 1);
            stateOfObject[DRAGON] = 2;
            stateOfObject[RUG] = 0;
            move((DRAGON + MAXOBJ), 0);
            move((RUG + MAXOBJ), 0);
            move(DRAGON, 120);
            move(RUG, 120);

            for (i = 1; i < MAXOBJ; ++i) {
                if (objectLocation[i] == 119 || objectLocation[i] == 121) { move(i, 120); }
            }
            newLocation = 120;
            return;
        }
        default: {
            speakDefaultAnswerTo(actualVerb);
            return;
        }
    }
    speakReaction(msg);
}

/*
	POUR
*/
void tvPour(void) {
    if (actualObject == BOTTLE || actualObject == 0) {
        actualObject = liq();
    }
    if (actualObject == 0) {
        needObject();
        return;
    }
    if (!isInInventory(actualObject)) {
        speakDefaultAnswerTo(actualVerb);
        return;
    }
    if (actualObject != OIL && actualObject != WATER) {
        speakReaction(78);
        return;
    }
    stateOfObject[BOTTLE] = 1;
    objectLocation[actualObject] = 0;
    if (isOnEitherSideOfTwoSidedObject(PLANT)) {
        if (actualObject != WATER) {
            speakReaction(112);
        } else {
            printItemMessage(PLANT, stateOfObject[PLANT] + 1);
            stateOfObject[PLANT] = (stateOfObject[PLANT] + 2) % 6;
            stateOfObject[PLANT2] = stateOfObject[PLANT] / 2;
            describeLocation();
        }
    } else if (isOnEitherSideOfTwoSidedObject(DOOR)) {
        stateOfObject[DOOR] = (actualObject == OIL ? 1 : 0);
        speakReaction(113 + stateOfObject[DOOR]);
    } else {
        speakReaction(77);
    }
}

/*
	EAT
*/
void tvEat(void) {
    int msg;

    switch (actualObject) {
        case FOOD: {
            destroy(FOOD);
            msg = 72;
            break;
        }
        case BIRD:
        case SNAKE:
        case CLAM:
        case OYSTER:
        case DWARF:
        case DRAGON:
        case TROLL:
        case BEAR: {
            msg = 71;
            break;
        }
        default: {
            speakDefaultAnswerTo(actualVerb);
            return;
        }
    }
    speakReaction(msg);
}

/*
	DRINK
*/
void tvDrink(void) {
    if (actualObject != WATER) {
        speakReaction(110);
    } else if (liq() != WATER || !here(BOTTLE)) {
        speakDefaultAnswerTo(actualVerb);
    } else {
        stateOfObject[BOTTLE] = 1;
        objectLocation[WATER] = 0;
        speakReaction(74);
    }
}

/*
	THROW etc.
*/
void tvThrow(void) {
    int msg;
    int i;

    if (isInInventory(ROD2) && actualObject == ROD && !isInInventory(ROD)) {
        actualObject = ROD2;
    }
    if (!isInInventory(actualObject)) {
        speakDefaultAnswerTo(actualVerb);
        return;
    }
    /*
       treasure to troll
    */
    if (isOnEitherSideOfTwoSidedObject(TROLL) && actualObject >= 50 && actualObject < MAXOBJ) {
        speakReaction(159);
        drop(actualObject, 0);
        move(TROLL, 0);
        move((TROLL + MAXOBJ), 0);
        drop(TROLL2, 117);
        drop((TROLL2 + MAXOBJ), 122);
        juggle(CHASM);
        return;
    }
    /*
       feed the bears...
    */
    if (actualObject == FOOD && here(BEAR)) {
        actualObject = BEAR;
        tvFeed();
        return;
    }
    /*
       if not axe, same as drop...
    */
    if (actualObject != AXE) {
        tvDrop();
        return;
    }
    /*
       AXE is THROWN
    */
    /*
       at a dwarf...
    */
    if ((i = dcheck())) {
        msg = 48;
        if (isRandomlyTrue(33)) {
            dwarfSawThePlayer[i] = dwarfLocations[i] = 0;
            msg = 47;
            ++amountDwarfKills;
            if (amountDwarfKills == 1) {
                msg = 149;
            }
        }
    }
        /*
           at a dragon...
        */
    else if (isOnEitherSideOfTwoSidedObject(DRAGON) && stateOfObject[DRAGON] == 0) {
        msg = 152;
        /*
           at the troll...
        */
    } else if (isOnEitherSideOfTwoSidedObject(TROLL)) {
        msg = 158;
        /*
           at the bear...
        */
    } else if (here(BEAR) && stateOfObject[BEAR] == 0) {
        speakReaction(164);
        drop(AXE, actualLocation);
        secondObjectLocation[AXE] = UINT8_MAX;
        stateOfObject[AXE] = 1;
        juggle(BEAR);
        return;
    }
        /*
           otherwise it is an attack
        */
    else {
        actualVerb = KILL;
        actualObject = 0;
        intransitiveVerb();
        return;
    }
    /*
       handle the left over axe...
    */
    speakReaction(msg);
    drop(AXE, actualLocation);
    describeLocation();
}

/*
	INVENTORY, FIND etc.
*/
void tvFind(void) {
    int msg;

    if (isInInventory(actualObject)) {
        msg = 24;
    } else if (caveIsClosed) {
        msg = 138;
    } else if (dcheck() && dwarfFlag >= 2 && actualObject == DWARF) {
        msg = 94;
    } else if (isOnEitherSideOfTwoSidedObject(actualObject) || (liq() == actualObject && here(BOTTLE)) || actualObject == liqloc(actualLocation)) {
        msg = 94;
    } else {
        speakDefaultAnswerTo(actualVerb);
        return;
    }
    speakReaction(msg);
}

/*
	FILL
*/
void tvFill(void) {
    int msg;
    int i;

    switch (actualObject) {
        case BOTTLE: {
            if (liq() != 0) {
                msg = 105;
            } else if (liqloc(actualLocation) == 0) {
                msg = 106;
            } else {
                stateOfObject[BOTTLE] = locationStatus[actualLocation] & WATOIL;
                i = liq();
                if (isInInventory(BOTTLE)) {
                    objectLocation[i] = UINT8_MAX;
                }
                msg = (i == OIL ? 108 : 107);
            }
            break;
        }
        case VASE: {
            if (liqloc(actualLocation) == 0) {
                msg = 144;
                break;
            }
            if (!isInInventory(VASE)) {
                msg = 29;
                break;
            }
            speakReaction(145);
            tvDrop();
            return;
        }
        default: {
            msg = 29;
        }
    }
    speakReaction(msg);
}

/*
	FEED
*/
void tvFeed(void) {
    int msg;

    switch (actualObject) {
        case BIRD: {
            msg = 100;
            break;
        }
        case DWARF: {
            if (!here(FOOD)) {
                speakDefaultAnswerTo(actualVerb);
                return;
            }
            ++dwarfFlag;
            msg = 103;
            break;
        }
        case BEAR: {
            if (!here(FOOD)) {
                if (stateOfObject[BEAR] == 0) {
                    msg = 102;
                } else if (stateOfObject[BEAR] == 3) {
                    msg = 110;
                } else {
                    speakDefaultAnswerTo(actualVerb);
                    return;
                }
                break;
            }
            destroy(FOOD);
            stateOfObject[BEAR] = 1;
            secondObjectLocation[AXE] = 0;
            stateOfObject[AXE] = 0;
            msg = 168;
            break;
        }
        case DRAGON: {
            msg = (stateOfObject[DRAGON] != 0 ? 110 : 102);
            break;
        }
        case TROLL: {
            msg = 182;
            break;
        }
        case SNAKE: {
            if (caveIsClosed || !here(BIRD)) {
                msg = 102;
                break;
            }
            msg = 101;
            destroy(BIRD);
            stateOfObject[BIRD] = 0;
            ++tally2;
            break;
        }
        default: {
            msg = 14;
        }
    }
    speakReaction(msg);
}

/*
	READ etc.
*/
void tvRead(void) {
    int msg;

    msg = 0;
    if (dark()) {
        printf("I see no %s here.\n", searchObjStringInBothWords(actualObject));
        return;
    }
    switch (actualObject) {
        case MAGAZINE: {
            msg = 190;
            break;
        }
        case TABLET: {
            msg = 196;
            break;
        }
        case MESSAGE: {
            msg = 191;
            break;
        }
        case OYSTER: {
            if (!isInInventory(OYSTER) || !caveIsClosed) {break;}

            yesOrNoQuestion(192, 193, 54);
            return;
        }
        default: {
        }
    }
    if (msg) {
        speakReaction(msg);
    } else {
        speakDefaultAnswerTo(actualVerb);
    }
}

/*
	BLAST etc.
*/
void tvBlast(void) {
    if (stateOfObject[ROD2] < 0 || !caveIsClosed) {
        speakDefaultAnswerTo(actualVerb);
    } else {
        bonus = 133;
        if (actualLocation == 115) { bonus = 134; }
        if (here(ROD2)) { bonus = 135; }
        speakReaction(bonus);
        normalEnd();
    }
}

/*
	BREAK etc.
*/
void tvBreak(void) {
    int msg;

    if (actualObject == MIRROR) {
        msg = 148;
        if (caveIsClosed) {
            speakReaction(197);
            dwarfEnd();
        }
    } else if (actualObject == VASE && stateOfObject[VASE] == 0) {
        msg = 198;
        if (isInInventory(VASE)) { drop(VASE, actualLocation); }
        stateOfObject[VASE] = 2;
        secondObjectLocation[VASE] = UINT8_MAX;
    } else {
        speakDefaultAnswerTo(actualVerb);
        return;
    }
    speakReaction(msg);
}

/*
	WAKE etc.
*/
void tvWake(void) {
    if (actualObject != DWARF || !caveIsClosed) {
        speakDefaultAnswerTo(actualVerb);
    } else {
        speakReaction(199);
        dwarfEnd();
    }
}

/*
	Routine to speak default verb message
*/
void speakDefaultAnswerTo(int verb) {
    char i;
    if (verb < 1 || verb > 31) { bug(39); }

    i = actmsg[verb];
    if (i) { speakReaction(i); }
}

/*
	Routine to indicate no reasonable
	object for verb found.  Used mostly by
	intransitive verbs.
*/
void needObject(void) {
    int wtype, wval;

    computeTypeAndValue(word1, &wtype, &wval);
    printf("%s what?\n", wtype == 2 ? word1 : word2);
}
