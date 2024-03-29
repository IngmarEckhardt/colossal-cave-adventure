#include "long_locations.h"
#include <stdlib.h>
#include <avr/pgmspace.h>
#include "advent.h"
#include "advdec.h"


typedef struct {
    uint8_t numbers[LONG_LOCATION_1_INDEX_ARRAY_SIZE];
    char stringInProgramMem[LONG_LOCATION_1_STRING_LENGTH];
} LONG_LOCATION_1;

const __attribute__((__progmem__)) LONG_LOCATION_1 longLocations_1[AMOUNT_LONG_LOCATION_1_STRINGS] = {
        {{3,},"You are inside a building, a well house for a large spring.\n"},
        {{5,},"You are in open forest, with a deep valley to one side.\n"},
        {{6,},"You are in open forest near both a valley and a road.\n"},
        {{12,},"You are in an awkward sloping east/west canyon.\n"},
        {{16,},"The crack is far too small for you to follow.\n"},
        {{20,},"You are at the bottom of the pit with a broken neck.\n"},
        {{21,},"You didn't make it.\n"},
        {{22,},"The dome is unclimbable.\n"},
        {{26,},"You clamber up the plant and scurry through the hole at the\ntop.\n"},
        {{27,},"You are on the west side of the fissure in the hall of mists.\n"},
        {{29,},"You are in the south side chamber.\n"},
        {{31,},">$<\n"},
        {{32,},"You can't get by the snake.\n"},
        {{34,},"You are in a jumble of rock, with cracks everywhere.\n"},
        {{42,43,44,45,49,50,51,52,53,55,80,83,84,87,},"You are in a maze of twisty little passages, all alike.\n"},
        {{46,47,48,54,56,58,63,},"Dead end\n"},
        {{62,},"You are at a crossover of a high N/S passage and a low\nE/W one.\n"},
        {{69,},"You are in a secret N/S canyon above a large room.\n"},
        {{70,},"You are in a secret N/S canyon above a sizable passage.\n"},
        {{72,},"You are in a large low room.  Crawls lead north, se, and sw.\n"},
        {{73,},"Dead end crawl.\n"},
        {{75,},"You are at a wide place in a very tight N/S canyon.\n"},
        {{76,},"The canyon here becomes too tight to go further south.\n"},
        {{78,},"The canyon runs into a mass of boulders -- dead end.\n"},
        {{81,82,85,86,114,140,},"Dead end.\n"},
        {{89,},"There is nothing here to climb.  Use \"up\" or \"out\" to leave\nthe pit.\n"},
        {{90,},"You have climbed up the plant and out of the pit.\n"},
        {{93,},"The passage here is blocked by a recent cave-in.\n"},
        {{94,},"You are at one end of an immense north/south passage.\n"},
        {{101,},"You're in the dark-room.  A corridor leading south is the\nonly exit.\n"},
        {{104,},"You are in a long sloping corridor with ragged sharp walls.\n"},
        {{105,},"You are in a cul-de-sac about eight feet across.\n"},
        {{107,},"You are in a maze of twisty little passages, all different.\n"},
        {{108,},"You are at Witt's end.  Passages lead off in ALL directions.\n"},
        {{112,},"You are in a little maze of twisting passages, all different.\n"},
        {{119,120,121,},"You are in a secret canyon which exits to the north and east.\n"},
        {{131,},"You are in a maze of twisting little passages, all different.\n"},
        {{132,},"You are in a little maze of twisty passages, all different.\n"},
        {{133,},"You are in a twisting maze of little passages, all different.\n"},
        {{134,},"You are in a twisting little maze of passages, all different.\n"},
        {{135,},"You are in a twisty little maze of passages, all different.\n"},
        {{136,},"You are in a twisty maze of little passages, all different.\n"},
        {{137,},"You are in a little twisty maze of passages, all different.\n"},
        {{138,},"You are in a maze of little twisting passages, all different.\n"},
        {{139,},"You are in a maze of little twisty passages, all different.\n"},
};

typedef struct {
    uint8_t numbers[LONG_LOCATION_2_INDEX_ARRAY_SIZE];
    char stringInProgramMem[LONG_LOCATION_2_STRING_LENGTH];
} LONG_LOCATION_2;

