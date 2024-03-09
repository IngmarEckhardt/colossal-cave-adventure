#include "unity.h"
#include <string_repository.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include "_include/advent1.h"
#include "_include/advent2.h"
#include "_include/advent3.h"
#include "_include/advent4.h"


void setUp(void) {
    // This is run before EACH test
}

void tearDown(void) {
    // This is run after EACH test
}

#define LOC_DESCRIPTIONS_SMALL_LENGTH 62
#define LOC_DESCRIPTIONS_MEDIUM_LENGTH 186
#define LOC_DESCRIPTIONS_LONG_LENGTH 520

#define AMOUNT_OF_LOC_DESCRIPTIONS_SMALL 30
#define AMOUNT_OF_LOC_DESCRIPTIONS_MEDIUM 50
#define AMOUNT_OF_LOC_DESCRIPTIONS_LONG 21

#define MAX_AMOUNT_SMALL_LOC_SANE_DESCRIPTION 14

#define LOC_DESCRIPTION_115_LENGTH 748
#define LOC_DESCRIPTION_126_LENGTH 1299

typedef struct {
    uint8_t numbers[MAX_AMOUNT_SMALL_LOC_SANE_DESCRIPTION];
    char stringInProgramMem[LOC_DESCRIPTIONS_SMALL_LENGTH];
} ShortLongLocation;

const ShortLongLocation shortLongLocations[AMOUNT_OF_LOC_DESCRIPTIONS_SMALL] = {
        {{3},                                                              "You are inside a building, a well house for a large spring.\n"},
        {{5},                                                              "You are in open forest, with a deep valley to one side.\n"},
        {{6},                                                              "You are in open forest near both a valley and a road.\n"},
        {{12},                                                             "You are in an awkward sloping east/west canyon.\n"},
        {{16},                                                             "The crack is far too small for you to follow.\n"},
        {{20},                                                             "You are at the bottom of the pit with a broken neck.\n"},
        {{21},                                                             "You didn't make it.\n"},
        {{22},                                                             "The dome is unclimbable.\n"},
        {{27},                                                             "You are on the west side of the fissure in the hall of mists.\n"},
        {{29},                                                             "You are in the south side chamber.\n"},
        {{31},                                                             ">$<\n"},
        {{32},                                                             "You can't get by the snake.\n"},
        {{34},                                                             "You are in a jumble of rock, with cracks everywhere.\n"},
        {{42,  43,  44,  45,  49,  50,  51,  52,  53,  55,  80, 83,  84, 87},
                                                                           "You are in a maze of twisty little passages, all alike.\n"},
        {{46,  47,  48,  54,  56,  58,  63,  81,  82,  85,  86, 114, 140}, "Dead end\n"},
        {{69},                                                             "You are in a secret N/S canyon above a large room.\n"},
        {{70},                                                             "You are in a secret N/S canyon above a sizable passage.\n"},
        {{72},                                                             "You are in a large low room. Crawls lead north, se, and sw.\n"},
        {{73},                                                             "Dead end crawl.\n"},
        {{75},                                                             "You are at a wide place in a very tight N/S canyon.\n"},
        {{76},                                                             "The canyon here becomes too tight to go further south.\n"},
        {{78},                                                             "The canyon runs into a mass of boulders -- dead end.\n"},
        {{90},                                                             "You have climbed up the plant and out of the pit.\n"},
        {{93},                                                             "The passage here is blocked by a recent cave-in.\n"},
        {{94},                                                             "You are at one end of an immense north/south passage.\n"},
        {{104},                                                            "You are in a long sloping corridor with ragged sharp walls.\n"},
        {{105},                                                            "You are in a cul-de-sac about eight feet across.\n"},
        {{107, 112, 131, 132, 133, 134, 135, 136, 137, 138, 139},
                                                                           "You are in a maze of twisty little passages, all different.\n"},
        {{108},                                                            "You are at Witt's end. Passages lead off in ALL directions.\n"},
        {{119, 120, 121},                                                  "You are in a secret canyon which exits to the north and east.\n"}
};


typedef struct {
    uint8_t number;
    char description[LOC_DESCRIPTIONS_MEDIUM_LENGTH];
} MediumLongLocation;

