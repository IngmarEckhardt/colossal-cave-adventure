#include <long_location_descriptions.h>
//advent1.h
#include <avr/pgmspace.h>
#include <stddef.h>
#include <stdlib.h>

#define LOC_DESCRIPTIONS_SMALL_LENGTH 62
#define LOC_DESCRIPTIONS_MEDIUM_LENGTH 186
#define LOC_DESCRIPTIONS_LONG_LENGTH 520

#define AMOUNT_OF_LOC_DESCRIPTIONS_SMALL 29
#define AMOUNT_OF_LOC_DESCRIPTIONS_MEDIUM 52
#define AMOUNT_OF_LOC_DESCRIPTIONS_LONG 20

#define MAX_AMOUNT_SMALL_LOC_SANE_DESCRIPTION 14

#define LOC_DESCRIPTION_115_LENGTH 748
#define LOC_DESCRIPTION_126_LENGTH 1299


const char locationDescriptionsSmall[AMOUNT_OF_LOC_DESCRIPTIONS_SMALL][LOC_DESCRIPTIONS_SMALL_LENGTH] PROGMEM = {
        // 3
        "You are inside a building, a well house for a large spring.\n",
        // 5
        "You are in open forest, with a deep valley to one side.\n",
        // 6
        "You are in open forest near both a valley and a road.\n",
        // 12
        "You are in an awkward sloping east/west canyon.\n",
        // 16
        "The crack is far too small for you to follow.\n",
        // 20
        "You are at the bottom of the pit with a broken neck.\n",
        // 21
        "You didn't make it.\n",
        // 22
        "The dome is unclimbable.\n",
        // 29
        "You are in the south side chamber.\n",
        // 31
        ">$<\n",
        // 32
        "You can't get by the snake.\n",
        // 34
        "You are in a jumble of rock, with cracks everywhere.\n",
        // 42 43 44 45 49 50 51 52 53 55 80 83 84 87
        "You are in a maze of twisty little passages, all alike.\n",
        // 46 47 48 54 56 58 63 81 82 85 86 114 140
        "Dead end\n",
        // 69
        "You are in a secret N/S canyon above a large room.\n",
        // 70
        "You are in a secret N/S canyon above a sizable passage.\n",
        // 72
        "You are in a large low room. Crawls lead north, se, and sw.\n",
        // 73
        "Dead end crawl.\n",
        // 75
        "You are at a wide place in a very tight N/S canyon.\n",
        // 76
        "The canyon here becomes too tight to go further south.\n",
        // 78
        "The canyon runs into a mass of boulders -- dead end.\n",
        // 90
        "You have climbed up the plant and out of the pit.\n",
        // 93
        "The passage here is blocked by a recent cave-in.\n",
        // 94
        "You are at one end of an immense north/south passage.\n",
        // 104
        "You are in a long sloping corridor with ragged sharp walls.\n",
        // 105
        "You are in a cul-de-sac about eight feet across.\n",
        // 107 112 131 132 133 134 135 136 137 138 139
        "You are in a maze of twisty little passages, all different.\n",
        // 108
        "You are at Witt's end. Passages lead off in ALL directions.\n",
        // 119 120 121
        "You are in a secret canyon which exits to the north and east.\n"
};

