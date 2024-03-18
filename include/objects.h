#ifndef COLOSSAL_CAVE_ADVENTURE_OBJECTS_H
#define COLOSSAL_CAVE_ADVENTURE_OBJECTS_H


#define OBJECT_1_STRING_LENGTH 74
#define OBJECT_2_STRING_LENGTH 117
#define OBJECT_3_STRING_LENGTH 199
#define OBJECT_4_STRING_LENGTH 246
#define AMOUNT_OBJECT_1_STRINGS 25
#define AMOUNT_OBJECT_2_STRINGS 15
#define AMOUNT_OBJECT_3_STRINGS 9
#define AMOUNT_OBJECT_4_STRINGS 4
#define OBJECT_1_INDEX_ARRAY_SIZE 1
#define OBJECT_2_INDEX_ARRAY_SIZE 1
#define OBJECT_3_INDEX_ARRAY_SIZE 1
#define OBJECT_4_INDEX_ARRAY_SIZE 1

#define LOAD_FROM(NUM) \
	stringToReturn = helper->loadFarStringFromFile(&(FarTextFile) { \
		.farPointer = pgm_get_far_address(objects_##NUM), \
		.maxLengthOfStrings = OBJECT_##NUM##_STRING_LENGTH, \
		.sizeOfIndexArray = OBJECT_##NUM##_INDEX_ARRAY_SIZE, \
		.amountOfEntries = AMOUNT_OBJECT_##NUM##_STRINGS, \
	}, objectNumber); \
	if (stringToReturn != NULL) { return stringToReturn; }

#endif //COLOSSAL_CAVE_ADVENTURE_OBJECTS_H
