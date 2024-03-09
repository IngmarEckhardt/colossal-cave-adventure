// advent3.h
#include <objects.h>
#include <avr/pgmspace.h>
#include <stdlib.h>
#include <cca_helper.h>

#define OBJ_DESCRIPTIONS_SMALL_LENGTH 59
#define OBJ_DESCRIPTIONS_MEDIUM_LENGTH 173
#define OBJ_DESCRIPTIONS_LONG_LENGTH 238

#define AMOUNT_OF_OBJ_DESCRIPTIONS_SMALL 20
#define AMOUNT_OF_OBJ_DESCRIPTIONS_MEDIUM 27
#define AMOUNT_OF_OBJ_DESCRIPTIONS_LONG 6
typedef struct {
    uint8_t number[1];
    char stringInProgramMem[OBJ_DESCRIPTIONS_SMALL_LENGTH];
} SmallObject;



const SmallObject smallObjects[AMOUNT_OF_OBJ_DESCRIPTIONS_SMALL]PROGMEM = {
        {{1,},"/Set of keys.\n/There are some keys on the ground here.\n/\n"},
        {{3,},"/*Grate\n/The grate is locked.\n/The grate is open.\n/\n"},
        {{10,},"/Velvet pillow\n/A small velvet pillow lies on the floor.\n/\n"},
        {{11,},"/*Snake\n/A huge green fierce snake bars the way!\n//\n"},
        {{19,},"/Tasty food\n/There is tasty food here.\n/\n"},
        {{21,},"/Water in the bottle.\n/\n"},
        {{22,},"/Oil in the bottle\n/\n"},
        {{23,},"/*Mirror\n//\n"},
        {{26,},"/*Stalactite\n//\n"},
        {{29,},"/*Cave drawings\n//\n"},
        {{30,},"/*Pirate\n//\n"},
        {{34,},"/*Phony troll\n/The troll is nowhere to be seen.\n/\n"},
        {{37,},"/*Volcano and,or Geyser\n//\n"},
        {{40,},"/*Carpet and,or moss\n//\n"},
        {{51,},"/Several diamonds\n/There are diamonds here!\n/\n"},
        {{52,},"/Bars of silver\n/There are bars of silver here!\n/\n"},
        {{53,},"/Precious jewelry\n/There is precious jewelry here!\n/\n"},
        {{54,},"/Rare coins\n/There are many coins here!\n/\n"},
        {{55,},"/Treasure chest\n/The pirate's treasure chest is here!\n/\n"},
        {{63,},"/Rare spices\n/There are rare spices here!\n/\n"},
};
typedef struct {
    uint8_t number[1];
    char description[OBJ_DESCRIPTIONS_MEDIUM_LENGTH];
} MediumObject;