const char locationDescriptionsMedium[AMOUNT_OF_LOC_DESCRIPTIONS_MEDIUM][LOC_DESCRIPTIONS_MEDIUM_LENGTH] PROGMEM = {
        // 1
        "You are standing at the end of a road before a small brick\n"
        "building.  Around you is a forest.  A small stream flows out\n"
        "of the building and down a gully.\n",
        // 2
        "You have walked up a hill, still in the forest.  The road\n"
        "slopes back down the other side of the hill.  There is a\n"
        "building in the distance.\n",
        // 4
        "You are in a valley in the forest beside a stream tumbling\n"
        "along a rocky bed.\n",
        // 7
        "At your feet all the water of the stream splashes into a\n"
        "2-inch slit in the rock.  Downstream the streambed is bare rock.\n",
        // 8
        "You are in a 20-foot depression floored with bare dirt.  Set\n"
        "into the dirt is a strong steel grate mounted in concrete.\n"
        "A dry streambed leads into the depression.\n",
        // 9
        "You are in a small chamber beneath a 3x3 steel grate to the\n"
        "surface.  A low crawl over cobbles leads inward to the West.\n",
        // 10
        "You are crawling over cobbles in a low passage.  There is a\n"
        "dim light at the east end of the passage.\n",
        // 13
        "You are in a splendid chamber thirty feet high.  The walls\n"
        "are frozen rivers of orange stone.  An awkward canyon and a\n"
        "good passage exit from east and west sides of the chamber.\n",
        // 14
        "At your feet is a small pit breathing traces of white mist.\n"
        "An east passage ends here except for a small crack leading\n"
        "on.\n",
        // 17
        "You are on the east bank of a fissure slicing clear across\n"
        "the hall.  The mist is quite thick here, and the fissure\n"
        "is too wide to jump.\n",
        // 18
        "This is a low room with a crude note on the wall.  The\n"
        "note says:\n"
        "       You won't get it up the steps.\n",
        // 19
        "You are in the hall of the mountain king, with passages\n"
        "off in all directions.\n",
        // 23
        "You are at the west end of the twopit room.  There is a\n"
        "large hole in the wall above the pit at this end of the\n"
        "room.\n",
        // 24
        "You are that the bottom of the eastern pit in the twopit\n"
        "room.  There is a small pool of oil in one corner of the\n"
        "pit.\n",
        // 25
        "You are at the bottom of the western pit in the towpit room.\n"
        "There is a large hole in the wall about 25 feet above you.\n",
        // 26
        "You clamber up the plant and scurry through the hole at the\n"
        "top.\n",
        // 28
        "You are in a low N/S passage at a hole in the floor.  The\n"
        "hole goes down to an E/W passage.\n",
        // 30
        "You are in the west side chamber of the hall of the\n"
        "mountain king.  A passage continues west and up here.\n",
        // 33
        "You are in a large room, with a passage to the south,\n"
        "a passage to the west, and a wall of broken rock to the\n"
        "east.  There is a large \"Y2\" on a rock in the room's \n"
        "center.\n",
        // 36
        "You are in a dirty broken passage.  To the east is a\n"
        "crawl.  To the west is a large passage.  Above you is\n"
        "another passage.\n",
        // 37
        "You are on the brink of a small clean climbable pit.  A\n"
        "crawl leads west.\n",
        // 38
        "You are in the bottom of a small pit with a little stream,\n"
        "which enters and exits through tiny slits.\n",
        // 39
        "You are in a large room full of dusty rocks.  There is a\n"
        "big hole in the floor.  There are cracks everywhere, and\n"
        "a passage leading east.\n",
        // 40
        "You have crawled through a very low wide passage parallel\n"
        "to and north of the hall of mists.\n",
        // 41
        "You are at the west end of hall of mists.  A low wide crawl\n"
        "continues west and another goes north.  To the south is a\n"
        "little passage 6 feet off the floor.\n",
        // 57
        "You are on the brink of a thirty foot pit with a massive\n"
        "orange column down one wall.  You could climb down here but\n"
        "you could not get back up.  The maze continues at this level.\n",
        // 59
        "You have crawled through a very low wide passage paralled\n"
        "to and north of the hall of mists.\n",
        // 60
        "You are at the east end of a very long hall apparently\n"
        "without side chambers.  To the east a low wide crawl slants\n"
        "up.  To the north a round two foot hole slants down.\n",
        // 61
        "You are at the west end of a very long featureless hall.\n"
        "The hall joins up with a narrow north/south passage.\n",
        // 62
        "You are at a crossover of a high N/S passage and a low\n"
        "E/W one.\n",
        // 65
        "You are in bedquilt, a long east/west passage with holes\n"
        "everywhere.  To explore at random select north, south, up\n"
        "or down.\n",
        // 66
        "You are in a room whose walls resemble swiss cheese.  \n"
        "Obvious passages go west, east, ne, and nw.  Part of the\n"
        "room is occupied by a large bedrock block.\n",
        // 65
        "You are in bedquilt, a long east/west passage with holes\n"
        "everywhere.  To explore at random select north, south, up\n"
        "or down.\n",
        // 66
        "You are in a room whose walls resemble swiss cheese.  \n"
        "Obvious passages go west, east, ne, and nw.  Part of the\n"
        "room is occupied by a large bedrock block.\n",
        // 71
        "You are in a secret canyon at a junction of three canyons,\n"
        "bearing north, south and se.  The north one is as tall as\n"
        "the other two combined.\n",
        // 74
        "You are in a secret canyon which here runs E/W.  It crosses\n"
        "over a very tight canyon 15 feet below.  If you go down you\n"
        "may not be able to get back up.\n",
        // 77
        "You are in a tall E/W canyon.  A low tight crawl goes 3\n"
        "feet north and seems to open up.\n",
        // 79
        "The stream flows out through a pair of 1 foot diameter\n"
        "sewer pipes.  It would be advisable to use the exit.\n",
        // 88
        "You are in a long, narrow corridor stretching out of sight\n"
        "to the west.  At the eastern end is a hole through which\n"
        "you can see a profusion of leaves,\n",
        // 89
        "There is nothing here to climb.  Use \"up\" or \"out\" to leave\n"
        "the pit.\n",
        // 91
        "You are at the top of a steep incline above a large room.\n"
        "You could climb down here, but you would not be able to\n"
        "climb up.  There is a passage leading back to the north.\n",
        // 96
        "You are in the soft room.  The walls are covered with\n"
        "heavy curtains, the floor with a thick pile carpet.\n"
        "Moss covers the ceiling.\n",
        // 100
        "You're in a small chamber lit by an eerie green light.  An\n"
        "extremely narrow tunnel exits to the west.  A dark corridor\n"
        "leads ne.\n",
        // 101
        "You're in the dark-room.  A corridor leading south is the\n"
        "only exit.\n",
        // 102
        "You are in an arched hall.  A coral passage once continued\n"
        "up and east from here, but is now blocked by debris.  The\n"
        "air smells of sea water.\n",
        // 117
        "You are on one side of a large deep chasm.  A heavy white\n"
        "mist rising up from below obscures all view of the far side.\n"
        "A sw path leads away from the chasm into a winding corridor.\n",
        // 118
        "You are in a long winding corridor sloping out of sight\n"
        "in both directions.\n",
        // 122
        "You are on the far side of the chasm.  A ne path leads away\n"
        "from the chasm on this side.\n",
        // 123
        "You're in a long east/west corridor.  A faint rumbling noise\n"
        "can be heard in the distance.\n",
        // 125
        "The walls are quite warm here. From the north can be heard a\n"
        "steady roar, so loud that the entire cave seems to be trembling.\n  "
        "Another passage leads south, and a low crawl goes east.\n",
        // 128
        "You are walking along a gently sloping north/south passage\n"
        "lined with oddly shaped limestone formations.\n",
        // 129
        "You are standing at the entrance to a large, barren\n"
        "room.  A sign posted above the entrance reads:\n"
        "       \"Caution!  Bear in room!\"\n",
};

