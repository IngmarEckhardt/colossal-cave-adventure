
/*	program TURN.C						*\
\*	WARNING: "advent.c" allocates GLOBAL storage space by	*\
\*		including "advdef.h".				*\
\*		All other modules use "advdec.h".		*/

#include <stdio.h> /* drv = 1.1st file 2.def 3.A	*/
#include <stdlib.h>
#include <avr/pgmspace.h>

#include "advent.h"
#include "advdec.h"

static char * getString(int n);


/*
	Routine to take 1 turn
*/
void turn(void) {
    int i;
    /*
        if caveIsClosing, then he can't leave except via
        the main office.
    */
    if (newLocation < 9 && newLocation != 0 && caveIsClosing) {
        speakReaction(130);
        newLocation = actualLocation;
        if (!panic) {
            clock2 = 15;
        }
        panic = 1;
    }
    /*
        see if a dwarf has seen him and has come
        from where he wants to go.
    */
    if (newLocation != actualLocation && !isForcingAMove(actualLocation) &&
        (locationStatus[actualLocation] & NOPIRAT) == 0) {
        for (i = 1; i < (DWARFMAX - 1); ++i) {
            if (oldLocationOfDwarf[i] == newLocation && dwarfSawThePlayer[i]) {
                newLocation = actualLocation;
                speakReaction(2);
                break;
            }
        }
    }

    processDwarves(); /* & special dwarf(pirate who steals)	*/

    if (actualLocation != newLocation) {
        turns++;
        actualLocation = newLocation;

        /* check for death */
        if (actualLocation == 0) {
            processPlayerDeath();
            return;
        }

        /* check for isForcingAMove move */
        if (isForcingAMove(actualLocation)) {
            describeLocation();
            doMove();
            return;
        }

        /* check for wandering in dark */
        if (locationIsDark && dark() && isRandomlyTrue(35)) {
            speakReaction(23);
            oldLocation2 = actualLocation;
            processPlayerDeath();
            return;
        }

        /* describe his situation */
        describeLocation();
        if (!dark()) {
            ++amountOfVisits[actualLocation];
            describeItem();
        }
    }

    if (caveIsClosed) {
        if (stateOfObject[OYSTER] < 0 && isInInventory(OYSTER)) {
            printItemMessage(OYSTER, 1);
        }
        for (i = 1; i < MAXOBJ; ++i) {
            if (isInInventory(i) && stateOfObject[i] < 0) {
                stateOfObject[i] = -1 - stateOfObject[i];
            }
        }
    }

    locationIsDark = dark();

    if (knifeLocation > 0 && knifeLocation != actualLocation && knifeLocation <= MAXLOC) { knifeLocation = 0; }

    if (processTimeLimits()) { return; } /* as the grains of sand slip by	*/

    while (!parseSimpleEnglish()) {} /* retrieve player instructions	*/

    if (debugFlag) {
        printf("actualLocation = %d, actVerb = %d, actObject = %d, actotion = %d\n", actualLocation, actualVerb,
               actualObject,
               actualMotion);
    }

    if (actualMotion) { doMove(); }
    else if (actualObject) { processActualObject(); }
    else { intransitiveVerb(); }
}

/*
	Routine to describe current location
*/
void describeLocation(void) {
    if (isInInventory(BEAR)) {
        speakReaction(141);
    }
    if (dark()) {
        speakReaction(16);
    } else if (amountOfVisits[actualLocation]) {
        describeShortLocation(actualLocation);
    } else {
        describeLongLocation(actualLocation);
    }
    if (actualLocation == 33 && isRandomlyTrue(25) && !caveIsClosing) {
        speakReaction(8);
    }
}

/*
	Routine to describe visible items
*/
void describeItem(void) {
    int i, state;

    for (i = 1; i < MAXOBJ; i++) {
        if (isOnEitherSideOfTwoSidedObject(i)) {
            if (i == STEPS && isInInventory(NUGGET)) {
                continue;
            }
            if (stateOfObject[i] < 0) {
                if (caveIsClosed) {
                    continue;
                }

                stateOfObject[i] = 0;
                if (i == RUG || i == CHAIN) {
                    ++stateOfObject[i];
                }
                tally--;
            }
            if (i == STEPS && actualLocation == secondObjectLocation[STEPS]) {
                state = 1;
            } else {
                state = stateOfObject[i];
            }
            printItemMessage(i, state);
        }
    }
    if (tally == tally2 && tally != 0 && timeLimit > 35) {
        timeLimit = 35;
    }
}