const __attribute__((__progmem__)) LONG_LOCATION_2 longLocations_2[AMOUNT_LONG_LOCATION_2_STRINGS] = {
        {{4,},"You are in a valley in the forest beside a stream tumbling\nalong a rocky bed.\n"},
        {{7,},"At your feet all the water of the stream splashes into a\n2-inch slit in the rock.  Downstream the streambed is bare rock.\n"},
        {{9,},"You are in a small chamber beneath a 3x3 steel grate to the\nsurface.  A low crawl over cobbles leads inward to the West.\n"},
        {{10,},"You are crawling over cobbles in a low passage.  There is a\ndim light at the east end of the passage.\n"},
        {{14,},"At your feet is a small pit breathing traces of white mist.\nAn east passage ends here except for a small crack leading\non.\n"},
        {{17,},"You are on the east bank of a fissure slicing clear across\nthe hall.  The mist is quite thick here, and the fissure\nis too wide to jump.\n"},
        {{18,},"This is a low room with a crude note on the wall.  The\nnote says:\n       You won't get it up the steps.\n"},
        {{19,},"You are in the hall of the mountain king, with passages\noff in all directions.\n"},
        {{23,},"You are at the west end of the twopit room.  There is a\nlarge hole in the wall above the pit at this end of the\nroom.\n"},
        {{24,},"You are that the bottom of the eastern pit in the twopit\nroom.  There is a small pool of oil in one corner of the\npit.\n"},
        {{25,},"You are at the bottom of the western pit in the towpit room.\nThere is a large hole in the wall about 25 feet above you.\n"},
        {{28,},"You are in a low N/S passage at a hole in the floor.  The\nhole goes down to an E/W passage.\n"},
        {{30,},"You are in the west side chamber of the hall of the\nmountain king.  A passage continues west and up here.\n"},
        {{36,},"You are in a dirty broken passage.  To the east is a\ncrawl.  To the west is a large passage.  Above you is\nanother passage.\n"},
        {{37,},"You are on the brink of a small clean climbable pit.  A\ncrawl leads west.\n"},
        {{38,},"You are in the bottom of a small pit with a little stream,\nwhich enters and exits through tiny slits.\n"},
        {{39,},"You are in a large room full of dusty rocks.  There is a\nbig hole in the floor.  There are cracks everywhere, and\na passage leading east.\n"},
        {{40,},"You have crawled through a very low wide passage parallel\nto and north of the hall of mists.\n"},
        {{59,},"You have crawled through a very low wide passage paralled\nto and north of the hall of mists.\n"},
        {{61,},"You are at the west end of a very long featureless hall.\nThe hall joins up with a narrow north/south passage.\n"},
        {{65,},"You are in bedquilt, a long east/west passage with holes\neverywhere.  To explore at random select north, south, up\nor down.\n"},
        {{77,},"You are in a tall E/W canyon.  A low tight crawl goes 3\nfeet north and seems to open up.\n"},
        {{79,},"The stream flows out through a pair of 1 foot diameter\nsewer pipes.  It would be advisable to use the exit.\n"},
        {{96,},"You are in the soft room.  The walls are covered with\nheavy curtains, the floor with a thick pile carpet.\nMoss covers the ceiling.\n"},
        {{100,},"You're in a small chamber lit by an eerie green light.  An\nextremely narrow tunnel exits to the west.  A dark corridor\nleads ne.\n"},
        {{118,},"You are in a long winding corridor sloping out of sight\nin both directions.\n"},
        {{122,},"You are on the far side of the chasm.  A ne path leads away\nfrom the chasm on this side.\n"},
        {{123,},"You're in a long east/west corridor.  A faint rumbling noise\ncan be heard in the distance.\n"},
        {{128,},"You are walking along a gently sloping north/south passage\nlined with oddly shaped limestone formations.\n"},
        {{129,},"You are standing at the entrance to a large, barren\nroom.  A sign posted above the entrance reads:\n       \"Caution!  Bear in room!\"\n"},
};

typedef struct {
    uint8_t numbers[LONG_LOCATION_3_INDEX_ARRAY_SIZE];
    char stringInProgramMem[LONG_LOCATION_3_STRING_LENGTH];
} LONG_LOCATION_3;

