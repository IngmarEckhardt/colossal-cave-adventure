#ifndef LONG_LOCATIONS_H
#define LONG_LOCATIONS_H
#include <stdint.h>
#include <string_repository.h>

char * getLongLocation(StringRepository * stringRepository, FlashHelper * flashHelper, uint8_t longLocationNumber);

#endif //LONG_LOCATIONS_H