/*
	Routine to handle motion requests
*/
void doMove(void) {
    getRoutingInfos(actualLocation);
    switch (actualMotion) {
        case NULLX: {
            break;
        }
        case BACK: {
            processReturnRequest();
            break;
        }
        case LOOK: {
            if (lookCount++ < 3) {
                speakReaction(15);
            }
            locationIsDark = 0;
            amountOfVisits[actualLocation] = 0;
            newLocation = actualLocation;
            actualLocation = 0;
            break;
        }
        case CAVE: {
            if (actualLocation < 8) {
                speakReaction(57);
            } else {
                speakReaction(58);
            }
            break;
        }
        default: {
            oldLocation2 = oldLocation;
            oldLocation = actualLocation;
            processTravel();
        }
    }
}

/*
	Routine to handle request to return
	from whence we came!
*/
void processReturnRequest(void) {
    int kk, k2, want, temp;
    TravelInfo strav[MAXTRAV];

    if (isForcingAMove(oldLocation)) {
        want = oldLocation2;
    } else {
        want = oldLocation;
    }
    oldLocation2 = oldLocation;
    oldLocation = actualLocation;
    k2 = 0;
    if (want == actualLocation) {
        speakReaction(91);
        return;
    }
    copyTravelInfo(locationRoutingInfos, strav);

    for (kk = 0; locationRoutingInfos[kk].destination != -1; ++kk) {
        if (!locationRoutingInfos[kk].condition && locationRoutingInfos[kk].destination == want) {
            actualMotion = locationRoutingInfos[kk].verbForDest;
            processTravel();
            return;
        }
        if (!locationRoutingInfos[kk].condition) {
            k2 = kk;
            temp = locationRoutingInfos[kk].destination;
            getRoutingInfos(temp);
            if (isForcingAMove(temp) && locationRoutingInfos[0].destination == want) {
                k2 = temp;
            }
            copyTravelInfo(strav, locationRoutingInfos);
        }
    }
    if (k2) {
        actualMotion = locationRoutingInfos[k2].verbForDest;
        processTravel();
    } else {
        speakReaction(140);
    }
}

/*
	Routine to copy a TravelInfo array
*/
void copyTravelInfo(TravelInfo * trav1, TravelInfo * trav2) {
    int i;

    for (i = 0; i < MAXTRAV; ++i) {
        trav2->destination = trav1->destination;
        trav2->verbForDest = trav1->verbForDest;
        trav2->condition = trav1->condition;
    }
}

/*
	Routine to figure out a new location
	given current actualLocation and a motion.
*/
void processTravel(void) {
    char mvflag, hitflag;
    int rdest, rverb, rcond, robject;
    int pctt, kk;

    newLocation = actualLocation;
    mvflag = hitflag = 0;
    pctt = rand() % 100;

    for (kk = 0; locationRoutingInfos[kk].destination >= 0 && !mvflag; ++kk) {
        rdest = locationRoutingInfos[kk].destination;
        rverb = locationRoutingInfos[kk].verbForDest;
        rcond = locationRoutingInfos[kk].condition;
        robject = rcond % 100;

        if (debugFlag) {
            printf("rdest = %d, rverb = %d, rcond = %d, \
			robject = %d in processTravel\n",
                   rdest, rverb, rcond, robject);
        }
        if ((rverb != 1) && (rverb != actualMotion) && !hitflag) {
            continue;
        }
        ++hitflag;
        switch (rcond / 100) {
            case 0:
                if ((rcond == 0) || (pctt < rcond)) {
                    ++mvflag;
                }
                if (rcond && debugFlag) {
                    printf("%% move %d %d\n", pctt, mvflag);
                }
                break;
            case 1:
                if (robject == 0) {
                    ++mvflag;
                } else if (isInInventory(robject)) {
                    ++mvflag;
                }
                break;
            case 2:
                if (isInInventory(robject) || isOnEitherSideOfTwoSidedObject(robject)) {
                    ++mvflag;
                }
                break;
            case 3:
            case 4:
            case 5:
            case 7:
                if (stateOfObject[robject] != (rcond / 100) - 3) {
                    ++mvflag;
                }
                break;
            default:
                bug(37);
        }
    }
    if (!mvflag) {
        reactToBadMove();
    } else if (rdest > 500) {
        speakReaction(rdest - 500);
    } else if (rdest > 300) {
        processSpecialMovements(rdest);
    } else {
        newLocation = rdest;
        if (debugFlag) {
            printf("newLocation in processTravel = %d\n", newLocation);
        }
    }
}

