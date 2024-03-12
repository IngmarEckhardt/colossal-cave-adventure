#include <stdlib.h>
#include <stdint.h>
#ifndef CCA_TEST
#include <avr/pgmspace.h>
#include <advent.h>
#include <advdec.h>
#else
#include <string_repository.h>
#endif

#define SHORT_LOCATION_DESCRIPTION_1_LENGTH 16
#define SHORT_LOCATION_DESCRIPTION_2_LENGTH 31
#define SHORT_LOCATION_DESCRIPTION_3_LENGTH 56
#define SHORT_LOCATION_DESCRIPTION_4_LENGTH 76
#define SHORT_LOCATION_DESCRIPTION_5_LENGTH 187
#define AMOUNT_OF_SHORT_LOCATION_DESCRIPTIONS_1 2
#define AMOUNT_OF_SHORT_LOCATION_DESCRIPTIONS_2 51
#define AMOUNT_OF_SHORT_LOCATION_DESCRIPTIONS_3 29
#define AMOUNT_OF_SHORT_LOCATION_DESCRIPTIONS_4 11
#define AMOUNT_OF_SHORT_LOCATION_DESCRIPTIONS_5 8
#define MAX_AMOUNT_OF_SHORT_LOCATION_DESCRIPTIONS_1_WITH_SAME_LENGTH 13
#define MAX_AMOUNT_OF_SHORT_LOCATION_DESCRIPTIONS_2_WITH_SAME_LENGTH 2
#define MAX_AMOUNT_OF_SHORT_LOCATION_DESCRIPTIONS_3_WITH_SAME_LENGTH 1
#define MAX_AMOUNT_OF_SHORT_LOCATION_DESCRIPTIONS_4_WITH_SAME_LENGTH 14
#define MAX_AMOUNT_OF_SHORT_LOCATION_DESCRIPTIONS_5_WITH_SAME_LENGTH 1

typedef struct {
    uint8_t numbers[MAX_AMOUNT_OF_SHORT_LOCATION_DESCRIPTIONS_1_WITH_SAME_LENGTH];
    char stringInProgramMem[SHORT_LOCATION_DESCRIPTION_1_LENGTH];
} SHORT_LOCATION_1;