const __attribute__((__progmem__)) LONG_LOCATION_3 longLocations_3[AMOUNT_LONG_LOCATION_3_STRINGS] = {
        {{1,},"You are standing at the end of a road before a small brick\nbuilding.  Around you is a forest.  A small stream flows out\nof the building and down a gully.\n"},
        {{2,},"You have walked up a hill, still in the forest.  The road\nslopes back down the other side of the hill.  There is a\nbuilding in the distance.\n"},
        {{8,},"You are in a 20-foot depression floored with bare dirt.  Set\ninto the dirt is a strong steel grate mounted in concrete.\nA dry streambed leads into the depression.\n"},
        {{13,},"You are in a splendid chamber thirty feet high.  The walls\nare frozen rivers of orange stone.  An awkward canyon and a\ngood passage exit from east and west sides of the chamber.\n"},
        {{33,},"You are in a large room, with a passage to the south,\na passage to the west, and a wall of broken rock to the\neast.  There is a large \"Y2\" on a rock in the room's \ncenter.\n"},
        {{41,},"You are at the west end of hall of mists.  A low wide crawl\ncontinues west and another goes north.  To the south is a\nlittle passage 6 feet off the floor.\n"},
        {{57,},"You are on the brink of a thirty foot pit with a massive\norange column down one wall.  You could climb down here but\nyou could not get back up.  The maze continues at this level.\n"},
        {{60,},"You are at the east end of a very long hall apparently\nwithout side chambers.  To the east a low wide crawl\nslants up.  To the north a round two foot hole slants\ndown.\n"},
        {{66,},"You are in a room whose walls resemble swiss cheese.  \nObvious passages go west, east, ne, and nw.  Part of the\nroom is occupied by a large bedrock block.\n"},
        {{71,},"You are in a secret canyon at a junction of three canyons,\nbearing north, south and se.  The north one is as tall as\nthe other two combined.\n"},
        {{74,},"You are in a secret canyon which here runs E/W.  It crosses\nover a very tight canyon 15 feet below.  If you go down you\nmay not be able to get back up.\n"},
        {{88,},"You are in a long, narrow corridor stretching out of sight\nto the west.  At the eastern end is a hole through which\nyou can see a profusion of leaves,\n"},
        {{91,},"You are at the top of a steep incline above a large room.\nYou could climb down here, but you would not be able to\nclimb up.  There is a passage leading back to the north.\n"},
        {{97,},"This is the oriental room.  Ancient oriental cave drawings\ncover the walls.  A gently sloping passage leads upward\nto the north, another passage leads se, and a hands and\nknees crawl leads west.\n"},
        {{102,},"You are in an arched hall.  A coral passage once continued\nup and east from here, but is now blocked by debris.  The\nair smells of sea water.\n"},
        {{117,},"You are on one side of a large deep chasm.  A heavy white\nmist rising up from below obscures all view of the far\nside.  A sw path leads away from the chasm into a winding\ncorridor.\n"},
        {{125,},"The walls are quite warm here.  From the north can be heard\na steady roar, so loud that the entire cave seems to be\ntrembling.  Another passage leads south, and a low crawl\ngoes east.\n"},
        {{130,},"You are inside a barren room.  The center of the room\nis completely empty except for some dust.  Marks in\nthe dust lead away toward the far end of the room.\nThe only exit is the way you came in.\n"},
};

typedef struct {
    uint8_t numbers[LONG_LOCATION_4_INDEX_ARRAY_SIZE];
    char stringInProgramMem[LONG_LOCATION_4_STRING_LENGTH];
} LONG_LOCATION_4;