/*
	The player tried a poor move option.
*/
void reactToBadMove(void) {
    int msg;

    msg = 12;
    if (actualMotion >= 43 && actualMotion <= 50) {
        msg = 9;
    }
    if (actualMotion == 29 || actualMotion == 30) {
        msg = 9;
    }
    if (actualMotion == 7 || actualMotion == 36 || actualMotion == 37) {
        msg = 10;
    }
    if (actualMotion == 11 || actualMotion == 19) {
        msg = 11;
    }
    if (actualVerb == FIND || actualVerb == INVENTORY) {
        msg = 59;
    }
    if (actualMotion == 62 || actualMotion == 65) {
        msg = 42;
    }
    if (actualMotion == 17) {
        msg = 80;
    }
    speakReaction(msg);
}

/*
	Routine to handle very special movement.
*/
void processSpecialMovements(int rdest) {
    switch (rdest - 300) {
        case 1: /* plover movement via alcove */
            if (!countItemsHeld || (countItemsHeld == 1 && isInInventory(EMERALD))) {
                newLocation = (99 + 100) - actualLocation;
            } else {
                speakReaction(117);
            }
            break;
        case 2: /* trying to remove plover, bad route */
            drop(EMERALD, actualLocation);
            break;
        case 3: /* troll bridge */
            if (stateOfObject[TROLL] == 1) {
                printItemMessage(TROLL, 1);
                stateOfObject[TROLL] = 0;
                move(TROLL2, 0);
                move((TROLL2 + MAXOBJ), 0);
                move(TROLL, 117);
                move((TROLL + MAXOBJ), 122);
                juggle(CHASM);
                newLocation = actualLocation;
            } else {
                newLocation = (actualLocation == 117 ? 122 : 117);
                if (stateOfObject[TROLL] == 0) {
                    ++stateOfObject[TROLL];
                }
                if (!isInInventory(BEAR)) {
                    return;
                }
                speakReaction(162);
                stateOfObject[CHASM] = 1;
                stateOfObject[TROLL] = 2;
                drop(BEAR, newLocation);
                secondObjectLocation[BEAR] = UINT8_MAX;
                stateOfObject[BEAR] = 3;
                if (stateOfObject[SPICES] < 0) {
                    ++tally2;
                }
                oldLocation2 = newLocation;
                processPlayerDeath();
            }
            break;
        default:
            bug(38);
    }
}

/*
	Routine to handle player's demise via
	waking up the dwarves...
*/
void dwarfEnd(void) {
    processPlayerDeath();
    normalEnd();
}

/*
	normal end of game
*/
void normalEnd(void) {
    calcScore();
//    exit(-1);
}