#ifndef CCA_TEST
const SHORT_LOCATION_1 shortLocations_1[AMOUNT_OF_SHORT_LOCATION_DESCRIPTIONS_1] PROGMEM = {
#else
const SHORT_LOCATION_1 shortLocations_1[AMOUNT_OF_SHORT_LOCATION_DESCRIPTIONS_1] = {
#endif
		{{31,},">$<\n"},
		{{46,47,48,54,56,58,63,81,82,85,86,114,140,},"Dead end.\n"},
};

typedef struct {
    uint8_t numbers[MAX_AMOUNT_OF_SHORT_LOCATION_DESCRIPTIONS_2_WITH_SAME_LENGTH];
    char stringInProgramMem[SHORT_LOCATION_DESCRIPTION_2_LENGTH];
} SHORT_LOCATION_2;

#ifndef CCA_TEST
const SHORT_LOCATION_2 shortLocations_2[AMOUNT_OF_SHORT_LOCATION_DESCRIPTIONS_2] PROGMEM = {
#else
const SHORT_LOCATION_2 shortLocations_2[AMOUNT_OF_SHORT_LOCATION_DESCRIPTIONS_2] = {
#endif
		{{1,},"You're at end of road again.\n"},
		{{2,},"You're at hill in road.\n"},
		{{3,},"You're inside building.\n"},
		{{4,},"You're in valley.\n"},
		{{5,6,},"You're in forest.\n"},
		{{7,},"You're at slit in streambed.\n"},
		{{8,},"You're outside grate.\n"},
		{{9,},"You're below the grate.\n"},
		{{10,},"You're in cobble crawl.\n"},
		{{11,},"You're in debris room.\n"},
		{{13,},"You're in bird chamber.\n"},
		{{14,},"You're at top of small pit.\n"},
		{{15,},"You're in hall of mists.\n"},
		{{19,},"You're in hall of mt. king.\n"},
		{{21,},"You didn't make it.\n"},
		{{22,},"The dome is unclimbable.\n"},
		{{24,},"You're in east pit.\n"},
		{{25,},"You're in west pit.\n"},
		{{32,},"You can't get by the snake.\n"},
		{{33,},"You're at \"Y2\".\n"},
		{{35,110,},"You're at window on pit.\n"},
		{{36,},"You're in dirty passage.\n"},
		{{39,},"You're in dusty rock room.\n"},
		{{57,},"You're at brink of pit.\n"},
		{{64,},"You're at complex junction.\n"},
		{{66,},"You're in swiss cheese room.\n"},
		{{68,},"You're in slab room.\n"},
		{{73,},"Dead end crawl.\n"},
		{{88,},"You're in narrow corridor.\n"},
		{{92,},"You're in giant room.\n"},
		{{96,},"You're in soft room.\n"},
		{{97,},"You're in oriental room.\n"},
		{{98,},"You're in misty cavern.\n"},
		{{99,},"You're in alcove.\n"},
		{{100,},"You're in plover room.\n"},
		{{101,},"You're in dark-room.\n"},
		{{102,},"You're in arched hall.\n"},
		{{103,},"You're in shell room.\n"},
		{{106,},"You're in anteroom.\n"},
		{{108,},"You're at Witt's end.\n"},
		{{109,},"You're in mirror canyon.\n"},
		{{111,},"You're at top of stalactite.\n"},
		{{113,},"You're at reservoir.\n"},
		{{117,},"You're on sw side of chasm.\n"},
		{{118,},"You're in sloping corridor.\n"},
		{{122,},"You're on ne side of chasm.\n"},
		{{123,},"You're in corridor.\n"},
		{{124,},"You're at fork in path.\n"},
		{{126,},"You're at breath-taking view.\n"},
		{{128,},"You're in limestone passage.\n"},
		{{130,},"You're in barren room.\n"},
};

typedef struct {
    uint8_t numbers[MAX_AMOUNT_OF_SHORT_LOCATION_DESCRIPTIONS_3_WITH_SAME_LENGTH];
    char stringInProgramMem[SHORT_LOCATION_DESCRIPTION_3_LENGTH];
} SHORT_LOCATION_3;

#ifndef CCA_TEST
const SHORT_LOCATION_3 shortLocations_3[AMOUNT_OF_SHORT_LOCATION_DESCRIPTIONS_3] PROGMEM = {
#else
const SHORT_LOCATION_3 shortLocations_3[AMOUNT_OF_SHORT_LOCATION_DESCRIPTIONS_3] = {
#endif
		{{12,},"You are in an awkward sloping east/west canyon.\n"},
		{{16,},"The crack is far too small for you to follow.\n"},
		{{17,},"You're on east bank of fissure.\n"},
		{{18,},"You're in nugget of gold room.\n"},
		{{20,},"You are the the bottom of the pit with a broken neck.\n"},
		{{23,},"You're at west end of twopit room.\n"},
		{{29,},"You are in the south side chamber.\n"},
		{{34,},"You are in a jumble of rock, with cracks everywhere.\n"},
		{{41,},"You're at west end of hall of mists.\n"},
		{{60,},"You're at east end of long hall.\n"},
		{{61,},"You're at west end of long hall.\n"},
		{{67,},"You're at east end of twopit room.\n"},
		{{69,},"You are in a secret N/S canyon above a large room.\n"},
		{{71,},"You're at junction of three secret canyons.\n"},
		{{74,},"You're at secret E/W canyon above tight canyon.\n"},
		{{75,},"You are at a wide place in a very tight N/S canyon.\n"},
		{{76,},"The canyon here becomes too tight to go further south.\n"},
		{{78,},"The canyon runs into a mass of boulders -- dead end.\n"},
		{{90,},"You have climbed up the plant and out of the pit.\n"},
		{{91,},"You're at steep incline above large room.\n"},
		{{93,},"The passage here is blocked by a recent cave-in.\n"},
		{{94,},"You are at one end of an immense north/south passage.\n"},
		{{95,},"You're in cavern with waterfall.\n"},
		{{105,},"You are in a cul-de-sac about eight feet across.\n"},
		{{115,},"You're at ne end of repository.\n"},
		{{116,},"You're at sw end of repository.\n"},
		{{125,},"You're at junction with warm walls.\n"},
		{{127,},"You're in chamber of boulders.\n"},
		{{129,},"You're in front of barren room.\n"},
};

typedef struct {
    uint8_t numbers[MAX_AMOUNT_OF_SHORT_LOCATION_DESCRIPTIONS_4_WITH_SAME_LENGTH];
    char stringInProgramMem[SHORT_LOCATION_DESCRIPTION_4_LENGTH];
} SHORT_LOCATION_4;

#ifndef CCA_TEST
const SHORT_LOCATION_4 shortLocations_4[AMOUNT_OF_SHORT_LOCATION_DESCRIPTIONS_4] PROGMEM = {
#else
const SHORT_LOCATION_4 shortLocations_4[AMOUNT_OF_SHORT_LOCATION_DESCRIPTIONS_4] = {
#endif
		{{26,},"You clamber up the plant and scurry through the hole at the\ntop.\n"},
		{{27,},"You are on the west side of the fissure in the hall of mists.\n"},
		{{37,},"You are on the brink of a small clean climbable pit.  A\ncrawl leads west.\n"},
		{{42,43,44,45,49,50,51,52,53,55,80,83,84,87,},"You are in a maze of twisty little passages, all alike.\n"},
		{{62,},"You are at a crossover of a high N/S passage and a low\nE/W one.\n"},
		{{70,},"You are in a secret N/S canyon above a sizable passage.\n"},
		{{72,},"You are in a large low room.  Crawls lead north, se, and sw.\n"},
		{{89,},"There is nothing here to climb.  Use \"up\" or \"out\" to leave\nthe pit.\n"},
		{{104,},"You are in a long sloping corridor with ragged sharp walls.\n"},
		{{107,112,131,132,133,134,135,136,137,138,139,},"You are in a maze of little twisty passages, all different.\n"},
		{{119,120,121,},"You are in a secret canyon which exits to the north and east.\n"},
};

typedef struct {
    uint8_t numbers[MAX_AMOUNT_OF_SHORT_LOCATION_DESCRIPTIONS_5_WITH_SAME_LENGTH];
    char stringInProgramMem[SHORT_LOCATION_DESCRIPTION_5_LENGTH];
} SHORT_LOCATION_5;

#ifndef CCA_TEST
const SHORT_LOCATION_5 shortLocations_5[AMOUNT_OF_SHORT_LOCATION_DESCRIPTIONS_5] PROGMEM = {
#else
const SHORT_LOCATION_5 shortLocations_5[AMOUNT_OF_SHORT_LOCATION_DESCRIPTIONS_5] = {
#endif
		{{28,},"You are in a low N/S passage at a hole in the floor.  The\nhole goes down to an E/W passage.\n"},
		{{30,},"You are in the west side chamber of the hall of the\nmountain king.  A passage continues west and up here.\n"},
		{{38,},"You are in the bottom of a small pit with a little stream,\nwhich enters and exits through tiny slits.\n"},
		{{40,},"You have crawled through a very low wide passage parallel\nto and north of the hall of mists.\n"},
		{{59,},"You have crawled through a very low wide passage paralled\nto and north of the hall of mists.\n"},
		{{65,},"You are in bedquilt, a long east/west passage with holes\neverywhere.  To explore at random select north, south, up\nor down.\n"},
		{{77,},"You are in a tall E/W canyon.  A low tight crawl goes 3\nfeet north and seems to open up.\n"},
		{{79,},"The stream flows out through a pair of 1 foot diameter\nsewer pipes.  It would be advisable to use the exit.\n"},
};



char * loadShortLocation(StringRepository * stringRepository, FlashHelper * flashHelper, uint8_t shortLocationNumber) {
    char * stringToReturn = NULL;

    if (stringToReturn != NULL) { return stringToReturn; }

    stringToReturn = stringRepository->loadStringFromFile(&(TextFile) {
            .entries = (void *) shortLocations_1,
            .maxLengthOfStrings = SHORT_LOCATION_DESCRIPTION_1_LENGTH,
            .sizeOfIndexArray = MAX_AMOUNT_OF_SHORT_LOCATION_DESCRIPTIONS_1_WITH_SAME_LENGTH,
            .amountOfEntries = AMOUNT_OF_SHORT_LOCATION_DESCRIPTIONS_1,
    }, flashHelper, shortLocationNumber);
    if (stringToReturn != NULL) { return stringToReturn; }

    stringToReturn = stringRepository->loadStringFromFile(&(TextFile) {
            .entries = (void *) shortLocations_2,
            .maxLengthOfStrings = SHORT_LOCATION_DESCRIPTION_2_LENGTH,
            .sizeOfIndexArray = MAX_AMOUNT_OF_SHORT_LOCATION_DESCRIPTIONS_2_WITH_SAME_LENGTH,
            .amountOfEntries = AMOUNT_OF_SHORT_LOCATION_DESCRIPTIONS_2,
    }, flashHelper, shortLocationNumber);
    if (stringToReturn != NULL) { return stringToReturn; }

    stringToReturn = stringRepository->loadStringFromFile(&(TextFile) {
            .entries = (void *) shortLocations_3,
            .maxLengthOfStrings = SHORT_LOCATION_DESCRIPTION_3_LENGTH,
            .sizeOfIndexArray = MAX_AMOUNT_OF_SHORT_LOCATION_DESCRIPTIONS_3_WITH_SAME_LENGTH,
            .amountOfEntries = AMOUNT_OF_SHORT_LOCATION_DESCRIPTIONS_3,
    }, flashHelper, shortLocationNumber);
    if (stringToReturn != NULL) { return stringToReturn; }

    stringToReturn = stringRepository->loadStringFromFile(&(TextFile) {
            .entries = (void *) shortLocations_4,
            .maxLengthOfStrings = SHORT_LOCATION_DESCRIPTION_4_LENGTH,
            .sizeOfIndexArray = MAX_AMOUNT_OF_SHORT_LOCATION_DESCRIPTIONS_4_WITH_SAME_LENGTH,
            .amountOfEntries = AMOUNT_OF_SHORT_LOCATION_DESCRIPTIONS_4,
    }, flashHelper, shortLocationNumber);
    if (stringToReturn != NULL) { return stringToReturn; }

    stringToReturn = stringRepository->loadStringFromFile(&(TextFile) {
            .entries = (void *) shortLocations_5,
            .maxLengthOfStrings = SHORT_LOCATION_DESCRIPTION_5_LENGTH,
            .sizeOfIndexArray = MAX_AMOUNT_OF_SHORT_LOCATION_DESCRIPTIONS_5_WITH_SAME_LENGTH,
            .amountOfEntries = AMOUNT_OF_SHORT_LOCATION_DESCRIPTIONS_5,
    }, flashHelper, shortLocationNumber);

	return stringToReturn;
}

char * getShortLocation(int shortLocationNumber) {
#ifndef CCA_TEST
    return loadShortLocation(stringRepository, flashHelper, shortLocationNumber);
#else
    StringRepository * stringRepository = dOS_initStringRepository(0);
    FlashHelper * flashHelper = dOS_initFlashHelper();
    char * result = loadShortLocation(stringRepository, flashHelper, shortLocationNumber);
    free(stringRepository);
    free(flashHelper);
    return result;
#endif
}
