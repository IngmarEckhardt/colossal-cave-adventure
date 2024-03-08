#include <long_locations.h>
//advent1.h
#ifndef CCA_TEST
#include <avr/pgmspace.h>
#endif
#include <stdlib.h>
#include <cca_helper.h>


#define LOC_DESCRIPTIONS_SMALL_LENGTH 62
#define LOC_DESCRIPTIONS_MEDIUM_LENGTH 186
#define LOC_DESCRIPTIONS_LONG_LENGTH 520

#define AMOUNT_OF_LOC_DESCRIPTIONS_SMALL 31
#define AMOUNT_OF_LOC_DESCRIPTIONS_MEDIUM 49
#define AMOUNT_OF_LOC_DESCRIPTIONS_LONG 22

#define MAX_AMOUNT_SMALL_LOC_SANE_DESCRIPTION 14

#define LOC_DESCRIPTION_115_LENGTH 748
#define LOC_DESCRIPTION_126_LENGTH 1299

typedef struct {
    uint8_t numbers[MAX_AMOUNT_SMALL_LOC_SANE_DESCRIPTION];
    char stringInProgramMem[LOC_DESCRIPTIONS_SMALL_LENGTH];
} ShortLongLocation;

const ShortLongLocation shortLongLocations[AMOUNT_OF_LOC_DESCRIPTIONS_SMALL] PROGMEM = {
        {{3,},"You are inside a building, a well house for a large spring.\n"},
        {{5,},"You are in open forest, with a deep valley to one side.\n"},
        {{6,},"You are in open forest near both a valley and a road.\n"},
        {{12,},"You are in an awkward sloping east/west canyon.\n"},
        {{16,},"The crack is far too small for you to follow.\n"},
        {{20,},"You are at the bottom of the pit with a broken neck.\n"},
        {{21,},"You didn't make it.\n"},
        {{22,},"The dome is unclimbable.\n"},
        {{27,},"You are on the west side of the fissure in the hall of mists.\n"},
        {{29,},"You are in the south side chamber.\n"},
        {{31,},">$<\n"},
        {{32,},"You can't get by the snake.\n"},
        {{34,},"You are in a jumble of rock, with cracks everywhere.\n"},
        {{42,43,44,45,49,50,51,52,53,55,80,83,84,87,},"You are in a maze of twisty little passages, all alike.\n"},
        {{46,47,48,54,56,58,63,81,82,85,86,114,140,},"Dead end.\n"},
        {{69,},"You are in a secret N/S canyon above a large room.\n"},
        {{70,},"You are in a secret N/S canyon above a sizable passage.\n"},
        {{72,},"You are in a large low room.  Crawls lead north, se, and sw.\n"},
        {{73,},"Dead end crawl.\n"},
        {{75,},"You are at a wide place in a very tight N/S canyon.\n"},
        {{76,},"The canyon here becomes too tight to go further south.\n"},
        {{78,},"The canyon runs into a mass of boulders -- dead end.\n"},
        {{90,},"You have climbed up the plant and out of the pit.\n"},
        {{93,},"The passage here is blocked by a recent cave-in.\n"},
        {{94,},"You are at one end of an immense north/south passage.\n"},
        {{104,},"You are in a long sloping corridor with ragged sharp walls.\n"},
        {{105,},"You are in a cul-de-sac about eight feet across.\n"},
        {{107,131,132,133,134,135,136,137,138,139,},"You are in a maze of little twisty passages, all different.\n"},
        {{108,},"You are at Witt's end.  Passages lead off in ALL directions.\n"},
        {{112,},"You are in a little maze of twisting passages, all different.\n"},
        {{119,120,121,},"You are in a secret canyon which exits to the north and east.\n"},
};

typedef struct {
    uint8_t number[1];
    char description[LOC_DESCRIPTIONS_MEDIUM_LENGTH];
} MediumLongLocation;