/*
	scoring
*/
void calcScore(void) {
    int t, i, k, s;
    s = t = k = 0;
    for (i = 50; i <= MAXTRS; ++i) {
        if (i == CHEST) {
            k = 14;
        } else if (i > CHEST) {
            k = 16;
        } else {
            k = 12;
        }
        if (stateOfObject[i] >= 0) {
            t += 2;
        }
        if (objectLocation[i] == 3 && stateOfObject[i] == 0) {
            t += k - 2;
        }
    }
    char * string = getString(0);
    printf("%-20s%d\n", string, s = t);
    free(string);
    t = (MAXDIE - numberOfDeaths) * 10;
    if (t) {
        string = getString(1);
        printf("%-20s%d\n", string, t);
        free(string);
    }
    s += t;
    if (!playerWantToQuitFlag) {
        s += 4;
    }
    t = dwarfFlag ? 25 : 0;
    if (t) {
        string = getString(2);
        printf("%-20s%d\n", string, t);
        free(string);
    }
    s += t;
    t = caveIsClosing ? 25 : 0;
    if (t) {
        string = getString(3);
        printf("%-20s%d\n", string, t);
        free(string);
    }
    s += t;
    if (caveIsClosed) {
        if (bonus == 0) {
            t = 10;
        } else if (bonus == 135) {
            t = 25;
        } else if (bonus == 134) {
            t = 30;
        } else if (bonus == 133) {
            t = 45;
        }
        string = getString(4);
        printf("%-20s%d\n", string, t);
        free(string);
        s += t;
    }
    if (objectLocation[MAGAZINE] == 108) {
        s += 1;
    }
    s += 2;
    string = getString(5);
    printf("%-20s%d\n", string, s);
    free(string);
}

/*
	Routine to handle the passing on of one
	of the player's incarnations...
*/
void processPlayerDeath(void) {
    char yea, i, j;

    if (!caveIsClosing) {
        yea = yesOrNoQuestion(81 + numberOfDeaths * 2, 82 + numberOfDeaths * 2, 54);
        if (++numberOfDeaths >= MAXDIE || !yea) {
            normalEnd();
        }
        objectLocation[WATER] = 0;
        objectLocation[OIL] = 0;
        if (isInInventory(LAMP)) {
            stateOfObject[LAMP] = 0;
        }
        for (j = 1; j < MAXOBJ; ++j) {
            i = MAXOBJ - j;
            if (isInInventory(i)) {
                drop(i, i == LAMP ? 1 : oldLocation2);
            }
        }
        newLocation = 3;
        oldLocation = actualLocation;
        return;
    }
    /*
       caveIsClosing -- no resurrection...
    */
    speakReaction(131);
    ++numberOfDeaths;
    normalEnd();
}





/*
	Routine to process an object.
*/
void processActualObject(void) {
    /*
       is object here?  if so, transitive
    */
    if (secondObjectLocation[actualObject] == actualLocation || here(actualObject)) {
        processTransitionOfReferredObject();
        /*
            did he give grate as destination?
        */
    } else if (actualObject == GRATE) {
        if (actualLocation == 1 || actualLocation == 4 || actualLocation == 7) {
            actualMotion = DEPRESSION;
            doMove();
        } else if (actualLocation > 9 && actualLocation < 15) {
            actualMotion = ENTRANCE;
            doMove();
        }
    }
        /*
            is it a dwarf he is after?
        */
    else if (dcheck() && dwarfFlag >= 2) {
        actualObject = DWARF;
        processTransitionOfReferredObject();
    }
        /*
           is he trying to get/use a liquid?
        */
    else if ((liq() == actualObject && here(BOTTLE)) || liqloc(actualLocation) == actualObject) {
        processTransitionOfReferredObject();
    } else if (actualObject == PLANT && isOnEitherSideOfTwoSidedObject(PLANT2) && stateOfObject[PLANT2] == 0) {
        actualObject = PLANT2;
        processTransitionOfReferredObject();
    }
        /*
           is he trying to grab a knife?
        */
    else if (actualObject == KNIFE && knifeLocation == actualLocation) {
        speakReaction(116);
        knifeLocation = MAXLOC + 1;
    }
        /*
           is he trying to get isOnEitherSideOfTwoSidedObject dynamite?
        */
    else if (actualObject == ROD && here(ROD2)) {
        actualObject = ROD2;
        processTransitionOfReferredObject();
    } else {
        char * string1 = getString(6);
        char * string2 = getString(7);
        printf("%s%s%s", string1, searchObjStringInBothWords(actualObject), string2);
        free(string1);
        free(string2);
    }
}

/*
	Routine to process an object being
	referred to.
*/
void processTransitionOfReferredObject(void) {
    if (actualVerb) {
        transitiveVerb();
    } else {
        char * string = getString(10);
        printf("%s%s?\n",string, searchObjStringInBothWords(actualObject));
        free(string);
    }
}

