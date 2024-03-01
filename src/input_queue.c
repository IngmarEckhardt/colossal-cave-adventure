#include "input_queue.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

InputQueue * inputQueue;

void enqueue(uint8_t item);

uint8_t dequeue(void);

void resize(void);

//void print_queue(void);

InputQueue * cca_initInputQueue(uint8_t initSize) {
    InputQueue * queue = malloc(sizeof(InputQueue));
    if (queue == NULL) { return NULL; }
    else {
        queue->front = 0;
        queue->rear = 0;
        queue->size = initSize;
        queue->buffer = malloc(initSize * sizeof(uint8_t));
        queue->buffer[0] = '\0';
        queue->enqueue = enqueue;
        queue->dequeue = dequeue;
        queue->resize = resize;
        inputQueue = queue;
        return queue;
    }
}

void enqueue(uint8_t item) {
    inputQueue->buffer[inputQueue->rear] = item;

    uint8_t nextRear = (inputQueue->rear + 1) % inputQueue->size;
    if (nextRear == inputQueue->front) {
        inputQueue->resize();
        nextRear = (inputQueue->rear + 1) % inputQueue->size;
    }
    inputQueue->rear = nextRear;

}

uint8_t dequeue(void) {
    if (inputQueue->front == inputQueue->rear) { return 0; }
    uint8_t item = inputQueue->buffer[inputQueue->front];
    inputQueue->front = (inputQueue->front + 1) % inputQueue->size;

    return item;
}

void resize(void) {
    if (inputQueue->size >= UINT8_MAX / 2) {
        return; // Prevent overflow (size * 2 > UINT8_MAX
    }
    uint8_t newSize = inputQueue->size * 2;

    uint8_t * newBuffer = realloc(inputQueue->buffer, newSize * sizeof(uint8_t));
    if (newBuffer == NULL) { return; }

    if (inputQueue->front > 0) {
        uint8_t amountOfBytesToMove = inputQueue->size - inputQueue->front;
        uint8_t newFront = (inputQueue->size + inputQueue->front);
        memcpy(newBuffer + newFront,
               inputQueue->buffer + inputQueue->front,
               amountOfBytesToMove);
        inputQueue->front = newFront;

    }
    inputQueue->size = newSize;
    free(inputQueue->buffer);
    inputQueue->buffer = newBuffer;
}