
#ifndef COLOSSAL_CAVE_ADVENTURE_INPUTQUEUE_H
#define COLOSSAL_CAVE_ADVENTURE_INPUTQUEUE_H

#include <stdint.h>

typedef struct {
    uint8_t front;
    uint8_t rear;
    uint8_t size;
    uint8_t * buffer;

    void (* enqueue)(uint8_t item);
    uint8_t (* dequeue)(void);
    void (* resize)(void);
} InputQueue;

InputQueue * cca_initInputQueue(uint8_t initSize);

#endif //COLOSSAL_CAVE_ADVENTURE_INPUTQUEUE_H