/*
	Routine to print word corresponding to object
*/
char * searchObjStringInBothWords(int object) {
    int wtype, wval;

    (void) object;
    computeTypeAndValue(word1, &wtype, &wval);

    return wtype == 1 ? word1 : word2;
}

/*
	dwarf stuff.
*/
void processDwarves(void) {
    int i, j, k, try, attack, stick, dtotal;

    /*
        see if dwarves allowed here
    */
    if (newLocation == 0 || isForcingAMove(newLocation) || locationStatus[newLocation] & NOPIRAT) {
        return;
    }
    /*
        see if dwarves are active.
    */
    if (!dwarfFlag) {
        if (newLocation > 15) {
            ++dwarfFlag;
        }
        return;
    }
    /*
        if first close encounter (of 3rd kind)
        kill 0, 1 or 2
    */
    if (dwarfFlag == 1) {
        if (newLocation < 15 || isRandomlyTrue(95)) {
            return;
        }
        ++dwarfFlag;
        for (i = 0; i < 2; i++) {
            if (isRandomlyTrue(50)) { dwarfLocations[rand() % 5 + 1] = 0; }
        }
        for (i = 1; i < (DWARFMAX - 1); i++) {
            if (dwarfLocations[i] == newLocation) {
                dwarfLocations[i] = dwarfAltLocation;
            }
            oldLocationOfDwarf[i] = dwarfLocations[i];
        }
        speakReaction(3);
        drop(AXE, newLocation);
        return;
    }
    dtotal = attack = stick = 0;
    for (i = 1; i < DWARFMAX; ++i) {
        if (dwarfLocations[i] == 0) {
            continue;
        }
        /*
            move a dwarf at random.  we don't
            have a matrix around to do it
            as in the original version...
        */
        for (try = 1; try < 20; ++try) {
            j = rand() % 106 + 15; /* allowed area */
            if (j != oldLocationOfDwarf[i] && j != dwarfLocations[i] &&
                !(i == (DWARFMAX - 1) && (locationStatus[j] & NOPIRAT) == NOPIRAT)) {
                break;
            }
        }
        if (j == 0) {
            j = oldLocationOfDwarf[i];
        }

        oldLocationOfDwarf[i] = dwarfLocations[i];
        dwarfLocations[i] = j;

        if ((dwarfSawThePlayer[i] && newLocation >= 15) || dwarfLocations[i] == newLocation ||
            oldLocationOfDwarf[i] == newLocation) {
            dwarfSawThePlayer[i] = 1;
        } else {
            dwarfSawThePlayer[i] = 0;
        }
        if (!dwarfSawThePlayer[i]) {
            continue;
        }
        dwarfLocations[i] = newLocation;
        if (i == 6) {
            processPirating();
        } else {
            ++dtotal;
            if (oldLocationOfDwarf[i] == dwarfLocations[i]) {
                ++attack;
                if (knifeLocation <= MAXLOC) {
                    knifeLocation = newLocation;
                }
                if (rand() % 1000 < 95 * (dwarfFlag - 2)) {
                    ++stick;
                }
            }
        }
    }
    if (dtotal == 0) {
        return;
    }
    if (dtotal > 1) {
        char * string1 = getString(9);
        char * string2 = getString(11);
        printf("%s%d%s",string1, dtotal, string2);
        free(string1);
        free(string2);
    } else {
        speakReaction(4);
    }
    if (attack == 0) {
        return;
    }
    if (dwarfFlag == 2) {
        ++dwarfFlag;
    }
    if (attack > 1) {
        char * string = getString(12);
        printf("%d%s", attack, string);
        free(string);
        k = 6;
    } else {
        speakReaction(5);
        k = 52;
    }
    if (stick <= 1) {
        speakReaction(stick + k);
        if (stick == 0) {
            return;
        }
    } else {
        char * string = getString(8);
        printf("%d%s", stick, string);
        free(string);
    }
    oldLocation2 = newLocation;
    processPlayerDeath();
}