const char locationDescriptionsLong[AMOUNT_OF_LOC_DESCRIPTIONS_LONG][LOC_DESCRIPTIONS_LONG_LENGTH] PROGMEM = {
        // 15
        "You are at one end of a vast hall stretching forward out of\n"
        "sight to the west.  There are openings to either side.\n"
        "Nearby, a wide stone staircase leads downward.  The hall\n"
        "is filled with wisps of white mist swaying to and fro\n"
        "almost as if alive.  A cold wind blows up the staircase.\n"
        "There is a passage at the top of a dome behind you.\n",
        // 35
        "You're at a low window overlooking a huge pit, which\n"
        "extends up out of sight.  A floor is indistinctly visible\n"
        "over 50 feet below.  Traces of white mist cover the floor\n"
        "of the pit, becoming thicker to the right.  Marks in the\n"
        "dust around the window would seem to indicate that\n"
        "someone has been here recently.  Directly across the pit\n"
        "from you and 25 feet away there is a similar window\n"
        "looking into a lighted room.  A shadowy figure can\n"
        "be seen there peering back at you.\n",
        // 64
        "You are at a complex junction.  A low hands and knees passage\n"
        "from the north joins a higher crawl from the east to make\n"
        "a walking passage going west.  There is also a large room\n"
        "above.  The air is damp here.\n",
        // 67
        "You are at the east end of the twopit room.  The floor\n"
        "here is littered with thin rock slabs, which make it easy\n"
        "to descend the pits.  There is a path here bypassing\n"
        "the pits to connect passages from east and west.\n"
        "There are holes all over, but the only bit one is on\n"
        "the wall directly over the west pit where you can't\n"
        "get at it.\n",
        // 68
        "You are in a large low circular chamber whose floor is\n"
        "an immense slab fallen from the ceiling (slab room).\n"
        "East and west there once were large passages, but they\n"
        "are now filled with boulders.  Low small passages go\n"
        "north and south, and the south one quickly bends west\n"
        "around the boulders.\n",
        // 92
        "You are in the giant room.  The ceiling is too high up\n"
        "for your lamp to show it.  Cavernous passages lead east,\n"
        "north, and south.  On the west wall is scrawled the\n"
        "inscription:\n"
        "              \"Fee Fie Foe Foo\"       {sic}\n",
        // 95
        "You are in a magnificent cavern with a rushing stream,\n"
        "which cascades over a sparkling waterfall into a\n"
        "roaring whirlpool which disappears through a hole in\n"
        "the floor.  Passages exit to the south and west.\n",
        // 97
        "This is the oriental room.  Ancient oriental cave drawings\n"
        "cover the walls.  A gently sloping passage leads upward\n"
        "to the north, another passage leads se, and a hands and\n"
        "knees crawl leads west.\n",
        // 98
        "You are following a wide path around the outer edge of a\n"
        "large cavern.  Far below, through a heavy white mist,\n"
        "strange splashing noises can be heard.  The mist rises up\n"
        "through a fissure in the ceiling.  The path exits to the\n"
        "south and west.\n",
        // 99
        "You are in an alcove.  A small nw path seems to widen\n"
        "after a short distance.  An extremely tight tunnel leads\n"
        "east.  It looks like a very tight squeeze.  An eerie\n"
        "light can be seen at the other end.\n",
        // 103
        "You're in a large room carved out of sedimentary rock.\n"
        "The floor and walls are littered with bits of shells\n"
        "imbedded in the stone.  A shallow passage proceeds\n"
        "downward, and a somewhat steeper one leads up.  A low\n"
        "hands and knees passage enters from the south.\n",
        // 106
        "You are in an anteroom leading to a large passage to the\n"
        "east.  Small passages go west and up.  The remnants of\n"
        "recent digging are evident.  A sign in midair here says:\n"
        "       \"Cave under construction beyond this point.\"\n"
        "              \"Proceed at your own risk.\"\n"
        "             \"Witt construction company\"\n",
        // 109
        "You are in a north/south canyon about 25 feet across.  The\n"
        "floor is covered by white mist seeping in from the north.\n"
        "The walls extend upward for well over 100 feet.  Suspended\n"
        "from some unseen point far above you, an enormous two-\n"
        "sided mirror is hanging paralled to and midway between\n"
        "the canyon walls.  (The mirror is obviously provided\n"
        "for the use of the dwarves, who as you know, are\n"
        "extremely vain.)  A small window can be seen in either\n"
        "wall, some fifty feet up.\n",
        // 110
        "You're at a low window overlooking a huge pit, which\n"
        "extends up out of sight.  A floor is indistinctly visible\n"
        "over 50 feet below.  Traces of white mist cover the floor\n"
        "of the pit, becoming thicker to the left.  Marks in the\n"
        "dust around the window would seem to indicate that\n"
        "someone has been here recently.  Directly across the pit\n"
        "from you and 25 feet away there is a similar window\n"
        "looking into a lighted room.  A shadowy figure can be seen\n"
        "there peering back at you.\n",
        // 111
        "A large stalactite extends from the roof and almost reaches\n"
        "the floor below.  You could climb down it, and jump from\n"
        "it to the floor, but having done so you would be unable to\n"
        "reach it to climb back up.\n",
        // 113
        "You are at the edge of a large underground reservoir.  An\n"
        "opaque cloud of white mist fills the room and rises\n"
        "rapidly upward.  The lake is fed by a stream which tumbles\n"
        "out of a hole in the wall about 10 feet overhead and\n"
        "splashes noisily into the water somewhere within the mist.\n"
        "The only passage goes back toward the south.\n",
        // 116
        "You are at the southwest end of the repository.  To one\n"
        "side is a pit full of fierce green snakes.  On the other\n"
        "side is a row of small wicker cages, each of which contains\n"
        "a little sulking bird.  In one corner is a bundle of\n"
        "black rods with rusty marks on their ends.  A large\n"
        "number of velvet pillows are scattered about on the floor.\n"
        "A vast mirror stretches off to the northeast.  At your\n"
        "feet is a large steel grate, next to which is a sign\n"
        "which reads:\n"
        "     \"Treasure vault.  Keys in main office.\"\n",
        // 124
        "The path forks here.  The left fork leads northeast.  A dull\n"
        "rumbling seems to get louder in that direction.  The right\n"
        "fork leads southeast down a gentle slope.  The main\n"
        "corridor enters from the west.\n",
        // 127
        "You are in a small chamber filled with large boulders.\n"
        "The walls are very warm, causing the air in the room\n"
        "to be almost stifling from the heat.  The only exit\n"
        "is a crawl heading west, through which is coming\n"
        "a low rumbling.\n",
        // 130
        "You are inside a barren room.  The center of the room\n"
        "is completely empty except for some dust.  Marks in\n"
        "the dust lead away toward the far end of the room.\n"
        "The only exit is the way you came in.\n",
};
//115
const char locationDescription_115[LOC_DESCRIPTION_115_LENGTH] PROGMEM =
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
//126
const char locationDescription_126[LOC_DESCRIPTION_126_LENGTH] PROGMEM =
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