const MediumLongLocation mediumLongLocations[AMOUNT_OF_LOC_DESCRIPTIONS_MEDIUM] = {
        {1,   "You are standing at the end of a road before a small brick\n"
              "building.  Around you is a forest.  A small stream flows out\n"
              "of the building and down a gully.\n"},
        {2,   "You have walked up a hill, still in the forest.  The road\n"
              "slopes back down the other side of the hill.  There is a\n"
              "building in the distance.\n"},
        {4,   "You are in a valley in the forest beside a stream tumbling\n"
              "along a rocky bed.\n"},
        {7,   "At your feet all the water of the stream splashes into a\n"
              "2-inch slit in the rock.  Downstream the streambed is bare rock.\n"},
        {8,   "You are in a 20-foot depression floored with bare dirt.  Set\n"
              "into the dirt is a strong steel grate mounted in concrete.\n"
              "A dry streambed leads into the depression.\n"},
        {9,   "You are in a small chamber beneath a 3x3 steel grate to the\n"
              "surface.  A low crawl over cobbles leads inward to the West.\n"},
        {10,  "You are crawling over cobbles in a low passage.  There is a\n"
              "dim light at the east end of the passage.\n"},
        {13,  "You are in a splendid chamber thirty feet high.  The walls\n"
              "are frozen rivers of orange stone.  An awkward canyon and a\n"
              "good passage exit from east and west sides of the chamber.\n"},
        {14,  "At your feet is a small pit breathing traces of white mist.\n"
              "An east passage ends here except for a small crack leading\n"
              "on.\n"},
        {17,  "You are on the east bank of a fissure slicing clear across\n"
              "the hall.  The mist is quite thick here, and the fissure\n"
              "is too wide to jump.\n"},
        {18,  "This is a low room with a crude note on the wall.  The\n"
              "note says:\n"
              "       You won't get it up the steps.\n"},
        {19,  "You are in the hall of the mountain king, with passages\n"
              "off in all directions.\n"},
        {23,  "You are at the west end of the twopit room.  There is a\n"
              "large hole in the wall above the pit at this end of the\n"
              "room.\n"},
        {24,  "You are that the bottom of the eastern pit in the twopit\n"
              "room.  There is a small pool of oil in one corner of the\n"
              "pit.\n"},
        {25,  "You are at the bottom of the western pit in the towpit room.\n"
              "There is a large hole in the wall about 25 feet above you.\n"},
        {26,  "You clamber up the plant and scurry through the hole at the\n"
              "top.\n"},
        {28,  "You are in a low N/S passage at a hole in the floor.  The\n"
              "hole goes down to an E/W passage.\n"},
        {30,  "You are in the west side chamber of the hall of the\n"
              "mountain king.  A passage continues west and up here.\n"},
        {33,  "You are in a large room, with a passage to the south,\n"
              "a passage to the west, and a wall of broken rock to the\n"
              "east.  There is a large \"Y2\" on a rock in the room's \n"
              "center.\n"},
        {36,  "You are in a dirty broken passage.  To the east is a\n"
              "crawl.  To the west is a large passage.  Above you is\n"
              "another passage.\n"},
        {37,  "You are on the brink of a small clean climbable pit.  A\n"
              "crawl leads west.\n"},
        {38,  "You are in the bottom of a small pit with a little stream,\n"
              "which enters and exits through tiny slits.\n"},
        {39,  "You are in a large room full of dusty rocks.  There is a\n"
              "big hole in the floor.  There are cracks everywhere, and\n"
              "a passage leading east.\n"},
        {40,  "You have crawled through a very low wide passage parallel\n"
              "to and north of the hall of mists.\n"},
        {41,  "You are at the west end of hall of mists.  A low wide crawl\n"
              "continues west and another goes north.  To the south is a\n"
              "little passage 6 feet off the floor.\n"},
        {57,  "You are on the brink of a thirty foot pit with a massive\n"
              "orange column down one wall.  You could climb down here but\n"
              "you could not get back up.  The maze continues at this level.\n"},
        {59,  "You have crawled through a very low wide passage paralled\n"
              "to and north of the hall of mists.\n"},
        {60,  "You are at the east end of a very long hall apparently\n"
              "without side chambers.  To the east a low wide crawl slants\n"
              "up.  To the north a round two foot hole slants down.\n"},
        {61,  "You are at the west end of a very long featureless hall.\n"
              "The hall joins up with a narrow north/south passage.\n"},
        {62,  "You are at a crossover of a high N/S passage and a low\n"
              "E/W one.\n"},
        {65,  "You are in bedquilt, a long east/west passage with holes\n"
              "everywhere.  To explore at random select north, south, up\n"
              "or down.\n"},
        {66,  "You are in a room whose walls resemble swiss cheese.  \n"
              "Obvious passages go west, east, ne, and nw.  Part of the\n"
              "room is occupied by a large bedrock block.\n"},
        {71,  "You are in a secret canyon at a junction of three canyons,\n"
              "bearing north, south and se.  The north one is as tall as\n"
              "the other two combined.\n"},
        {74,  "You are in a secret canyon which here runs E/W.  It crosses\n"
              "over a very tight canyon 15 feet below.  If you go down you\n"
              "may not be able to get back up.\n"},
        {77,  "You are in a tall E/W canyon.  A low tight crawl goes 3\n"
              "feet north and seems to open up.\n"},
        {79,  "The stream flows out through a pair of 1 foot diameter\n"
              "sewer pipes.  It would be advisable to use the exit.\n"},
        {88,  "You are in a long, narrow corridor stretching out of sight\n"
              "to the west.  At the eastern end is a hole through which\n"
              "you can see a profusion of leaves.\n"},
        {89,  "There is nothing here to climb.  Use \"up\" or \"out\" to leave\n"
              "the pit.\n"},
        {91,  "You are at the top of a steep incline above a large room.\n"
              "You could climb down here, but you would not be able to\n"
              "climb up.  There is a passage leading back to the north.\n"},
        {96,  "You are in the soft room.  The walls are covered with\n"
              "heavy curtains, the floor with a thick pile carpet.\n"
              "Moss covers the ceiling.\n"},
        {100, "You're in a small chamber lit by an eerie green light.  An\n"
              "extremely narrow tunnel exits to the west.  A dark corridor\n"
              "leads ne.\n"},
        {101, "You're in the dark-room.  A corridor leading south is the\n"
              "only exit.\n"},
        {102, "You are in an arched hall.  A coral passage once continued\n"
              "up and east from here, but is now blocked by debris.  The\n"
              "air smells of sea water.\n"},
        {117, "You are on one side of a large deep chasm.  A heavy white\n"
              "mist rising up from below obscures all view of the far side.\n"
              "A sw path leads away from the chasm into a winding corridor.\n"},
        {118, "You are in a long winding corridor sloping out of sight\n"
              "in both directions.\n"},
        {122, "You are on the far side of the chasm.  A ne path leads away\n"
              "from the chasm on this side.\n"},
        {123, "You're in a long east/west corridor.  A faint rumbling noise\n"
              "can be heard in the distance.\n"},
        {125, "The walls are quite warm here. From the north can be heard a\n"
              "steady roar, so loud that the entire cave seems to be trembling.\n  "
              "Another passage leads south, and a low crawl goes east.\n"},
        {128, "You are walking along a gently sloping north/south passage\n"
              "lined with oddly shaped limestone formations.\n"},
        {129, "You are standing at the entrance to a large, barren\n"
              "room.  A sign posted above the entrance reads:\n"
              "       \"Caution!  Bear in room!\"\n"},
};

