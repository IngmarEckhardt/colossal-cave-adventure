
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

void trverb(void) {
    switch (verb) {
        case CALM:
        case WALK:
        case QUIT:
        case SCORE:
        case FOO:
        case BRIEF:
        case SUSPEND:
        case HOURS:
        case LOG: {
            actspk(verb);
            break;
        }
        case TAKE: {
            vtake();
            break;
        }
        case DROP: {
            vdrop();
            break;
        }
        case OPEN:
        case LOCK: {
            vopen();
            break;
        }
        case SAY: {
            vsay();
            break;
        }
        case NOTHING: {
            rspeak(54);
            break;
        }
        case ON: {
            von();
            break;
        }
        case OFF: {
            voff();
            break;
        }
        case WAVE: {
            vwave();
            break;
        }
        case KILL: {
            vkill();
            break;
        }
        case POUR: {
            vpour();
            break;
        }
        case EAT: {
            veat();
            break;
        }
        case DRINK: {
            vdrink();
            break;
        }
        case RUB: {
            if (object != LAMP) {
                rspeak(76);
            } else {
                actspk(RUB);
            }
            break;
        }
        case THROW: {
            vthrow();
            break;
        }
        case FEED: {
            vfeed();
            break;
        }
        case FIND: {
        }
        case INVENTORY: {
            vfind();
            break;
        }
        case FILL: {
            vfill();
            break;
        }
        case READ: {
            vread();
            break;
        }
        case BLAST: {
            vblast();
            break;
        }
        case BREAK: {
            vbreak();
            break;
        }
        case WAKE: {
            vwake();
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
void vtake(void) {
    int msg;
    int i;

    if (toting(object)) {
        actspk(verb);
        return;
    }
    /*
       special case objects and secondObjectLocation objects
    */
    msg = 25;
    if (object == PLANT && objectStatus[PLANT] <= 0) {
        msg = 115;
    }
    if (object == BEAR && objectStatus[BEAR] == 1) {
        msg = 169;
    }
    if (object == CHAIN && objectStatus[BEAR] != 0) {
        msg = 170;
    }
    if (secondObjectLocation[object]) {
        rspeak(msg);
        return;
    }
    /*
       special case for liquids
    */
    if (object == WATER || object == OIL) {
        if (!here(BOTTLE) || liq() != object) {
            object = BOTTLE;
            if (toting(BOTTLE) && objectStatus[BOTTLE] == 1) {
                vfill();
                return;
            }
            if (objectStatus[BOTTLE] != 1) {
                msg = 105;
            }
            if (!toting(BOTTLE)) {
                msg = 104;
            }
            rspeak(msg);
            return;
        }
        object = BOTTLE;
    }
    if (countItemsHeld >= 7) {
        rspeak(92);
        return;
    }
    /*
       special case for bird.
    */
    if (object == BIRD && objectStatus[BIRD] == 0) {
        if (toting(ROD)) {
            rspeak(26);
            return;
        }
        if (!toting(CAGE)) {
            rspeak(27);
            return;
        }
        objectStatus[BIRD] = 1;
    }
    if ((object == BIRD || object == CAGE) && objectStatus[BIRD] != 0) {
        carry((BIRD + CAGE) - object, location);
    }
    carry(object, location);
    /*
       handle liquid in bottle
    */
    i = liq();
    if (object == BOTTLE && i != 0) {
        objectLocation[i] = UINT8_MAX;
    }
    rspeak(54);
}

/*
	DROP etc.
*/
void vdrop(void) {
    int i;

    /*
       check for dynamite
    */
    if (toting(ROD2) && object == ROD && !toting(ROD)) {
        object = ROD2;
    }
    if (!toting(object)) {
        actspk(verb);
        return;
    }
    /*
       snake and bird
    */
    if (object == BIRD && here(SNAKE)) {
        rspeak(30);
        if (closed) {
            dwarfend();
        }
        dstroy(SNAKE);
        objectStatus[SNAKE] = -1;
    }
        /*
           coins and vending machine
        */
    else if (object == COINS && here(VEND)) {
        dstroy(COINS);
        drop(BATTERIES, location);
        pspeak(BATTERIES, 0);
        return;
    }
        /*
           bird and dragon (ouch!!)
        */
    else if (object == BIRD && at(DRAGON) && objectStatus[DRAGON] == 0) {
        rspeak(154);
        dstroy(BIRD);
        objectStatus[BIRD] = 0;
        if (objectLocation[SNAKE] != 0) {
            ++tally2;
        }
        return;
    }
    /*
       Bear and troll
    */
    if (object == BEAR && at(TROLL)) {
        rspeak(163);
        move(TROLL, 0);
        move((TROLL + MAXOBJ), 0);
        move(TROLL2, 117);
        move((TROLL2 + MAXOBJ), 122);
        juggle(CHASM);
        objectStatus[TROLL] = 2;
    }
        /*
           vase
        */
    else if (object == VASE) {
        if (location == 96) {
            rspeak(54);
        } else {
            objectStatus[VASE] = at(PILLOW) ? 0 : 2;
            pspeak(VASE, objectStatus[VASE] + 1);
            if (objectStatus[VASE] != 0) {
                secondObjectLocation[VASE] = UINT8_MAX;
            }
        }
    }
    /*
       handle liquid and bottle
    */
    i = liq();
    if (i == object) {
        object = BOTTLE;
    }
    if (object == BOTTLE && i != 0) {
        objectLocation[i] = 0;
    }
    /*
       handle bird and cage
    */
    if (object == CAGE && objectStatus[BIRD] != 0) {
        drop(BIRD, location);
    }
    if (object == BIRD) {
        objectStatus[BIRD] = 0;
    }
    drop(object, location);
}

/*
	LOCK, UNLOCK, OPEN, CLOSE etc.
*/
void vopen(void) {
    int msg, oyclam;

    switch (object) {
        case CLAM: {
        }
        case OYSTER: {
            oyclam = (object == OYSTER ? 1 : 0);
            if (verb == LOCK) {
                msg = 61;
            } else if (!toting(TRIDENT)) {
                msg = 122 + oyclam;
            } else if (toting(object)) {
                msg = 120 + oyclam;
            } else {
                msg = 124 + oyclam;
                dstroy(CLAM);
                drop(OYSTER, location);
                drop(PEARL, 105);
            }
            break;
        }
        case DOOR: {
            msg = (objectStatus[DOOR] == 1 ? 54 : 111);
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
            } else if (verb == LOCK) {
                if (objectStatus[CHAIN] != 0) {
                    msg = 34;
                } else if (location != 130) {
                    msg = 173;
                } else {
                    objectStatus[CHAIN] = 2;
                    if (toting(CHAIN)) {
                        drop(CHAIN, location);
                    }
                    secondObjectLocation[CHAIN] = UINT8_MAX;
                    msg = 172;
                }
            } else {
                if (objectStatus[BEAR] == 0) { msg = 41; }
                else if (objectStatus[CHAIN] == 0) { msg = 37; }
                else {
                    objectStatus[CHAIN] = 0;
                    secondObjectLocation[CHAIN] = 0;
                    if (objectStatus[BEAR] != 3) { objectStatus[BEAR] = 2; }
                    //the original calculation works also with UINT8_MAX instead of -1
                    secondObjectLocation[BEAR] = 2 - objectStatus[BEAR];
                    msg = 171;
                }
            }
            break;
        }
        case GRATE: {
            if (!here(KEYS)) {
                msg = 31;
            } else if (closing) {
                if (!panic) {
                    clock2 = 15;
                    ++panic;
                }
                msg = 130;
            } else {
                msg = 34 + objectStatus[GRATE];
                objectStatus[GRATE] = (verb == LOCK ? 0 : 1);
                msg += 2 * objectStatus[GRATE];
            }
            break;
        }
        default: {
            msg = 33;
        }
    }
    rspeak(msg);
}

/*
	SAY etc.
*/
void vsay(void) {
    int wtype, wval;

    analyze(word1, &wtype, &wval);
    printf("Okay.\n%s\n", wval == SAY ? word2 : word1);
}

/*
	ON etc.
*/
void von(void) {
    if (!here(LAMP)) {
        actspk(verb);
    } else if (timeLimit < 0) {
        rspeak(184);
    } else {
        objectStatus[LAMP] = 1;
        rspeak(39);
        if (wzdark) {
            wzdark = 0;
            describe();
        }
    }
}

/*
	OFF etc.
*/
void voff(void) {
    if (!here(LAMP)) {
        actspk(verb);
    } else {
        objectStatus[LAMP] = 0;
        rspeak(40);
    }
}

/*
	WAVE etc.
*/
void vwave(void) {
    if (!toting(object) && (object != ROD || !toting(ROD2))) {
        rspeak(29);
    } else if (object != ROD || !at(FISSURE) || !toting(object) || closing) {
        actspk(verb);
    } else {
        objectStatus[FISSURE] = 1 - objectStatus[FISSURE];
        pspeak(FISSURE, 2 - objectStatus[FISSURE]);
    }
}

/*
	ATTACK, KILL etc.
*/
void vkill(void) {
    int msg;
    int i;

    switch (object) {
        case BIRD: {
            if (closed) {
                msg = 137;
            } else {
                dstroy(BIRD);
                objectStatus[BIRD] = 0;
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
            if (closed) {
                dwarfend();
            }
            msg = 49;
            break;
        }
        case TROLL: {
            msg = 157;
            break;
        }
        case BEAR: {
            msg = 165 + (objectStatus[BEAR] + 1) / 2;
            break;
        }
        case DRAGON: {
            if (objectStatus[DRAGON] != 0) {
                msg = 167;
                break;
            }
            if (!yes(49, 0, 0)) {
                return;
            }
            pspeak(DRAGON, 1);
            objectStatus[DRAGON] = 2;
            objectStatus[RUG] = 0;
            move((DRAGON + MAXOBJ), -1);
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
            actspk(verb);
            return;
        }
    }
    rspeak(msg);
}

/*
	POUR
*/
void vpour(void) {
    if (object == BOTTLE || object == 0) {
        object = liq();
    }
    if (object == 0) {
        needobj();
        return;
    }
    if (!toting(object)) {
        actspk(verb);
        return;
    }
    if (object != OIL && object != WATER) {
        rspeak(78);
        return;
    }
    objectStatus[BOTTLE] = 1;
    objectLocation[object] = 0;
    if (at(PLANT)) {
        if (object != WATER) {
            rspeak(112);
        } else {
            pspeak(PLANT, objectStatus[PLANT] + 1);
            objectStatus[PLANT] = (objectStatus[PLANT] + 2) % 6;
            objectStatus[PLANT2] = objectStatus[PLANT] / 2;
            describe();
        }
    } else if (at(DOOR)) {
        objectStatus[DOOR] = (object == OIL ? 1 : 0);
        rspeak(113 + objectStatus[DOOR]);
    } else {
        rspeak(77);
    }
}

/*
	EAT
*/
void veat(void) {
    int msg;

    switch (object) {
        case FOOD: {
            dstroy(FOOD);
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
            actspk(verb);
            return;
        }
    }
    rspeak(msg);
}

/*
	DRINK
*/
void vdrink(void) {
    if (object != WATER) {
        rspeak(110);
    } else if (liq() != WATER || !here(BOTTLE)) {
        actspk(verb);
    } else {
        objectStatus[BOTTLE] = 1;
        objectLocation[WATER] = 0;
        rspeak(74);
    }
}

/*
	THROW etc.
*/
void vthrow(void) {
    int msg;
    int i;

    if (toting(ROD2) && object == ROD && !toting(ROD)) {
        object = ROD2;
    }
    if (!toting(object)) {
        actspk(verb);
        return;
    }
    /*
       treasure to troll
    */
    if (at(TROLL) && object >= 50 && object < MAXOBJ) {
        rspeak(159);
        drop(object, 0);
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
    if (object == FOOD && here(BEAR)) {
        object = BEAR;
        vfeed();
        return;
    }
    /*
       if not axe, same as drop...
    */
    if (object != AXE) {
        vdrop();
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
        if (pct(33)) {
            dwarfSeenFlag[i] = dwarfLocations[i] = 0;
            msg = 47;
            ++dkill;
            if (dkill == 1) {
                msg = 149;
            }
        }
    }
        /*
           at a dragon...
        */
    else if (at(DRAGON) && objectStatus[DRAGON] == 0) {
        msg = 152;
        /*
           at the troll...
        */
    } else if (at(TROLL)) {
        msg = 158;
        /*
           at the bear...
        */
    } else if (here(BEAR) && objectStatus[BEAR] == 0) {
        rspeak(164);
        drop(AXE, location);
        secondObjectLocation[AXE] = UINT8_MAX;
        objectStatus[AXE] = 1;
        juggle(BEAR);
        return;
    }
        /*
           otherwise it is an attack
        */
    else {
        verb = KILL;
        object = 0;
        itverb();
        return;
    }
    /*
       handle the left over axe...
    */
    rspeak(msg);
    drop(AXE, location);
    describe();
}

/*
	INVENTORY, FIND etc.
*/
void vfind(void) {
    int msg;

    if (toting(object)) {
        msg = 24;
    } else if (closed) {
        msg = 138;
    } else if (dcheck() && dwarfFlag >= 2 && object == DWARF) {
        msg = 94;
    } else if (at(object) || (liq() == object && here(BOTTLE)) || object == liqloc(location)) {
        msg = 94;
    } else {
        actspk(verb);
        return;
    }
    rspeak(msg);
}

/*
	FILL
*/
void vfill(void) {
    int msg;
    int i;

    switch (object) {
        case BOTTLE: {
            if (liq() != 0) {
                msg = 105;
            } else if (liqloc(location) == 0) {
                msg = 106;
            } else {
                objectStatus[BOTTLE] = locationStatus[location] & WATOIL;
                i = liq();
                if (toting(BOTTLE)) {
                    objectLocation[i] = UINT8_MAX;
                }
                msg = (i == OIL ? 108 : 107);
            }
            break;
        }
        case VASE: {
            if (liqloc(location) == 0) {
                msg = 144;
                break;
            }
            if (!toting(VASE)) {
                msg = 29;
                break;
            }
            rspeak(145);
            vdrop();
            return;
        }
        default: {
            msg = 29;
        }
    }
    rspeak(msg);
}

/*
	FEED
*/
void vfeed(void) {
    int msg;

    switch (object) {
        case BIRD: {
            msg = 100;
            break;
        }
        case DWARF: {
            if (!here(FOOD)) {
                actspk(verb);
                return;
            }
            ++dwarfFlag;
            msg = 103;
            break;
        }
        case BEAR: {
            if (!here(FOOD)) {
                if (objectStatus[BEAR] == 0) {
                    msg = 102;
                } else if (objectStatus[BEAR] == 3) {
                    msg = 110;
                } else {
                    actspk(verb);
                    return;
                }
                break;
            }
            dstroy(FOOD);
            objectStatus[BEAR] = 1;
            secondObjectLocation[AXE] = 0;
            objectStatus[AXE] = 0;
            msg = 168;
            break;
        }
        case DRAGON: {
            msg = (objectStatus[DRAGON] != 0 ? 110 : 102);
            break;
        }
        case TROLL: {
            msg = 182;
            break;
        }
        case SNAKE: {
            if (closed || !here(BIRD)) {
                msg = 102;
                break;
            }
            msg = 101;
            dstroy(BIRD);
            objectStatus[BIRD] = 0;
            ++tally2;
            break;
        }
        default: {
            msg = 14;
        }
    }
    rspeak(msg);
}

/*
	READ etc.
*/
void vread(void) {
    int msg;

    msg = 0;
    if (dark()) {
        printf("I see no %s here.\n", probj(object));
        return;
    }
    switch (object) {
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
            if (!toting(OYSTER) || !closed) {break;}

            yes(192, 193, 54);
            return;
        }
        default: {
        }
    }
    if (msg) {
        rspeak(msg);
    } else {
        actspk(verb);
    }
}

/*
	BLAST etc.
*/
void vblast(void) {
    if (objectStatus[ROD2] < 0 || !closed) {
        actspk(verb);
    } else {
        bonus = 133;
        if (location == 115) { bonus = 134; }
        if (here(ROD2)) { bonus = 135; }
        rspeak(bonus);
        normend();
    }
}

/*
	BREAK etc.
*/
void vbreak(void) {
    int msg;

    if (object == MIRROR) {
        msg = 148;
        if (closed) {
            rspeak(197);
            dwarfend();
        }
    } else if (object == VASE && objectStatus[VASE] == 0) {
        msg = 198;
        if (toting(VASE)) { drop(VASE, location); }
        objectStatus[VASE] = 2;
        secondObjectLocation[VASE] = UINT8_MAX;
    } else {
        actspk(verb);
        return;
    }
    rspeak(msg);
}

/*
	WAKE etc.
*/
void vwake(void) {
    if (object != DWARF || !closed) {
        actspk(verb);
    } else {
        rspeak(199);
        dwarfend();
    }
}

/*
	Routine to speak default verb message
*/
void actspk(int verb) {
    char i;
    if (verb < 1 || verb > 31) { bug(39); }

    i = actmsg[verb];
    if (i) { rspeak(i); }
}

/*
	Routine to indicate no reasonable
	object for verb found.  Used mostly by
	intransitive verbs.
*/
void needobj(void) {
    int wtype, wval;

    analyze(word1, &wtype, &wval);
    printf("%s what?\n", wtype == 2 ? word1 : word2);
}