const uint8_t shortLocMsg[AMOUNT_OF_LOC_DESCRIPTIONS_SMALL][MAX_AMOUNT_SMALL_LOC_SANE_DESCRIPTION] PROGMEM = {
        {3},
        {5},
        {6},
        {12},
        {16},
        {20},
        {21},
        {22},
        {29},
        {31},
        {32},
        {34},
        {42,  43,  44,  45,  49,  50,  51,  52,  53,  55,  80, 83,  84, 87},
        {46,  47,  48,  54,  56,  58,  63,  81,  82,  85,  86, 114, 140},
        {69},
        {70},
        {72},
        {73},
        {75},
        {76},
        {78},
        {90},
        {93},
        {94},
        {104},
        {105},
        {107, 112, 131, 132, 133, 134, 135, 136, 137, 138, 139},
        {108},
        {119, 120, 121},
};

const uint8_t mediumLocMsg[AMOUNT_OF_LOC_DESCRIPTIONS_MEDIUM] PROGMEM = {1, 2, 4, 7, 8, 9, 10, 13, 14, 17, 18, 19, 23, 24,
                                                                      25, 26,
                                                                      28, 30, 33, 36, 37, 38, 39, 40, 41, 57, 59, 60,
                                                                      61, 62, 65,
                                                                      66, 65, 66, 71, 74, 77, 79, 88, 89, 91, 96, 100,
                                                                      101, 102,
                                                                      117, 118, 122, 123, 125, 128, 129};