#define OBJ_DESCRIPTIONS_SMALL_LENGTH 62
#define OBJ_DESCRIPTIONS_MEDIUM_LENGTH 186
#define OBJ_DESCRIPTIONS_LONG_LENGTH 438

#define AMOUNT_OF_OBJ_DESCRIPTIONS_SMALL 22
#define AMOUNT_OF_OBJ_DESCRIPTIONS_MEDIUM 25
#define AMOUNT_OF_OBJ_DESCRIPTIONS_LONG 6
typedef struct {
    uint8_t number;
    char stringInProgramMem[OBJ_DESCRIPTIONS_SMALL_LENGTH];
} SmallObject;



const SmallObject smallObjects[AMOUNT_OF_OBJ_DESCRIPTIONS_SMALL]= {
        {1,  "/Set of keys.\n"
             "/There are some keys on the ground here.\n"
             "/\n"},
        {3,  "/*Grate\n"
             "/The grate is locked.\n"
             "/The grate is open.\n"
             "/\n"},
        {10, "/Velvet pillow\n"
             "/A small velvet pillow lies on the floor.\n"
             "/\n"},
        {11, "/*Snake\n"
             "/A huge green fierce snake bars the way!\n"
             "//\n"},
        {19, "/Tasty food\n"
             "/There is tasty food here.\n"
             "/\n"},
        {21, "/Water in the bottle.\n"
             "/\n"},
        {22, "/Oil in the bottle\n"
             "/\n"},
        {23, "/*Mirror\n"
             "//\n"},
        {26, "/*Stalactite\n"
             "//\n"},
        {29, "/*Cave drawings\n"
             "//\n"},
        {30, "/*Pirate\n"
             "//\n"},
        {34, "/*Phony troll\n"
             "/The troll is nowhere to be seen.\n"
             "/\n"},
        {37, "/*Volcano and,or Geyser\n"
             "//\n"},
        {40, "/*Carpet and,or moss\n"
             "//\n"},
        {51, "/Several diamonds\n"
             "/There are diamonds here!\n"
             "/\n"},
        {52, "/Bars of silver\n"
             "/There are bars of silver here!\n"
             "/\n"},
        {53, "/Precious jewelry\n"
             "/There is precious jewelry here!\n"
             "/\n"},
        {54, "/Rare coins\n"
             "/There are many coins here!\n"
             "/\n"},
        {55, "/Treasure chest\n"
             "/The pirate's treasure chest is here!\n"
             "/\n"},
        {57, "/Jeweled trident\n"
             "/There is a jewel-encrusted trident here!\n"
             "/\n"},
        {61, "/Glistening pearl\n"
             "/Off to one side lies a glistening pearl!\n"
             "/\n"},
        {63, "/Rare spices\n"
             "/There are rare spices here!\n"
             "/\n"}
};


