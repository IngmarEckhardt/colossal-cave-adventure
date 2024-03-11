#ifndef OBJECTS_H
#define OBJECTS_H
#include <stdint.h>
#include <string_repository.h>

char * getObject(StringRepository * stringRepository, FlashHelper * flashHelper, uint8_t objectNumber);

#endif //OBJECTS_H