const uint8_t longLocMsg[AMOUNT_OF_LOC_DESCRIPTIONS_LONG] PROGMEM = {15, 35, 64, 67, 68, 92, 95, 97, 98, 99, 103, 106, 109,
                                                                  110, 111,
                                                                  113, 116, 124, 127, 130};

char * getLongLocationDescription(uint8_t locNumber) {
    char * stringToReturn = NULL;
    if (locNumber == 115) {
        stringToReturn = (char *) malloc(LOC_DESCRIPTION_115_LENGTH);
        strcpy_P(stringToReturn, locationDescription_115);
        return stringToReturn;
    } else if (locNumber == 126) {
        stringToReturn = (char *) malloc(LOC_DESCRIPTION_126_LENGTH);
        strcpy_P(stringToReturn, locationDescription_126);
        return stringToReturn;
    }


    for (uint8_t i = 0; i < AMOUNT_OF_LOC_DESCRIPTIONS_SMALL; i++) {
        for (int j = 0; j < MAX_AMOUNT_SMALL_LOC_SANE_DESCRIPTION; ++j) {
            if (pgm_read_byte(&shortLocMsg[i][j]) == locNumber) {
                stringToReturn = (char *) malloc(LOC_DESCRIPTIONS_SMALL_LENGTH);
                strcpy_P(stringToReturn, locationDescriptionsSmall[i]);
                return stringToReturn;
            }
        }
    }

    for (uint8_t i = 0; i < AMOUNT_OF_LOC_DESCRIPTIONS_MEDIUM; i++) {
        if (pgm_read_byte(&mediumLocMsg[i]) == locNumber) {
            stringToReturn = (char *) malloc(LOC_DESCRIPTIONS_MEDIUM_LENGTH);
            strcpy_P(stringToReturn, locationDescriptionsMedium[i]);
            return stringToReturn;
        }
    }

    for (uint8_t i = 0; i < AMOUNT_OF_LOC_DESCRIPTIONS_LONG; i++) {
        if (pgm_read_byte(&longLocMsg[i]) == locNumber) {
            stringToReturn = (char *) malloc(LOC_DESCRIPTIONS_LONG_LENGTH);
            strcpy_P(stringToReturn, locationDescriptionsLong[i]);
            return stringToReturn;
        }
    }
    return stringToReturn;
}

/* merged all different msg such as 131 to 139 into on version, deleted doubled white space in some strings to make
 * them fit into the arrays, and changed strings from 4 line to 3 (60, 117, 125)    */