const __attribute__((__progmem__)) LONG_LOCATION_4 longLocations_4[AMOUNT_LONG_LOCATION_4_STRINGS] = {
        {{11,},"You are in a debris room filled with stuff washed in from the\nsurface.  A low wide passage with cobbles becomes plugged\nwith mud and debris here, but an awkward canyon leads\nupward and west.  A note on the wall says:\n       Magic Word \"XYZZY\"\n"},
        {{64,},"You are at a complex junction.  A low hands and knees passage\nfrom the north joins a higher crawl from the east to make\na walking passage going west.  There is also a large room\nabove.  The air is damp here.\n"},
        {{68,},"You are in a large low circular chamber whose floor is\nan immense slab fallen from the ceiling (slab room).\nEast and west there once were large passages, but they\nare now filled with boulders.  Low small passages go\nnorth and south, and the south one quickly bends west\naround the boulders.\n"},
        {{92,},"You are in the giant room.  The ceiling is too high up\nfor your lamp to show it.  Cavernous passages lead east,\nnorth, and south.  On the west wall is scrawled the\ninscription:\n              \"Fee Fie Foe Foo\"       {sic}\n"},
        {{95,},"You are in a magnificent cavern with a rushing stream,\nwhich cascades over a sparkling waterfall into a\nroaring whirlpool which disappears through a hole in\nthe floor.  Passages exit to the south and west.\n"},
        {{98,},"You are following a wide path around the outer edge of a\nlarge cavern.  Far below, through a heavy white mist,\nstrange splashing noises can be heard.  The mist rises up\nthrough a fissure in the ceiling.  The path exits to the\nsouth and west.\n"},
        {{99,},"You are in an alcove.  A small nw path seems to widen\nafter a short distance.  An extremely tight tunnel leads\neast.  It looks like a very tight squeeze.  An eerie\nlight can be seen at the other end.\n"},
        {{103,},"You're in a large room carved out of sedimentary rock.\nThe floor and walls are littered with bits of shells\nimbedded in the stone.  A shallow passage proceeds\ndownward, and a somewhat steeper one leads up.  A low\nhands and knees passage enters from the south.\n"},
        {{106,},"You are in an anteroom leading to a large passage to the\neast.  Small passages go west and up.  The remnants of\nrecent digging are evident.  A sign in midair here says:\n       \"Cave under construction beyond this point.\"\n              \"Proceed at your own risk.\"\n             \"Witt construction company\"\n"},
        {{111,},"A large stalactite extends from the roof and almost reaches\nthe floor below.  You could climb down it, and jump from\nit to the floor, but having done so you would be unable to\nreach it to climb back up.\n"},
        {{124,},"The path forks here.  The left fork leads northeast.  A dull\nrumbling seems to get louder in that direction.  The right\nfork leads southeast down a gentle slope.  The main\ncorridor enters from the west.\n"},
        {{127,},"You are in a small chamber filled with large boulders.\nThe walls are very warm, causing the air in the room\nto be almost stifling from the heat.  The only exit\nis a crawl heading west, through which is coming\na low rumbling.\n"},
};

typedef struct {
    uint8_t numbers[LONG_LOCATION_5_INDEX_ARRAY_SIZE];
    char stringInProgramMem[LONG_LOCATION_5_STRING_LENGTH];
} LONG_LOCATION_5;

const __attribute__((__progmem__)) LONG_LOCATION_5 longLocations_5[AMOUNT_LONG_LOCATION_5_STRINGS] = {
        {{15,},"You are at one end of a vast hall stretching forward out of\nsight to the west.  There are openings to either side.\nNearby, a wide stone staircase leads downward.  The hall\nis filled with wisps of white mist swaying to and fro\nalmost as if alive.  A cold wind blows up the staircase.\nThere is a passage at the top of a dome behind you.\n"},
        {{35,},"You're at a low window overlooking a huge pit, which\nextends up out of sight.  A floor is indistinctly visible\nover 50 feet below.  Traces of white mist cover the floor\nof the pit, becoming thicker to the right.  Marks in the\ndust around the window would seem to indicate that\nsomeone has been here recently.  Directly across the pit\nfrom you and 25 feet away there is a similar window\nlooking into a lighted room.  A shadowy figure can\nbe seen there peering back at you.\n"},
        {{67,},"You are at the east end of the twopit room.  The floor\nhere is littered with thin rock slabs, which make it easy\nto descend the pits.  There is a path here bypassing\nthe pits to connect passages from east and west.\nThere are holes all over, but the only bit one is on\nthe wall directly over the west pit where you can't\nget at it.\n"},
        {{109,},"You are in a north/south canyon about 25 feet across.  The\nfloor is covered by white mist seeping in from the north.\nThe walls extend upward for well over 100 feet.  Suspended\nfrom some unseen point far above you, an enormous two-\nsided mirror is hanging paralled to and midway between\nthe canyon walls.  (The mirror is obviously provided\nfor the use of the dwarves, who as you know, are\nextremely vain.)  A small window can be seen in either\nwall, some fifty feet up.\n"},
        {{110,},"You're at a low window overlooking a huge pit, which\nextends up out of sight.  A floor is indistinctly visible\nover 50 feet below.  Traces of white mist cover the floor\nof the pit, becoming thicker to the left.  Marks in the\ndust around the window would seem to indicate that\nsomeone has been here recently.  Directly across the pit\nfrom you and 25 feet away there is a similar window\nlooking into a lighted room.  A shadowy figure can be seen\nthere peering back at you.\n"},
        {{113,},"You are at the edge of a large underground reservoir.  An\nopaque cloud of white mist fills the room and rises\nrapidly upward.  The lake is fed by a stream which tumbles\nout of a hole in the wall about 10 feet overhead and\nsplashes noisily into the water somewhere within the mist.\nThe only passage goes back toward the south.\n"},
        {{116,},"You are at the southwest end of the repository.  To one\nside is a pit full of fierce green snakes.  On the other\nside is a row of small wicker cages, each of which contains\na little sulking bird.  In one corner is a bundle of\nblack rods with rusty marks on their ends.  A large\nnumber of velvet pillows are scattered about on the floor.\nA vast mirror stretches off to the northeast.  At your\nfeet is a large steel grate, next to which is a sign\nwhich reads:\n     \"Treasure vault.  Keys in main office.\"\n"},
};

