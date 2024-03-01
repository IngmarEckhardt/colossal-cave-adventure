#include <unity.h>
#include <input_queue.h>
#include <stdlib.h>

void print_queue2(InputQueue * inputQueue);

void setUp(void) {}

void tearDown(void) {
}

void enqueue_initSizeTwoTwoElements_haveSizeFourThen(void) {
    InputQueue * queue = cca_initInputQueue(2);
    TEST_ASSERT_NOT_NULL(queue);
    queue->enqueue(1);
    queue->enqueue(2);
    TEST_ASSERT_EQUAL(4, queue->size);
    free(queue->buffer);
    free(queue);
}


void enqueue_initSizeUint8MaxHalf_shouldStaySameSizeWithoutError(void) {
    InputQueue * queue = cca_initInputQueue(UINT8_MAX / 2);
    TEST_ASSERT_NOT_NULL(queue);
    for (int i = 0; i < UINT8_MAX - 1; ++i) {
        queue->enqueue(i);
    }
    TEST_ASSERT_EQUAL(UINT8_MAX / 2, queue->size);
    free(queue->buffer);
    free(queue);
}

void test_queue_empty_after_init() {
    InputQueue * queue = cca_initInputQueue(5);
    TEST_ASSERT_NOT_NULL(queue);
    TEST_ASSERT_EQUAL(0, queue->front);
    TEST_ASSERT_EQUAL(0, queue->rear);
    free(queue->buffer);
    free(queue);
}

void test_queue_resize() {
    InputQueue * queue = cca_initInputQueue(2);
    TEST_ASSERT_NOT_NULL(queue);
    queue->enqueue(1);
    queue->enqueue(2);
    queue->enqueue(3);
    TEST_ASSERT_EQUAL(4, queue->size);
    free(queue->buffer);
    free(queue);
}

void test_dequeue() {
    InputQueue * queue = cca_initInputQueue(5);
    TEST_ASSERT_NOT_NULL(queue);
    queue->enqueue(1);
    queue->enqueue(2);
    //first dequeue find always '\0
    queue->dequeue();
    uint8_t item = queue->dequeue();
    TEST_ASSERT_EQUAL(1, item);
    free(queue->buffer);
    free(queue);
}

void test_elements_position_after_resize() {
    InputQueue * queue = cca_initInputQueue(7); // Initialize with a size less than 20
    TEST_ASSERT_NOT_NULL(queue);

    // Enqueue 20 elements
    for (uint8_t i = 0; i < 20; i++) {
        queue->enqueue(i);
    }
    // Check if the elements are in the correct order
    for (uint8_t i = 0; i < 20; i++) {
        print_queue2(queue);
        uint8_t item = queue->dequeue();
        printf("Dequeued item: %d, Expected item: %d\n", item, i);
        TEST_ASSERT_EQUAL(i, item);
    }
    for (uint8_t i = 0; i < 24; i++) {
        queue->enqueue(i);
    }
    // Check if the elements are in the correct order
    for (uint8_t i = 0; i < 24; i++) {

        uint8_t item = queue->dequeue();
        printf("Dequeued item: %d, Expected item: %d\n", item, i);
        TEST_ASSERT_EQUAL(i, item);
    }
    print_queue2(queue);
    for (uint8_t i = 0; i < 44; i++) {
        queue->enqueue(i);
    }
    print_queue2(queue);
    for (uint8_t i = 0; i < 44; i++) {

        uint8_t item = queue->dequeue();
        printf("Dequeued item: %d, Expected item: %d\n", item, i);
        TEST_ASSERT_EQUAL(i, item);
    }

    for (uint8_t i = 0; i < 128; i++) {
        queue->enqueue(i);
    }
    print_queue2(queue);
    for (uint8_t i = 0; i < 128; i++) {

        uint8_t item = queue->dequeue();
        printf("Dequeued item: %d, Expected item: %d\n", item, i);
        TEST_ASSERT_EQUAL(i, item);
    }

    for (uint8_t i = 0; i < 219; i++) {
        queue->enqueue(i);
    }
    print_queue2(queue);
    for (uint8_t i = 0; i < 219; i++) {

        uint8_t item = queue->dequeue();
        printf("Dequeued item: %d, Expected item: %d\n", item, i);
        TEST_ASSERT_EQUAL(i, item);
    }
    print_queue2(queue);
    free(queue->buffer);
    free(queue);
}


int main(void) {
    UNITY_BEGIN();

//    RUN_TEST(enqueue_initSizeTwoTwoElements_haveSizeFourThen);
//    RUN_TEST(enqueue_initSizeUint8MaxHalf_shouldStaySameSizeWithoutError);
//    RUN_TEST(test_queue_empty_after_init);
//    RUN_TEST(test_queue_resize);
//    RUN_TEST(test_dequeue);
    RUN_TEST(test_elements_position_after_resize);


    return UNITY_END();
}

void print_queue2(InputQueue * inputQueue) {
    printf("Front: %d\n", inputQueue->front);
    printf("Rear: %d\n", inputQueue->rear);
    printf("Elements in the queue: ");
    for (uint8_t i = 0; i < inputQueue->size; i++) {
        printf("%d ", inputQueue->buffer[i]);
    }
    printf("\n");
}