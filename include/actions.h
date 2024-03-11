#ifndef ACTIONS_H
#define ACTIONS_H
#include <stdint.h>
#include <string_repository.h>

char * getAction(StringRepository * stringRepository, FlashHelper * flashHelper, uint8_t actionNumber);

#endif //ACTIONS_H