const MediumObject mediumObjects[AMOUNT_OF_OBJ_DESCRIPTIONS_MEDIUM]PROGMEM = {
        {{2,},"/Brass lantern\n/There is a shiny brass lamp nearby.\n/There is a lamp shining nearby.\n/\n"},
        {{4,},"/Wicker cage\n/There is a small wicker cage discarded nearby.\n/\n"},
        {{5,},"/Black rod\n/A three foot black rod with a rusty star on an end lies nearby.\n/\n"},
        {{6,},"/Black rod\n/A three foot black rod with a rusty mark on an end lies nearby.\n/\n"},
        {{7,},"/*Steps\n/Rough stone steps lead down the pit.\n/Rough stone steps lead up the dome.\n/\n"},
        {{8,},"/Little bird in cage\n/A cheerful little bird is sitting here singing.\n/There is a little bird in the cage.\n/\n"},
        {{9,},"/*Rusty door\n/The way north is barred by a massive, rusty, iron door.\n/The way north leads through a massive, rusty, iron door.\n/\n"},
        {{12,},"/*Fissure\n//A crystal bridge now spans the fissure.\n/The crystal bridge has vanished!\n/\n"},
        {{13,},"/*Stone tablet\n/A massive stone tablet imbedded in the wall reads:\n\"Congratulations on bringing light into the dark-room!\"\n/\n"},
        {{14,},"/Giant clam >Grunt!<\n/There is an enormous clam here with its shell tightly closed.\n/\n"},
        {{15,},"/Giant oyster >Groan!<\n/There is an enormous oyster here with its shell tightly closed.\n/Interesting.  There seems to be something written on the\nunderside of the oyster.\n/\n"},
        {{16,},"/\"Spelunker Today\"\n/There are a few recent issues of \"Spelunker Today\" magazine\nhere.\n/\n"},
        {{20,},"/Small bottle\n/There is a bottle of water here.\n/There is an empty bottle here.\n/There is a bottle of oil here.\n/\n"},
        {{25,},"/*Phony plant\n/\n/The top of a 12-foot-tall beanstalk is poking up out of\nthe west pit.\n/There is a huge beanstalk growing out of the west pit up to\nthe hole.\n/\n"},
        {{27,},"/*Shadowy figure\n/The shadowy figure seems to be trying to attract your attention.\n/\n"},
        {{28,},"/Dwarf's axe\n/There is a little axe here.\n/There is a little axe lying beside the bear.\n/\n"},
        {{33,},"/*Troll\n/A burly troll stands by the bridge and insists you throw\nhim a treasure before you may cross.\n/The troll steps out from beneath the bridge and blocks\nyour way.\n//\n"},
        {{38,},"/*Vending machine\n/There is a massive vending machine here.  The instructions\non it read:\n     \"Drop coins here to receive fresh batteries.\"\n/\n"},
        {{39,},"/Batteries\n/There are fresh batteries here.\n/Some worn-out batteries have been discarded nearby.\n/\n"},
        {{50,},"/Large gold nugget\n/There is a large sparkling nugget of gold here!\n/\n"},
        {{56,},"/Golden eggs\n/There is a large nest here, full of golden eggs!\n/The nest of golden eggs has vanished!\n/Done!\n/\n"},
        {{57,},"/Jeweled trident\n/There is a jewel-encrusted trident here!\n/\n"},
        {{59,},"/Egg-sized emerald\n/There is an emerald here the size of a plover's egg!\n/\n"},
        {{60,},"/Platinum pyramid\n/There is a platinum pyramid here, 8 inches on a side!\n/\n"},
        {{61,},"/Glistening pearl\n/Off to one side lies a glistening pearl!\n/\n"},
        {{62,},"/Persian rug\n/There is a persian rug spread out on the floor!\n/The dragon is sprawled out on a persian rug!!\n/\n"},
        {{64,},"/Golden chain\n/There is a golden chain lying in a heap on the floor!\n/The bear is locked to the wall with a golden chain!\n/There is a golden chain locked to the wall!\n/\n"},
};
typedef struct {
    uint8_t number[1];
    char description[OBJ_DESCRIPTIONS_LONG_LENGTH];
} LongObject;
const LongObject longObjects[AMOUNT_OF_OBJ_DESCRIPTIONS_LONG] PROGMEM = {
        {{31,},"/*Dragon\n/A huge green fierce dragon bars the way!\n/Congratulations!  You have just vanquished a dragon with\nyour bare hands!  (Unbelievable, Isn't it?)\n/The body of a huge green dead dragon is lying off to one\nside.\n/\n"},
        {{32,},"/*Chasm\n/A rickety wooden bridge extends across the chasm, vanishing\ninto the mist.  A sign posted on the bridge reads:\n          \"Stop!  Pay Troll!\"\n/The wreckage of a bridge (and a dead bear) can be seen\nat the bottom of the chasm.\n/\n"},
        {{33,},"/*Troll\n/A burly troll stands by the bridge and insists you throw\nhim a treasure before you may cross.\n/The troll steps out from beneath the bridge and blocks\nyour way.\n//\n"},
        {{35,},"//There is a ferocious cave bear eyeing you from the far\nend of the room!\n/There is a gentle cave bear sitting placidly in one corner.\n/There is a contented-looking bear wandering about nearby.\n//\n"},
        {{36,},"/*Message in second maze\n/There is a message scrawled in the dust in a flowery script,\nreading:\n           \"This is not the maze where the\"\n           \"pirate leaves his treasure chest\"\n/\n"},
        {{58,},"/Ming vase\n/There is a delicate, precious, ming vase here!\n/The vase is now resting, delicately, on a velvet pillow.\n/The floor is littered with worthless shards of pottery.\n/The ming vase drops with a delicate crash.\n/\n"},
};
const char longObject24[438]PROGMEM = "/*Plant\n/There is a tiny little plant in the pit, murmuring\n\"Water, Water, ...\"\n/The plant spurts into furious growth for a few seconds.\n/There is a 12-foot-tall beanstalk stretching up out of\nthe pit, bellowing \"Water!! Water!!\"\n/The plant grows explosively, almost filling the bottom\nof the pit. \n/There is a gigantic beanstalk stretching all the way\nup to the hole.\n/You've over-watered the plant!  It's shriveling up!\nIt's, It's...\n/\n";

char * getObject(uint8_t objectNumber)  {
    char * stringToReturn = NULL;

    if (objectNumber == 24) {
        stringToReturn = (char *) malloc(438);
        strcpy_P(stringToReturn, longObject24);
        return stringToReturn;
    }

    stringToReturn = stringRepository->loadStringFromFile(&(TextFile) {
            .entries = (void *) smallObjects,
            .maxLengthOfStrings = OBJ_DESCRIPTIONS_SMALL_LENGTH,
            .sizeOfIndexArray = 1,
            .amountOfEntries = AMOUNT_OF_OBJ_DESCRIPTIONS_SMALL,
    }, stringStorage, objectNumber);

    if (stringToReturn == NULL) {
        stringToReturn = stringRepository->loadStringFromFile(&(TextFile) {
                .entries = (void *) mediumObjects,
                .maxLengthOfStrings = OBJ_DESCRIPTIONS_MEDIUM_LENGTH,
                .sizeOfIndexArray = 1,
                .amountOfEntries = AMOUNT_OF_OBJ_DESCRIPTIONS_MEDIUM,
        }, stringStorage, objectNumber);
    }
    if (stringToReturn == NULL) {
        stringToReturn = stringRepository->loadStringFromFile(&(TextFile) {
                .entries = (void *) longObjects,
                .maxLengthOfStrings = OBJ_DESCRIPTIONS_LONG_LENGTH,
                .sizeOfIndexArray = 1,
                .amountOfEntries = AMOUNT_OF_OBJ_DESCRIPTIONS_LONG,
        }, stringStorage, objectNumber);
    }

    return stringToReturn;
}