void test_loadStringFromFile(void) {
    // Define a known input
    TextFile textFile = {
            .entries = (void *) shortLongLocations,
            .maxLengthOfStrings = LOC_DESCRIPTIONS_SMALL_LENGTH,
            .sizeOfIndexArray = MAX_AMOUNT_SMALL_LOC_SANE_DESCRIPTION,
            .amountOfEntries = AMOUNT_OF_LOC_DESCRIPTIONS_SMALL,
    };

    char * result = getStringIfNumberIncluded(textFile, 83);
    printf("Result: %s\n", result);
    result = getStringIfNumberIncluded(textFile, 89);
    printf("Result: %s\n", result);
    TextFile objectsFile = {
            .entries = (void *) smallObjects,
            .maxLengthOfStrings = OBJ_DESCRIPTIONS_SMALL_LENGTH,
            .sizeOfIndexArray = 1,
            .amountOfEntries = AMOUNT_OF_OBJ_DESCRIPTIONS_SMALL,
    };
    result = getStringIfNumberIncluded(objectsFile, 54);
    printf("Result: %s\n", result);
}









typedef struct {
    uint8_t indices[14];
    const char * text;
    int index_count;
} AdventEntry;

void toLowerCase(char* str) {
    for(int i = 0; str[i]; i++){
        str[i] = tolower(str[i]);
    }
}


char* replaceNewlineWithSlashN(const char* str) {
    char* result = malloc(strlen(str) * 2 + 1); // Allocate enough space for the replaced string
    char* dest = result;
    while (*str) {
        if (*str == '\n') {
            *dest++ = '\\';
            *dest++ = 'n';
        } else if (*str == '\"') {
            *dest++ = '\\';
            *dest++ = '\"';
        } else{
            *dest++ = *str;
        }
        str++;
    }
    *dest = '\0'; // Null-terminate the string
    return result;
}
void computeAdventtxt2() {
    uint16_t amount = 201;
    AdventEntry* entries = malloc(amount * sizeof(AdventEntry));
    int entry_count = 0;

    for (int i = 0; i < amount; i++) {
        uint8_t placed = 0;
        if(adventtxt4[i] == NULL) continue;
        for (int j = 0; j < entry_count; ++j) {


            if (strcmp(replaceNewlineWithSlashN(adventtxt4[i]),entries[j].text) == 0) {
                entries[j].indices[entries[j].index_count++] = i+1;
                placed = 1;
                break;
            }
        }
        if(!placed) {
            char* replaced = replaceNewlineWithSlashN(adventtxt4[i]);
            AdventEntry entry = {
                    .indices = {i+1},
                    .text = replaced,
                    .index_count = 1
            };
            entries[entry_count++] = entry;
        }
    }

    FILE *file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < entry_count; ++i) {
        if (strlen(entries[i].text) <= 187) { continue;}
        if (strlen(entries[i].text)> 521) { continue;}
        fprintf(file, "{{");

        for (int j = 0; j < entries[i].index_count; ++j) {
            fprintf(file, "%d,", entries[i].indices[j]);
        }

        fprintf(file, "},\"%s\"},\n", entries[i].text);
    }
    fprintf(file, "}\n");

    fclose(file);



    free(entries);

}

void test_convertAdvent(void) {
    computeAdventtxt2();

}





















int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_loadStringFromFile);
    RUN_TEST(test_convertAdvent);
    return UNITY_END();
}