const MediumLongLocation mediumLongLocations[AMOUNT_OF_LOC_DESCRIPTIONS_MEDIUM] PROGMEM = {
        {{1,},"You are standing at the end of a road before a small brick\nbuilding.  Around you is a forest.  A small stream flows out\nof the building and down a gully.\n"},
        {{2,},"You have walked up a hill, still in the forest.  The road\nslopes back down the other side of the hill.  There is a\nbuilding in the distance.\n"},
        {{4,},"You are in a valley in the forest beside a stream tumbling\nalong a rocky bed.\n"},
        {{7,},"At your feet all the water of the stream splashes into a\n2-inch slit in the rock.  Downstream the streambed is bare rock.\n"},
        {{8,},"You are in a 20-foot depression floored with bare dirt.  Set\ninto the dirt is a strong steel grate mounted in concrete.\nA dry streambed leads into the depression.\n"},
        {{9,},"You are in a small chamber beneath a 3x3 steel grate to the\nsurface.  A low crawl over cobbles leads inward to the West.\n"},
        {{10,},"You are crawling over cobbles in a low passage.  There is a\ndim light at the east end of the passage.\n"},
        {{13,},"You are in a splendid chamber thirty feet high.  The walls\nare frozen rivers of orange stone.  An awkward canyon and a\ngood passage exit from east and west sides of the chamber.\n"},
        {{14,},"At your feet is a small pit breathing traces of white mist.\nAn east passage ends here except for a small crack leading\non.\n"},
        {{17,},"You are on the east bank of a fissure slicing clear across\nthe hall.  The mist is quite thick here, and the fissure\nis too wide to jump.\n"},
        {{18,},"This is a low room with a crude note on the wall.  The\nnote says:\n       You won't get it up the steps.\n"},
        {{19,},"You are in the hall of the mountain king, with passages\noff in all directions.\n"},
        {{23,},"You are at the west end of the twopit room.  There is a\nlarge hole in the wall above the pit at this end of the\nroom.\n"},
        {{24,},"You are that the bottom of the eastern pit in the twopit\nroom.  There is a small pool of oil in one corner of the\npit.\n"},
        {{25,},"You are at the bottom of the western pit in the towpit room.\nThere is a large hole in the wall about 25 feet above you.\n"},
        {{26,},"You clamber up the plant and scurry through the hole at the\ntop.\n"},
        {{28,},"You are in a low N/S passage at a hole in the floor.  The\nhole goes down to an E/W passage.\n"},
        {{30,},"You are in the west side chamber of the hall of the\nmountain king.  A passage continues west and up here.\n"},
        {{33,},"You are in a large room, with a passage to the south,\na passage to the west, and a wall of broken rock to the\neast.  There is a large \"Y2\" on a rock in the room's \ncenter.\n"},
        {{36,},"You are in a dirty broken passage.  To the east is a\ncrawl.  To the west is a large passage.  Above you is\nanother passage.\n"},
        {{37,},"You are on the brink of a small clean climbable pit.  A\ncrawl leads west.\n"},
        {{38,},"You are in the bottom of a small pit with a little stream,\nwhich enters and exits through tiny slits.\n"},
        {{39,},"You are in a large room full of dusty rocks.  There is a\nbig hole in the floor.  There are cracks everywhere, and\na passage leading east.\n"},
        {{40,},"You have crawled through a very low wide passage parallel\nto and north of the hall of mists.\n"},
        {{41,},"You are at the west end of hall of mists.  A low wide crawl\ncontinues west and another goes north.  To the south is a\nlittle passage 6 feet off the floor.\n"},
        {{57,},"You are on the brink of a thirty foot pit with a massive\norange column down one wall.  You could climb down here but\nyou could not get back up.  The maze continues at this level.\n"},
        {{59,},"You have crawled through a very low wide passage paralled\nto and north of the hall of mists.\n"},
        {{60,},"You are at the east end of a very long hall apparently\nwithout side chambers.  To the east a low wide crawl\nslants up.  To the north a round two foot hole slants\ndown.\n"},
        {{61,},"You are at the west end of a very long featureless hall.\nThe hall joins up with a narrow north/south passage.\n"},
        {{62,},"You are at a crossover of a high N/S passage and a low\nE/W one.\n"},
        {{65,},"You are in bedquilt, a long east/west passage with holes\neverywhere.  To explore at random select north, south, up\nor down.\n"},
        {{66,},"You are in a room whose walls resemble swiss cheese.  \nObvious passages go west, east, ne, and nw.  Part of the\nroom is occupied by a large bedrock block.\n"},
        {{71,},"You are in a secret canyon at a junction of three canyons,\nbearing north, south and se.  The north one is as tall as\nthe other two combined.\n"},
        {{74,},"You are in a secret canyon which here runs E/W.  It crosses\nover a very tight canyon 15 feet below.  If you go down you\nmay not be able to get back up.\n"},
        {{77,},"You are in a tall E/W canyon.  A low tight crawl goes 3\nfeet north and seems to open up.\n"},
        {{79,},"The stream flows out through a pair of 1 foot diameter\nsewer pipes.  It would be advisable to use the exit.\n"},
        {{88,},"You are in a long, narrow corridor stretching out of sight\nto the west.  At the eastern end is a hole through which\nyou can see a profusion of leaves,\n"},
        {{89,},"There is nothing here to climb.  Use \"up\" or \"out\" to leave\nthe pit.\n"},
        {{91,},"You are at the top of a steep incline above a large room.\nYou could climb down here, but you would not be able to\nclimb up.  There is a passage leading back to the north.\n"},
        {{96,},"You are in the soft room.  The walls are covered with\nheavy curtains, the floor with a thick pile carpet.\nMoss covers the ceiling.\n"},
        {{100,},"You're in a small chamber lit by an eerie green light.  An\nextremely narrow tunnel exits to the west.  A dark corridor\nleads ne.\n"},
        {{101,},"You're in the dark-room.  A corridor leading south is the\nonly exit.\n"},
        {{102,},"You are in an arched hall.  A coral passage once continued\nup and east from here, but is now blocked by debris.  The\nair smells of sea water.\n"},
        {{117,},"You are on one side of a large deep chasm.  A heavy white\nmist rising up from below obscures all view of the far\nside.  A sw path leads away from the chasm into a winding\ncorridor.\n"},
        {{118,},"You are in a long winding corridor sloping out of sight\nin both directions.\n"},
        {{122,},"You are on the far side of the chasm.  A ne path leads away\nfrom the chasm on this side.\n"},
        {{123,},"You're in a long east/west corridor.  A faint rumbling noise\ncan be heard in the distance.\n"},
        {{128,},"You are walking along a gently sloping north/south passage\nlined with oddly shaped limestone formations.\n"},
        {{129,},"You are standing at the entrance to a large, barren\nroom.  A sign posted above the entrance reads:\n       \"Caution!  Bear in room!\"\n"},
};

