#ifndef COLOSSAL_CAVE_ADVENTURE_CAVES_H
#define COLOSSAL_CAVE_ADVENTURE_CAVES_H



#define CAVE_DESCRIPTION_1_LENGTH 16
#define CAVE_DESCRIPTION_2_LENGTH 31
#define CAVE_DESCRIPTION_3_LENGTH 56
#define CAVE_DESCRIPTION_4_LENGTH 76
#define CAVE_DESCRIPTION_5_LENGTH 187
#define AMOUNT_OF_CAVE_DESCRIPTIONS_1 14
#define AMOUNT_OF_CAVE_DESCRIPTIONS_2 44
#define AMOUNT_OF_CAVE_DESCRIPTIONS_3 31
#define AMOUNT_OF_CAVE_DESCRIPTIONS_4 18
#define AMOUNT_OF_CAVE_DESCRIPTIONS_5 32
#define MAX_AMOUNT_OF_CAVE_DESCRIPTIONS_1_WITH_SAME_LENGTH 2
#define MAX_AMOUNT_OF_CAVE_DESCRIPTIONS_2_WITH_SAME_LENGTH 1
#define MAX_AMOUNT_OF_CAVE_DESCRIPTIONS_3_WITH_SAME_LENGTH 1
#define MAX_AMOUNT_OF_CAVE_DESCRIPTIONS_4_WITH_SAME_LENGTH 1
#define MAX_AMOUNT_OF_CAVE_DESCRIPTIONS_5_WITH_SAME_LENGTH 1

#ifndef CCA_TEST
#define LOAD_FROM(NUM) \
    stringToReturn = stringRepository->loadStringFromFile(&(TextFile) { \
        .farPointer = pgm_get_far_address(caves_##NUM), \
        .maxLengthOfStrings = CAVE_DESCRIPTION_##NUM##_LENGTH, \
        .sizeOfIndexArray = MAX_AMOUNT_OF_CAVE_DESCRIPTIONS_##NUM##_WITH_SAME_LENGTH, \
        .amountOfEntries = AMOUNT_OF_CAVE_DESCRIPTIONS_##NUM, \
    }, flashHelper, caveNumber); \
    if (stringToReturn != NULL) { return stringToReturn; }

#else
#define LOAD_FROM(NUM) \
    stringToReturn = stringRepository->loadStringFromFile(&(TextFile) { \
        .farPointer = (uint32_t) (caves_##NUM), \
        .maxLengthOfStrings = CAVE_DESCRIPTION_##NUM##_LENGTH, \
        .sizeOfIndexArray = MAX_AMOUNT_OF_CAVE_DESCRIPTIONS_##NUM##_WITH_SAME_LENGTH, \
        .amountOfEntries = AMOUNT_OF_CAVE_DESCRIPTIONS_##NUM, \
    }, flashHelper, caveNumber); \
    if (stringToReturn != NULL) { return stringToReturn; }
#endif

#endif //COLOSSAL_CAVE_ADVENTURE_CAVES_H