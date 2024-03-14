
/*	program TURN.C						*\
\*	WARNING: "advent.c" allocates GLOBAL storage space by	*\
\*		including "advdef.h".				*\
\*		All other modules use "advdec.h".		*/

#include <stdio.h> /* drv = 1.1st file 2.def 3.A	*/
#include <stdlib.h>

#include "advent.h"
#include "advdec.h"


/*
	Routine to take 1 turn
*/
void turn(void) {
    int i;
    /*
        if closing, then he can't leave except via
        the main office.
    */
    if (newLocation < 9 && newLocation != 0 && closing) {
        rspeak(130);
        newLocation = location;
        if (!panic) {
            clock2 = 15;
        }
        panic = 1;
    }
    /*
        see if a dwarf has seen him and has come
        from where he wants to go.
    */
    if (newLocation != location && !forced(location) && (locationStatus[location] & NOPIRAT) == 0) {
        for (i = 1; i < (DWARFMAX - 1); ++i) {
            if (oldLocationOfDwarf[i] == newLocation && dwarfSeenFlag[i]) {
                newLocation = location;
                rspeak(2);
                break;
            }
        }
    }

    dwarves(); /* & special dwarf(pirate who steals)	*/

    /* added by BDS C conversion */
    if (location != newLocation) {
        ++turns;
        location = newLocation;
/*	causes occasional "move" with two describe & descitem	*/
/*	}	*/
/*	if (location != newLocation)	*/

        /* check for death */
        if (location == 0) {
            death();
            return;
        }

        /* check for forced move */
        if (forced(location)) {
            describe();
            domove();
            return;
        }

        /* check for wandering in dark */
        if (wzdark && dark() && pct(35)) {
            rspeak(23);
            oldLocation2 = location;
            death();
            return;
        }

        /* describe his situation */
        describe();
        if (!dark()) {
            ++visited[location];
            descitem();
        }
/*	causes occasional "move" with no describe & descitem	*/
    }

    if (closed) {
        if (objectStatus[OYSTER] < 0 && toting(OYSTER)) {
            pspeak(OYSTER, 1);
        }
        for (i = 1; i < MAXOBJ; ++i) {
            if (toting(i) && objectStatus[i] < 0) {
                objectStatus[i] = -1 - objectStatus[i];
            }
        }
    }

    wzdark = dark();

    if (knifeLocation > 0 && knifeLocation != location && knifeLocation <= MAXLOC) { knifeLocation = 0; }

    if (stimer()) { return; } /* as the grains of sand slip by	*/

    while (!english()) {} /* retrieve player instructions	*/

    if (debugFlag) { printf("location = %d, verb = %d, object = %d, motion = %d\n", location, verb, object, motion); }

    if (motion) { domove(); }
    else if (object) { doobj(); }
    else { itverb(); }
}

/*
	Routine to describe current location
*/
void describe(void) {
    if (toting(BEAR)) {
        rspeak(141);
    }
    if (dark()) {
        rspeak(16);
    } else if (visited[location]) {
        descsh(location);
    } else {
        desclg(location);
    }
    if (location == 33 && pct(25) && !closing) {
        rspeak(8);
    }
}

/*
	Routine to describe visible items
*/
void descitem(void) {
    int i, state;

    for (i = 1; i < MAXOBJ; ++i) {
        if (at(i)) {
            if (i == STEPS && toting(NUGGET)) {
                continue;
            }
            if (objectStatus[i] < 0) {
                if (closed) {
                    continue;
                }

                objectStatus[i] = 0;
                if (i == RUG || i == CHAIN) {
                    ++objectStatus[i];
                }
                --tally;
            }
            if (i == STEPS && location == secondObjectLocation[STEPS]) {
                state = 1;
            } else {
                state = objectStatus[i];
            }
            pspeak(i, state);
        }
    }
    if (tally == tally2 && tally != 0 && timeLimit > 35) {
        timeLimit = 35;
    }
}