typedef struct {
    uint8_t number[1];
    char description[LOC_DESCRIPTIONS_LONG_LENGTH];
} LongLongLocation;


const LongLongLocation longLongLocations[AMOUNT_OF_LOC_DESCRIPTIONS_LONG]PROGMEM = {
        {{11,},"You are in a debris room filled with stuff washed in from the\nsurface.  A low wide passage with cobbles becomes plugged\nwith mud and debris here, but an awkward canyon leads\nupward and west.  A note on the wall says:\n       Magic Word \"XYZZY\"\n"},
        {{15,},"You are at one end of a vast hall stretching forward out of\nsight to the west.  There are openings to either side.\nNearby, a wide stone staircase leads downward.  The hall\nis filled with wisps of white mist swaying to and fro\nalmost as if alive.  A cold wind blows up the staircase.\nThere is a passage at the top of a dome behind you.\n"},
        {{35,},"You're at a low window overlooking a huge pit, which\nextends up out of sight.  A floor is indistinctly visible\nover 50 feet below.  Traces of white mist cover the floor\nof the pit, becoming thicker to the right.  Marks in the\ndust around the window would seem to indicate that\nsomeone has been here recently.  Directly across the pit\nfrom you and 25 feet away there is a similar window\nlooking into a lighted room.  A shadowy figure can\nbe seen there peering back at you.\n"},
        {{64,},"You are at a complex junction.  A low hands and knees passage\nfrom the north joins a higher crawl from the east to make\na walking passage going west.  There is also a large room\nabove.  The air is damp here.\n"},
        {{67,},"You are at the east end of the twopit room.  The floor\nhere is littered with thin rock slabs, which make it easy\nto descend the pits.  There is a path here bypassing\nthe pits to connect passages from east and west.\nThere are holes all over, but the only bit one is on\nthe wall directly over the west pit where you can't\nget at it.\n"},
        {{68,},"You are in a large low circular chamber whose floor is\nan immense slab fallen from the ceiling (slab room).\nEast and west there once were large passages, but they\nare now filled with boulders.  Low small passages go\nnorth and south, and the south one quickly bends west\naround the boulders.\n"},
        {{92,},"You are in the giant room.  The ceiling is too high up\nfor your lamp to show it.  Cavernous passages lead east,\nnorth, and south.  On the west wall is scrawled the\ninscription:\n              \"Fee Fie Foe Foo\"       {sic}\n"},
        {{95,},"You are in a magnificent cavern with a rushing stream,\nwhich cascades over a sparkling waterfall into a\nroaring whirlpool which disappears through a hole in\nthe floor.  Passages exit to the south and west.\n"},
        {{97,},"This is the oriental room.  Ancient oriental cave drawings\ncover the walls.  A gently sloping passage leads upward\nto the north, another passage leads se, and a hands and\nknees crawl leads west.\n"},
        {{98,},"You are following a wide path around the outer edge of a\nlarge cavern.  Far below, through a heavy white mist,\nstrange splashing noises can be heard.  The mist rises up\nthrough a fissure in the ceiling.  The path exits to the\nsouth and west.\n"},
        {{99,},"You are in an alcove.  A small nw path seems to widen\nafter a short distance.  An extremely tight tunnel leads\neast.  It looks like a very tight squeeze.  An eerie\nlight can be seen at the other end.\n"},
        {{103,},"You're in a large room carved out of sedimentary rock.\nThe floor and walls are littered with bits of shells\nimbedded in the stone.  A shallow passage proceeds\ndownward, and a somewhat steeper one leads up.  A low\nhands and knees passage enters from the south.\n"},
        {{106,},"You are in an anteroom leading to a large passage to the\neast.  Small passages go west and up.  The remnants of\nrecent digging are evident.  A sign in midair here says:\n       \"Cave under construction beyond this point.\"\n              \"Proceed at your own risk.\"\n             \"Witt construction company\"\n"},
        {{109,},"You are in a north/south canyon about 25 feet across.  The\nfloor is covered by white mist seeping in from the north.\nThe walls extend upward for well over 100 feet.  Suspended\nfrom some unseen point far above you, an enormous two-\nsided mirror is hanging paralled to and midway between\nthe canyon walls.  (The mirror is obviously provided\nfor the use of the dwarves, who as you know, are\nextremely vain.)  A small window can be seen in either\nwall, some fifty feet up.\n"},
        {{110,},"You're at a low window overlooking a huge pit, which\nextends up out of sight.  A floor is indistinctly visible\nover 50 feet below.  Traces of white mist cover the floor\nof the pit, becoming thicker to the left.  Marks in the\ndust around the window would seem to indicate that\nsomeone has been here recently.  Directly across the pit\nfrom you and 25 feet away there is a similar window\nlooking into a lighted room.  A shadowy figure can be seen\nthere peering back at you.\n"},
        {{111,},"A large stalactite extends from the roof and almost reaches\nthe floor below.  You could climb down it, and jump from\nit to the floor, but having done so you would be unable to\nreach it to climb back up.\n"},
        {{113,},"You are at the edge of a large underground reservoir.  An\nopaque cloud of white mist fills the room and rises\nrapidly upward.  The lake is fed by a stream which tumbles\nout of a hole in the wall about 10 feet overhead and\nsplashes noisily into the water somewhere within the mist.\nThe only passage goes back toward the south.\n"},
        {{116,},"You are at the southwest end of the repository.  To one\nside is a pit full of fierce green snakes.  On the other\nside is a row of small wicker cages, each of which contains\na little sulking bird.  In one corner is a bundle of\nblack rods with rusty marks on their ends.  A large\nnumber of velvet pillows are scattered about on the floor.\nA vast mirror stretches off to the northeast.  At your\nfeet is a large steel grate, next to which is a sign\nwhich reads:\n     \"Treasure vault.  Keys in main office.\"\n"},
        {{124,},"The path forks here.  The left fork leads northeast.  A dull\nrumbling seems to get louder in that direction.  The right\nfork leads southeast down a gentle slope.  The main\ncorridor enters from the west.\n"},
        {{125,},"The walls are quite warm here.  From the north can be heard\na steady roar, so loud that the entire cave seems to be\ntrembling.  Another passage leads south, and a low crawl\ngoes east.\n"},
        {{127,},"You are in a small chamber filled with large boulders.\nThe walls are very warm, causing the air in the room\nto be almost stifling from the heat.  The only exit\nis a crawl heading west, through which is coming\na low rumbling.\n"},
        {{130,},"You are inside a barren room.  The center of the room\nis completely empty except for some dust.  Marks in\nthe dust lead away toward the far end of the room.\nThe only exit is the way you came in.\n"},};