void stealit(void) {
    speakReaction(128);
    if (objectLocation[MESSAGE] == 0) {
        move(CHEST, chestLocation);
    }
    move(MESSAGE, chestLocation2);
    for (int j = 50; j <= MAXTRS; j++) {
        if (j == PYRAMID && (newLocation == objectLocation[PYRAMID] || newLocation == objectLocation[EMERALD])) {
            continue;
        }
        if (isOnEitherSideOfTwoSidedObject(j) && secondObjectLocation[j] == 0) {
            carry(j, newLocation);
        }
        if (isInInventory(j)) {
            drop(j, chestLocation);
        }
    }
    dwarfLocations[6] = chestLocation;
    oldLocationOfDwarf[6] = chestLocation;
    dwarfSawThePlayer[6] = 0;
}

/*
	pirate stuff
*/
void processPirating(void) {
    int j, k;

    if (newLocation == chestLocation || stateOfObject[CHEST] >= 0) { return; }

    k = 0;
    for (j = 50; j <= MAXTRS; ++j)
        if (j != PYRAMID || (newLocation != objectLocation[PYRAMID] && newLocation != objectLocation[EMERALD])) {
            if (isInInventory(j)) {
//                goto stealit;
                stealit();
                return;
            }
            if (here(j)) {
                ++k;
            }
        }
    if (tally == tally2 + 1 && k == 0 && objectLocation[CHEST] == 0 && here(LAMP) && stateOfObject[LAMP] == 1) {
        speakReaction(186);
        move(CHEST, chestLocation);
        move(MESSAGE, chestLocation2);
        dwarfLocations[6] = chestLocation;
        oldLocationOfDwarf[6] = chestLocation;
        dwarfSawThePlayer[6] = 0;
        return;
    }
    if (oldLocationOfDwarf[6] != dwarfLocations[6] && isRandomlyTrue(20)) {
        speakReaction(127);
        return;
    }
    return;

//    stealit:

//    speakReaction(128);
//    if (objectLocation[MESSAGE] == 0) {
//        move(CHEST, chestLocation);
//    }
//    move(MESSAGE, chestLocation2);
//    for (j = 50; j <= MAXTRS; ++j) {
//        if (j == PYRAMID && (newLocation == objectLocation[PYRAMID] || newLocation == objectLocation[EMERALD])) {
//            continue;
//        }
//        if (isOnEitherSideOfTwoSidedObject(j) && secondObjectLocation[j] == 0) {
//            carry(j, newLocation);
//        }
//        if (isInInventory(j)) {
//            drop(j, chestLocation);
//        }
//    }
//    dwarfLocations[6] = chestLocation;
//    oldLocationOfDwarf[6] = chestLocation;
//    dwarfSawThePlayer[6] = 0;
}

