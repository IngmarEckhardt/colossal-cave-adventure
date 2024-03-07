#ifndef COLOSSAL_CAVE_ADVENTURE_SETUP_ADVENTURE_H
#define COLOSSAL_CAVE_ADVENTURE_SETUP_ADVENTURE_H

#include "input_queue.h"
volatile uint8_t adjustCounter;

void adjustTo1Sec(void);
void putIntoQueue(uint8_t item);
void setupAdvent(void);
#endif //COLOSSAL_CAVE_ADVENTURE_SETUP_ADVENTURE_H