const char longLocationDescription_115[LOC_DESCRIPTION_115_LENGTH] PROGMEM =
        "You are at the northeast end of an immense room, even\n"
        "larger than the giant room.  It appears to be a repository\n"
        "for the \"adventure\" program.  Massive torches far overhead\n"
        "bathe the room with smoky yellow light.  Scattered about\n"
        "you can be seen a pile of bottles (all of them empty), a\n"
        "nursery of young beanstalks murmuring quietly, a bed of\n"
        "oysters, a bundle of black rods with rusty stars on their\n"
        "ends, and a collection of brass lanterns.  Off to one side\n"
        "a great many Dwarves are sleeping on the floor, snoring\n"
        "loudly.  A sign nearby reads:\n"
        "        \"Do NOT disturb the Dwarves!\"\n"
        "An immense mirror is hanging against one wall, and\n"
        "stretches to the other end of the room, where various\n"
        "other sundry objects can be glimpsed dimly in the distance.\n";

const char longLocationDescription_126[LOC_DESCRIPTION_126_LENGTH] PROGMEM =
        "You are on the edge of a breath-taking view.  Far below you is an \n"
        "active volcano, from which great gouts of molten lava come surging \n"
        "out, cascading back down into the depths. The glowing rock fills the \n"
        "farthest reaches of the cavern with a blood-red glare, giving \n"
        "everything an eerie, macabre appearance.\n"
        "The air is filled with flickering sparks of ash and a heavy smell of \n"
        "brimstone.  The walls are hot to the touch, and the thundering of the \n"
        "volcano drowns out all other sounds.  Embedded in the jagged roof far \n"
        "overhead are myriad formations composed of pure white alabaster, which \n"
        "scatter their murky light into sinister apparitions upon the walls.\n"
        "To one side is a deep gorge, filled with a bizarre chaos of tortured \n"
        "rock which seems to have been crafted by the Devil Himself.  An \n"
        "immense river of fire crashes out from the depths of the volcano, \n"
        "burns its way through the gorge, and plummets into a bottomless pit \n"
        "far off to your left.  \n"
        "To the right, an immense geyser of blistering steam erupts \n"
        "continuously from a barren island in the center of a sulfurous lake, \n"
        "which bubbles ominously. The far right wall is aflame with an \n"
        "incandescence of its own, which lends an additional infernal splendor \n"
        "to the already hellish scene.  \n"
        "A dark, foreboding passage exits to the south.\n";
