#ifndef COLOSSAL_CAVE_ADVENTURE_LONG_LOCATIONS_H
#define COLOSSAL_CAVE_ADVENTURE_LONG_LOCATIONS_H

#define LONG_LOCATION_1_STRING_LENGTH 76
#define LONG_LOCATION_2_STRING_LENGTH 142
#define LONG_LOCATION_3_STRING_LENGTH 200
#define LONG_LOCATION_4_STRING_LENGTH 317
#define LONG_LOCATION_5_STRING_LENGTH 516
#define AMOUNT_LONG_LOCATION_1_STRINGS 45
#define AMOUNT_LONG_LOCATION_2_STRINGS 30
#define AMOUNT_LONG_LOCATION_3_STRINGS 18
#define AMOUNT_LONG_LOCATION_4_STRINGS 12
#define AMOUNT_LONG_LOCATION_5_STRINGS 7
#define LONG_LOCATION_1_INDEX_ARRAY_SIZE 14
#define LONG_LOCATION_2_INDEX_ARRAY_SIZE 1
#define LONG_LOCATION_3_INDEX_ARRAY_SIZE 1
#define LONG_LOCATION_4_INDEX_ARRAY_SIZE 1
#define LONG_LOCATION_5_INDEX_ARRAY_SIZE 1

#define LOAD_FROM(NUM) \
	stringToReturn = helper->loadFarStringFromFile(&(FarTextFile) { \
		.farPointer = pgm_get_far_address(longLocations_##NUM), \
		.maxLengthOfStrings = LONG_LOCATION_##NUM##_STRING_LENGTH, \
		.sizeOfIndexArray = LONG_LOCATION_##NUM##_INDEX_ARRAY_SIZE, \
		.amountOfEntries = AMOUNT_LONG_LOCATION_##NUM##_STRINGS, \
	}, longLocationNumber); \
	if (stringToReturn != NULL) { return stringToReturn; }

#endif //COLOSSAL_CAVE_ADVENTURE_LONG_LOCATIONS_H