/*
	Routine to handle motion requests
*/
void domove(void) {
    gettrav(location);
    switch (motion) {
        case NULLX:
            break;
        case BACK:
            goback();
            break;
        case LOOK:
            if (lookCount++ < 3) {
                rspeak(15);
            }
            wzdark = 0;
            visited[location] = 0;
            newLocation = location;
            location = 0;
            break;
        case CAVE:
            if (location < 8) {
                rspeak(57);
            } else {
                rspeak(58);
            }
            break;
        default:
            oldLocation2 = oldLocation;
            oldLocation = location;
            dotrav();
    }
}

/*
	Routine to handle request to return
	from whence we came!
*/
void goback(void) {
    int kk, k2, want, temp;
    struct trav strav[MAXTRAV];

    if (forced(oldLocation)) {
        want = oldLocation2;
    } else {
        want = oldLocation;
    }
    oldLocation2 = oldLocation;
    oldLocation = location;
    k2 = 0;
    if (want == location) {
        rspeak(91);
        return;
    }
    copytrv(travel, strav);
    for (kk = 0; travel[kk].tdest != -1; ++kk) {
        if (!travel[kk].tcond && travel[kk].tdest == want) {
            motion = travel[kk].tverb;
            dotrav();
            return;
        }
        if (!travel[kk].tcond) {
            k2 = kk;
            temp = travel[kk].tdest;
            gettrav(temp);
            if (forced(temp) && travel[0].tdest == want) {
                k2 = temp;
            }
            copytrv(strav, travel);
        }
    }
    if (k2) {
        motion = travel[k2].tverb;
        dotrav();
    } else {
        rspeak(140);
    }
}

/*
	Routine to copy a travel array
*/
void copytrv(struct trav * trav1, struct trav * trav2) {
    int i;

    for (i = 0; i < MAXTRAV; ++i) {
        trav2->tdest = trav1->tdest;
        trav2->tverb = trav1->tverb;
        trav2->tcond = trav1->tcond;
    }
}

/*
	Routine to figure out a new location
	given current location and a motion.
*/
void dotrav(void) {
    char mvflag, hitflag;
    int rdest, rverb, rcond, robject;
    int pctt, kk;

    newLocation = location;
    mvflag = hitflag = 0;
    pctt = rand() % 100;

    for (kk = 0; travel[kk].tdest >= 0 && !mvflag; ++kk) {
        rdest = travel[kk].tdest;
        rverb = travel[kk].tverb;
        rcond = travel[kk].tcond;
        robject = rcond % 100;

        if (debugFlag) {
            printf("rdest = %d, rverb = %d, rcond = %d, \
			robject = %d in dotrav\n",
                   rdest, rverb, rcond, robject);
        }
        if ((rverb != 1) && (rverb != motion) && !hitflag) {
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
                } else if (toting(robject)) {
                    ++mvflag;
                }
                break;
            case 2:
                if (toting(robject) || at(robject)) {
                    ++mvflag;
                }
                break;
            case 3:
            case 4:
            case 5:
            case 7:
                if (objectStatus[robject] != (rcond / 100) - 3) {
                    ++mvflag;
                }
                break;
            default:
                bug(37);
        }
    }
    if (!mvflag) {
        badmove();
    } else if (rdest > 500) {
        rspeak(rdest - 500);
    } else if (rdest > 300) {
        spcmove(rdest);
    } else {
        newLocation = rdest;
        if (debugFlag) {
            printf("newLocation in dotrav = %d\n", newLocation);
        }
    }
}

/*
	The player tried a poor move option.
*/
void badmove(void) {
    int msg;

    msg = 12;
    if (motion >= 43 && motion <= 50) {
        msg = 9;
    }
    if (motion == 29 || motion == 30) {
        msg = 9;
    }
    if (motion == 7 || motion == 36 || motion == 37) {
        msg = 10;
    }
    if (motion == 11 || motion == 19) {
        msg = 11;
    }
    if (verb == FIND || verb == INVENTORY) {
        msg = 59;
    }
    if (motion == 62 || motion == 65) {
        msg = 42;
    }
    if (motion == 17) {
        msg = 80;
    }
    rspeak(msg);
}

