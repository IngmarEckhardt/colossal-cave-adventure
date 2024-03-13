#ifndef COLOSSAL_CAVE_ADVENTURE_OBJECTS_H
#define COLOSSAL_CAVE_ADVENTURE_OBJECTS_H

#define OBJECT_DESCRIPTION_1_LENGTH 73
#define OBJECT_DESCRIPTION_2_LENGTH 113
#define OBJECT_DESCRIPTION_3_LENGTH 197
#define OBJECT_DESCRIPTION_4_LENGTH 247
#define AMOUNT_OF_OBJECT_DESCRIPTIONS_1 25
#define AMOUNT_OF_OBJECT_DESCRIPTIONS_2 15
#define AMOUNT_OF_OBJECT_DESCRIPTIONS_3 9
#define AMOUNT_OF_OBJECT_DESCRIPTIONS_4 4
#define MAX_AMOUNT_OF_OBJECT_DESCRIPTIONS_1_WITH_SAME_LENGTH 1
#define MAX_AMOUNT_OF_OBJECT_DESCRIPTIONS_2_WITH_SAME_LENGTH 1
#define MAX_AMOUNT_OF_OBJECT_DESCRIPTIONS_3_WITH_SAME_LENGTH 1
#define MAX_AMOUNT_OF_OBJECT_DESCRIPTIONS_4_WITH_SAME_LENGTH 1
#ifndef CCA_TEST
#define LOAD_FROM(NUM) \
    stringToReturn = stringRepository->loadStringFromFile(&(TextFile) { \
        .farPointer = pgm_get_far_address(objects_##NUM), \
        .maxLengthOfStrings = OBJECT_DESCRIPTION_##NUM##_LENGTH, \
        .sizeOfIndexArray = MAX_AMOUNT_OF_OBJECT_DESCRIPTIONS_##NUM##_WITH_SAME_LENGTH, \
        .amountOfEntries = AMOUNT_OF_OBJECT_DESCRIPTIONS_##NUM, \
    }, flashHelper, objectNumber); \
    if (stringToReturn != NULL) { return stringToReturn; }

#else
#define LOAD_FROM(NUM) \
    stringToReturn = stringRepository->loadStringFromFile(&(TextFile) { \
        .farPointer = (uint32_t) (objects_##NUM), \
        .maxLengthOfStrings = OBJECT_DESCRIPTION_##NUM##_LENGTH, \
        .sizeOfIndexArray = MAX_AMOUNT_OF_OBJECT_DESCRIPTIONS_##NUM##_WITH_SAME_LENGTH, \
        .amountOfEntries = AMOUNT_OF_OBJECT_DESCRIPTIONS_##NUM, \
    }, flashHelper, objectNumber); \
    if (stringToReturn != NULL) { return stringToReturn; }
#endif
#endif //COLOSSAL_CAVE_ADVENTURE_OBJECTS_H
