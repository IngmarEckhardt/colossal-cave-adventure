#ifndef COLOSSAL_CAVE_ADVENTURE_CAVES_H
#define COLOSSAL_CAVE_ADVENTURE_CAVES_H

#define CAVE_1_STRING_LENGTH 11
#define CAVE_2_STRING_LENGTH 31
#define CAVE_3_STRING_LENGTH 55
#define CAVE_4_STRING_LENGTH 76
#define CAVE_5_STRING_LENGTH 145
#define AMOUNT_CAVE_1_STRINGS 14
#define AMOUNT_CAVE_2_STRINGS 44
#define AMOUNT_CAVE_3_STRINGS 31
#define AMOUNT_CAVE_4_STRINGS 18
#define AMOUNT_CAVE_5_STRINGS 32
#define CAVE_1_INDEX_ARRAY_SIZE 2
#define CAVE_2_INDEX_ARRAY_SIZE 1
#define CAVE_3_INDEX_ARRAY_SIZE 1
#define CAVE_4_INDEX_ARRAY_SIZE 1
#define CAVE_5_INDEX_ARRAY_SIZE 1

#define LOAD_FROM(NUM) \
	stringToReturn = helper->loadFarStringFromFile(&(FarTextFile) { \
		.farPointer = pgm_get_far_address(caves_##NUM), \
		.maxLengthOfStrings = CAVE_##NUM##_STRING_LENGTH, \
		.sizeOfIndexArray = CAVE_##NUM##_INDEX_ARRAY_SIZE, \
		.amountOfEntries = AMOUNT_CAVE_##NUM##_STRINGS, \
	}, caveNumber); \
	if (stringToReturn != NULL) { return stringToReturn; }

#endif //COLOSSAL_CAVE_ADVENTURE_CAVES_H