/*
	Routine to handle very special movement.
*/
void spcmove(int rdest) {
    switch (rdest - 300) {
        case 1: /* plover movement via alcove */
            if (!countItemsHeld || (countItemsHeld == 1 && toting(EMERALD))) {
                newLocation = (99 + 100) - location;
            } else {
                rspeak(117);
            }
            break;
        case 2: /* trying to remove plover, bad route */
            drop(EMERALD, location);
            break;
        case 3: /* troll bridge */
            if (objectStatus[TROLL] == 1) {
                pspeak(TROLL, 1);
                objectStatus[TROLL] = 0;
                move(TROLL2, 0);
                move((TROLL2 + MAXOBJ), 0);
                move(TROLL, 117);
                move((TROLL + MAXOBJ), 122);
                juggle(CHASM);
                newLocation = location;
            } else {
                newLocation = (location == 117 ? 122 : 117);
                if (objectStatus[TROLL] == 0) {
                    ++objectStatus[TROLL];
                }
                if (!toting(BEAR)) {
                    return;
                }
                rspeak(162);
                objectStatus[CHASM] = 1;
                objectStatus[TROLL] = 2;
                drop(BEAR, newLocation);
                secondObjectLocation[BEAR] = UINT8_MAX;
                objectStatus[BEAR] = 3;
                if (objectStatus[SPICES] < 0) {
                    ++tally2;
                }
                oldLocation2 = newLocation;
                death();
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
void dwarfend(void) {
    death();
    normend();
}

/*
	normal end of game
*/
void normend(void) {
    score();
    exit(-1);
}

/*
	scoring
*/
void score(void) {
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
        if (objectStatus[i] >= 0) {
            t += 2;
        }
        if (objectLocation[i] == 3 && objectStatus[i] == 0) {
            t += k - 2;
        }
    }
    printf("%-20s%d\n", "Treasures:", s = t);
    t = (MAXDIE - numberOfDeaths) * 10;
    if (t) {
        printf("%-20s%d\n", "Survival:", t);
    }
    s += t;
    if (!playerWantToQuitFlag) {
        s += 4;
    }
    t = dwarfFlag ? 25 : 0;
    if (t) {
        printf("%-20s%d\n", "Getting well in:", t);
    }
    s += t;
    t = closing ? 25 : 0;
    if (t) {
        printf("%-20s%d\n", "Masters section:", t);
    }
    s += t;
    if (closed) {
        if (bonus == 0) {
            t = 10;
        } else if (bonus == 135) {
            t = 25;
        } else if (bonus == 134) {
            t = 30;
        } else if (bonus == 133) {
            t = 45;
        }
        printf("%-20s%d\n", "Bonus:", t);
        s += t;
    }
    if (objectLocation[MAGAZINE] == 108) {
        s += 1;
    }
    s += 2;
    printf("%-20s%d\n", "Score:", s);
}

/*
	Routine to handle the passing on of one
	of the player's incarnations...
*/
void death(void) {
    char yea, i, j;

    if (!closing) {
        yea = yes(81 + numberOfDeaths * 2, 82 + numberOfDeaths * 2, 54);
        if (++numberOfDeaths >= MAXDIE || !yea) {
            normend();
        }
        objectLocation[WATER] = 0;
        objectLocation[OIL] = 0;
        if (toting(LAMP)) {
            objectStatus[LAMP] = 0;
        }
        for (j = 1; j < MAXOBJ; ++j) {
            i = MAXOBJ - j;
            if (toting(i)) {
                drop(i, i == LAMP ? 1 : oldLocation2);
            }
        }
        newLocation = 3;
        oldLocation = location;
        return;
    }
    /*
       closing -- no resurrection...
    */
    rspeak(131);
    ++numberOfDeaths;
    normend();
}

/*
	Routine to process an object.
*/
void doobj(void) {
    /*
       is object here?  if so, transitive
    */
    if (secondObjectLocation[object] == location || here(object)) {
        trobj();
        /*
            did he give grate as destination?
        */
    } else if (object == GRATE) {
        if (location == 1 || location == 4 || location == 7) {
            motion = DEPRESSION;
            domove();
        } else if (location > 9 && location < 15) {
            motion = ENTRANCE;
            domove();
        }
    }
        /*
            is it a dwarf he is after?
        */
    else if (dcheck() && dwarfFlag >= 2) {
        object = DWARF;
        trobj();
    }
        /*
           is he trying to get/use a liquid?
        */
    else if ((liq() == object && here(BOTTLE)) || liqloc(location) == object) {
        trobj();
    } else if (object == PLANT && at(PLANT2) && objectStatus[PLANT2] == 0) {
        object = PLANT2;
        trobj();
    }
        /*
           is he trying to grab a knife?
        */
    else if (object == KNIFE && knifeLocation == location) {
        rspeak(116);
        knifeLocation = MAXLOC+1;
    }
        /*
           is he trying to get at dynamite?
        */
    else if (object == ROD && here(ROD2)) {
        object = ROD2;
        trobj();
    } else {
        printf("I see no %s here.\n", probj(object));
    }
}

/*
	Routine to process an object being
	referred to.
*/
void trobj(void) {
    if (verb) {
        trverb();
    } else {
        printf("What do you want to do with the %s?\n", probj(object));
    }
}

/*
	Routine to print word corresponding to object
*/
char * probj(int object) {
    int wtype, wval;

    (void) object;
    analyze(word1, &wtype, &wval);

    return wtype == 1 ? word1 : word2;
}

/*
	dwarf stuff.
*/
void dwarves(void) {
    int i, j, k, try, attack, stick, dtotal;

    /*
        see if dwarves allowed here
    */
    if (newLocation == 0 || forced(newLocation) || locationStatus[newLocation] & NOPIRAT) {
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
        if (newLocation < 15 || pct(95)) {
            return;
        }
        ++dwarfFlag;
        for (i = 1; i < 3; ++i)
            if (pct(50)) {
                dwarfLocations[rand() % 5 + 1] = 0;
            }
        for (i = 1; i < (DWARFMAX - 1); ++i) {
            if (dwarfLocations[i] == newLocation) {
                dwarfLocations[i] = dwarfAltLocation;
            }
            oldLocationOfDwarf[i] = dwarfLocations[i];
        }
        rspeak(3);
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
        if ((dwarfSeenFlag[i] && newLocation >= 15) || dwarfLocations[i] == newLocation || oldLocationOfDwarf[i] == newLocation) {
            dwarfSeenFlag[i] = 1;
        } else {
            dwarfSeenFlag[i] = 0;
        }
        if (!dwarfSeenFlag[i]) {
            continue;
        }
        dwarfLocations[i] = newLocation;
        if (i == 6) {
            dopirate();
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
        printf("There are %d threatening little dwarves in the room with you!\n", dtotal);
    } else {
        rspeak(4);
    }
    if (attack == 0) {
        return;
    }
    if (dwarfFlag == 2) {
        ++dwarfFlag;
    }
    if (attack > 1) {
        printf("%d of them throw knives at you!!\n", attack);
        k = 6;
    } else {
        rspeak(5);
        k = 52;
    }
    if (stick <= 1) {
        rspeak(stick + k);
        if (stick == 0) {
            return;
        }
    } else {
        printf("%d of them get you !!!\n", stick);
    }
    oldLocation2 = newLocation;
    death();
}

/*
	pirate stuff
*/
void dopirate(void) {
    int j, k;

    if (newLocation == chestLocation || objectStatus[CHEST] >= 0) {
        return;
    }

    k = 0;
    for (j = 50; j <= MAXTRS; ++j)
        if (j != PYRAMID || (newLocation != objectLocation[PYRAMID] && newLocation != objectLocation[EMERALD])) {
            if (toting(j)) {
                goto stealit;
            }
            if (here(j)) {
                ++k;
            }
        }
    if (tally == tally2 + 1 && k == 0 && objectLocation[CHEST] == 0 && here(LAMP) && objectStatus[LAMP] == 1) {
        rspeak(186);
        move(CHEST, chestLocation);
        move(MESSAGE, chestLocation2);
        dwarfLocations[6] = chestLocation;
        oldLocationOfDwarf[6] = chestLocation;
        dwarfSeenFlag[6] = 0;
        return;
    }
    if (oldLocationOfDwarf[6] != dwarfLocations[6] && pct(20)) {
        rspeak(127);
        return;
    }
    return;

    stealit:

    rspeak(128);
    if (objectLocation[MESSAGE] == 0) {
        move(CHEST, chestLocation);
    }
    move(MESSAGE, chestLocation2);
    for (j = 50; j <= MAXTRS; ++j) {
        if (j == PYRAMID && (newLocation == objectLocation[PYRAMID] || newLocation == objectLocation[EMERALD])) {
            continue;
        }
        if (at(j) && secondObjectLocation[j] == 0) {
            carry(j, newLocation);
        }
        if (toting(j)) {
            drop(j, chestLocation);
        }
    }
    dwarfLocations[6] = chestLocation;
    oldLocationOfDwarf[6] = chestLocation;
    dwarfSeenFlag[6] = 0;
}

/*
	special time timeLimit stuff...
*/
int stimer(void) {
    int i;

    foobar = foobar > 0 ? -foobar : 0;
    if (tally == 0 && location >= 15 && location != 33) {
        --clock1;
    }
    if (clock1 == 0) {
        /*
            start closing the cave
        */
        objectStatus[GRATE] = 0;
        objectStatus[FISSURE] = 0;
        for (i = 1; i < DWARFMAX; ++i)
            dwarfSeenFlag[i] = 0;
        move(TROLL, 0);
        move((TROLL + MAXOBJ), 0);
        move(TROLL2, 117);
        move((TROLL2 + MAXOBJ), 122);
        juggle(CHASM);
        if (objectStatus[BEAR] != 3) {
            dstroy(BEAR);
        }
        objectStatus[CHAIN] = 0;
        secondObjectLocation[CHAIN] = 0;
        objectStatus[AXE] = 0;
        secondObjectLocation[AXE] = 0;
        rspeak(129);
        clock1 = -1;
        closing = 1;
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
        objectStatus[BOTTLE] = put(BOTTLE, 115, 1);
        objectStatus[PLANT] = put(PLANT, 115, 0);
        objectStatus[OYSTER] = put(OYSTER, 115, 0);
        objectStatus[LAMP] = put(LAMP, 115, 0);
        objectStatus[ROD] = put(ROD, 115, 0);
        objectStatus[DWARF] = put(DWARF, 115, 0);
        location = 115;
        oldLocation = 115;
        newLocation = 115;
        put(GRATE, 116, 0);
        objectStatus[SNAKE] = put(SNAKE, 116, 1);
        objectStatus[BIRD] = put(BIRD, 116, 1);
        objectStatus[CAGE] = put(CAGE, 116, 0);
        objectStatus[ROD2] = put(ROD2, 116, 0);
        objectStatus[PILLOW] = put(PILLOW, 116, 0);
        objectStatus[MIRROR] = put(MIRROR, 115, 0);
        secondObjectLocation[MIRROR] = 116;
        for (i = 1; i < MAXOBJ; ++i) {
            if (toting(i)) {
                dstroy(i);
            }
        }
        rspeak(132);
        closed = 1;
        return 1;
    }
    if (objectStatus[LAMP] == 1) {
        --timeLimit;
    }
    if (timeLimit <= 30 && here(BATTERIES) && objectStatus[BATTERIES] == 0 && here(LAMP)) {
        rspeak(188);
        objectStatus[BATTERIES] = 1;
        if (toting(BATTERIES)) {
            drop(BATTERIES, location);
        }
        timeLimit += 2500;
        lampWarningFlag = 0;
        return 0;
    }
    if (timeLimit == 0) {
        --timeLimit;
        objectStatus[LAMP] = 0;
        if (here(LAMP)) {
            rspeak(184);
        }
        return 0;
    }
    if (timeLimit < 0 && location <= 8) {
        rspeak(185);
        playerWantToQuitFlag = 1;
        normend();
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
        if (objectStatus[BATTERIES] == 1) {
            i = 189;
        }
        rspeak(i);
        return 0;
    }
    return 0;
}
