#ifndef CAVES_H
#define CAVES_H
#include <stdint.h>
#include <string_repository.h>

char * getCave(StringRepository * stringRepository, FlashHelper * flashHelper, uint8_t caveNumber);

#endif //CAVES_H
