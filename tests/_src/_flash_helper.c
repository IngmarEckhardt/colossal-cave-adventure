#include <flash_helper.h>
#include <stdlib.h>
#include <string.h>

// Version of flash_helper without avr libs
char * createStringFromFlash(const char * flashString) {

    char * result = (char *) malloc((strlen(flashString) + 1) * sizeof(char));
    if (result == NULL) { return NULL; }


    strcpy(result, flashString);


    return result;

}
void loadFromFlash(char * stringBuffer, const char * flashString) {
    strcpy(stringBuffer, flashString);
}

void loadFarFromFlash(char * stringBuffer, uint32_t flashString) {
    strcpy(stringBuffer, (const char *) flashString);
}

uint8_t readProgMemByte(const uint8_t * addressOfByte) {
    return *addressOfByte;
}

uint8_t readFarProgMemByte(uint32_t addressOfByte) {
    uint8_t * pointerToInt = (uint8_t *) addressOfByte;

    uint8_t integerToFind = *pointerToInt;
    return integerToFind;
}

int32_t compareWithFlashString(const char * string, const char * flashString) {
    return strcmp(string, flashString);

}
uint16_t readWordNear(const uint16_t * intAdress) {
    return *intAdress;
}

const char initMsgOnFlash[] = " setup complete.\n";
LazyLoadingString initMsg = {.flashString = initMsgOnFlash, .pointerToString = NULL};


FlashHelper * dOS_initFlashHelper(void) {
    FlashHelper * helper = malloc(sizeof(FlashHelper));
    if (helper == NULL) { return NULL; }
    else {
        helper->initMsg = initMsg;
        helper->createStringFromFlash = createStringFromFlash;
        helper->loadStringFromFlash = loadFromFlash;
        helper->loadFarStringFromFlash = loadFarFromFlash;
        helper->readProgMemByte = readProgMemByte;
        helper->readFarProgMemByte = readFarProgMemByte;
        helper->readNearWord = readWordNear;
        helper->compareWithFlashString = compareWithFlashString;
        return helper;
    }
}