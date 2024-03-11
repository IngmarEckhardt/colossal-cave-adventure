#include <flash_helper.h>
#include <stdlib.h>
#include <string.h>


char * createStringFromFlash(const char * flashString) {

    char * result = (char *) malloc((strlen(flashString) + 1) * sizeof(char));
    if (result == NULL) { return NULL; }


    strcpy(result, flashString);


    return result;

}
void loadFromFlash(char * stringBuffer, const char * flashString) {
    strcpy(stringBuffer, flashString);
}

uint8_t readProgMemByte(const uint8_t * addressOfByte) {
    return *addressOfByte;
}

const char initMsgOnFlash[] = " setup complete.\n";
LazyLoadingString initMsg = {.flashString = initMsgOnFlash, .pointerToString = NULL};


FlashHelper * dOS_initFlashHelper(void) {
    FlashHelper * helper = malloc(sizeof(FlashHelper));
    if (helper == NULL) { return NULL; }
    else {
        helper->initMsg = initMsg;
        helper->createStringFromFlash = createStringFromFlash;
        helper->loadFromFlash = loadFromFlash;
        helper->readProgMemByte = readProgMemByte;
        return helper;
    }
}