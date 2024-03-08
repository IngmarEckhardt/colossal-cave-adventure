#ifndef CCA_HELPER_H
#define CCA_HELPER_H
#include <string_repository.h>
#include <uart_helper.h>
#include <input_queue.h>
#include <mcu_clock.h>
#include <heap_management_helper.h>


InputQueue * inputQueue;
StringRepository * stringRepository;
StringStorage * stringStorage;
UartHelper * uartHelper;
McuClock * mcuClock;
HeapManagementHelper * heapHelper;

extern volatile uint8_t cca_adjustCounter;
void adjustTo1Sec(void);
void putIntoQueue(uint8_t item);




#endif //CCA_HELPER_H
