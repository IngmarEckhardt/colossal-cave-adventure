#ifndef SHORT_LOCATIONS_H
#define SHORT_LOCATIONS_H
#include <stdint.h>
#include <string_repository.h>

char * getShortLocation(StringRepository * stringRepository, FlashHelper * flashHelper, uint8_t shortLocationNumber);

#endif //SHORT_LOCATIONS_H