#define LONG_LOCATION_115_STRING_LENGTH 767
const __attribute__((__progmem__)) char longLocation_115[LONG_LOCATION_115_STRING_LENGTH] = "You are at the northeast end of an immense room, even\nlarger than the giant room.  It appears to be a repository\nfor the \"adventure\" program.  Massive torches far overhead\nbathe the room with smoky yellow light.  Scattered about\nyou can be seen a pile of bottles (all of them empty), a\nnursery of young beanstalks murmuring quietly, a bed of\noysters, a bundle of black rods with rusty stars on their\nends, and a collection of brass lanterns.  Off to one side\na great many Dwarves are sleeping on the floor, snoring\nloudly.  A sign nearby reads:\n        \"Do NOT disturb the Dwarves!\"\nAn immense mirror is hanging against one wall, and\nstretches to the other end of the room, where various\nother sundry objects can be glimpsed dimly in the distance.\n";

#define LONG_LOCATION_126_STRING_LENGTH 1321
const __attribute__((__progmem__)) char longLocation_126[LONG_LOCATION_126_STRING_LENGTH] = "You are on the edge of a breath-taking view.  Far below you is an \nactive volcano, from which great gouts of molten lava come surging \nout, cascading back down into the depths. The glowing rock fills the \nfarthest reaches of the cavern with a blood-red glare, giving \neverything an eerie, macabre appearance.\nThe air is filled with flickering sparks of ash and a heavy smell of \nbrimstone.  The walls are hot to the touch, and the thundering of the \nvolcano drowns out all other sounds.  Embedded in the jagged roof far \noverhead are myriad formations composed of pure white alabaster, which \nscatter their murky light into sinister apparitions upon the walls.\nTo one side is a deep gorge, filled with a bizarre chaos of tortured \nrock which seems to have been crafted by the Devil Himself.  An \nimmense river of fire crashes out from the depths of the volcano, \nburns its way through the gorge, and plummets into a bottomless pit \nfar off to your left.  \nTo the right, an immense geyser of blistering steam erupts \ncontinuously from a barren island in the center of a sulfurous lake, \nwhich bubbles ominously. The far right wall is aflame with an \nincandescence of its own, which lends an additional infernal splendor \nto the already hellish scene.  \nA dark, foreboding passage exits to the south.\n";

char * loadLongLocation(FlashHelper * helper, uint8_t longLocationNumber) {
    char * stringToReturn = NULL;

    if (longLocationNumber == 115) {
        stringToReturn = (char *) malloc(LONG_LOCATION_115_STRING_LENGTH);
        helper->loadFarStringFromFlash(stringToReturn, pgm_get_far_address(longLocation_115));
    }
    if (longLocationNumber == 126) {
        stringToReturn = (char *) malloc(LONG_LOCATION_126_STRING_LENGTH);
        helper->loadFarStringFromFlash(stringToReturn, pgm_get_far_address(longLocation_126));
    }
    LOAD_FROM(1)
    LOAD_FROM(2)
    LOAD_FROM(3)
    LOAD_FROM(4)
    LOAD_FROM(5)

    return stringToReturn;
}

//getter function expects an initialized instance of FlashHelper as reachable global reference
char * getLongLocation(int longLocationNumber) {
    return loadLongLocation(flashHelper, longLocationNumber);
}