/*
	special time timeLimit stuff...
*/
int processTimeLimits(void) {
    int i;

    foobar = foobar > 0 ? -foobar : 0;
    if (tally == 0 && actualLocation >= 15 && actualLocation != 33) {
        --clock1;
    }
    if (clock1 == 0) {
        /*
            start caveIsClosing the cave
        */
        stateOfObject[GRATE] = 0;
        stateOfObject[FISSURE] = 0;
        for (i = 1; i < DWARFMAX; ++i)
            dwarfSawThePlayer[i] = 0;
        move(TROLL, 0);
        move((TROLL + MAXOBJ), 0);
        move(TROLL2, 117);
        move((TROLL2 + MAXOBJ), 122);
        juggle(CHASM);
        if (stateOfObject[BEAR] != 3) {
            destroy(BEAR);
        }
        stateOfObject[CHAIN] = 0;
        secondObjectLocation[CHAIN] = 0;
        stateOfObject[AXE] = 0;
        secondObjectLocation[AXE] = 0;
        speakReaction(129);
        clock1 = -1;
        caveIsClosing = 1;
        return 0;
    }
    if (clock1 < 0) {
        --clock2;
    }
    if (clock2 == 0) {
        /*
            set up storage room...
            and close the cave...
        */
        stateOfObject[BOTTLE] = put(BOTTLE, 115, 1);
        stateOfObject[PLANT] = put(PLANT, 115, 0);
        stateOfObject[OYSTER] = put(OYSTER, 115, 0);
        stateOfObject[LAMP] = put(LAMP, 115, 0);
        stateOfObject[ROD] = put(ROD, 115, 0);
        stateOfObject[DWARF] = put(DWARF, 115, 0);
        actualLocation = 115;
        oldLocation = 115;
        newLocation = 115;
        put(GRATE, 116, 0);
        stateOfObject[SNAKE] = put(SNAKE, 116, 1);
        stateOfObject[BIRD] = put(BIRD, 116, 1);
        stateOfObject[CAGE] = put(CAGE, 116, 0);
        stateOfObject[ROD2] = put(ROD2, 116, 0);
        stateOfObject[PILLOW] = put(PILLOW, 116, 0);
        stateOfObject[MIRROR] = put(MIRROR, 115, 0);
        secondObjectLocation[MIRROR] = 116;
        for (i = 1; i < MAXOBJ; ++i) {
            if (isInInventory(i)) {
                destroy(i);
            }
        }
        speakReaction(132);
        caveIsClosed = 1;
        return 1;
    }
    if (stateOfObject[LAMP] == 1) {
        --timeLimit;
    }
    if (timeLimit <= 30 && here(BATTERIES) && stateOfObject[BATTERIES] == 0 && here(LAMP)) {
        speakReaction(188);
        stateOfObject[BATTERIES] = 1;
        if (isInInventory(BATTERIES)) {
            drop(BATTERIES, actualLocation);
        }
        timeLimit += 2500;
        lampWarningFlag = 0;
        return 0;
    }
    if (timeLimit == 0) {
        --timeLimit;
        stateOfObject[LAMP] = 0;
        if (here(LAMP)) {
            speakReaction(184);
        }
        return 0;
    }
    if (timeLimit < 0 && actualLocation <= 8) {
        speakReaction(185);
        playerWantToQuitFlag = 1;
        normalEnd();
    }
    if (timeLimit <= 30) {
        if (lampWarningFlag || !here(LAMP)) {
            return 0;
        }
        lampWarningFlag = 1;
        i = 187;
        if (objectLocation[BATTERIES] == 0) {
            i = 183;
        }
        if (stateOfObject[BATTERIES] == 1) {
            i = 189;
        }
        speakReaction(i);
        return 0;
    }
    return 0;
}
#define TURN_STRING_LENGTH 20
const __attribute__((__progmem__)) char turnStrings[10][TURN_STRING_LENGTH] = {
        "Treasures:", "Survival:", "Getting well in:", "Masters section:", "Bonus:", "Score:", "I see no ", " here.\n",
        "of them get you !!!\n","There are "
};
#define LONG_TURN_STRING_LENGTH 51
const __attribute__((__progmem__)) char longTurnStrings[3][LONG_TURN_STRING_LENGTH] = {"What do you want to do with the ", " threatening little dwarves in the room with you!\n",
                                                                                       " of them throw knives at you!!\n"
};


#define PROCESS_SHORT_STRING(num) {\
    stringToReturn = malloc(TURN_STRING_LENGTH);\
    if (stringToReturn == NULL) { bug(4); }\
    flashHelper->loadFarStringFromFlash(stringToReturn, pgm_get_far_address(turnStrings[num]));\
    break;\
}
#define PROCESS_LONG_STRING(num) {\
    stringToReturn = malloc(LONG_TURN_STRING_LENGTH);\
    if (stringToReturn == NULL) { bug(4); }\
    flashHelper->loadFarStringFromFlash(stringToReturn, pgm_get_far_address(longTurnStrings[num]));\
    break;\
}
static char * getString(int n) {
    char * stringToReturn = NULL;
    switch (n) {
        case 0: PROCESS_SHORT_STRING(0)
        case 1: PROCESS_SHORT_STRING(1)
        case 2: PROCESS_SHORT_STRING(2)
        case 3: PROCESS_SHORT_STRING(3)
        case 4: PROCESS_SHORT_STRING(4)
        case 5: PROCESS_SHORT_STRING(5)
        case 6: PROCESS_SHORT_STRING(6)
        case 7: PROCESS_SHORT_STRING(7)
        case 8: PROCESS_SHORT_STRING(8)
        case 9: PROCESS_SHORT_STRING(9)

        case 10: PROCESS_LONG_STRING(0)
        case 11: PROCESS_LONG_STRING(1)
        case 12: PROCESS_LONG_STRING(2)
        default: {}
    }
    return stringToReturn;
}