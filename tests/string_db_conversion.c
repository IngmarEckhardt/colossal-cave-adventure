#include <unity.h>
#include <stdlib.h>

#include "_include/advent1.h"
#include "_include/advent2.h"
#include "_include/advent3.h"
#include "_include/advent4.h"
#include "_include/advcave.h"
#include <pgm_textfile_generator.h>
#include <objects.h>
#include <actions.h>
#include <long_locations.h>
#include <short_locations.h>
#include <caves.h>




void setUp(void) {}
void tearDown(void) {}
void convertAdvent(void) {
    convertTextArrayToProgMemTextFiles(adventtxt1, 140, (uint16_t[]) {72, 140, 195, 320, 520}, 5, "LONG_LOCATION");
    convertTextArrayToProgMemTextFiles(adventtxt2, 140, (uint16_t[]) {15, 30, 55, 75, 186}, 5, "SHORT_LOCATION");
    convertTextArrayToProgMemTextFiles(cave, 140, (uint16_t[]) {15, 30, 55, 75, 186}, 5, "CAVE");
    convertTextArrayToProgMemTextFiles(adventtxt3, 65, (uint16_t[]) {72, 112,  196, 246}, 4, "OBJECT");
    convertTextArrayToProgMemTextFiles(adventtxt4, 201, (uint16_t[]) {13,31, 62, 100, 156, 320, 520}, 7, "ACTION");
}

void test_convertAdvent(void) {
    char * result;
    StringRepository * stringRepository = dOS_initStringRepository(0);
    FlashHelper * flashHelper = dOS_initFlashHelper();
    for (int i = 0; i < 140; i++) {
        result = getLongLocation(stringRepository, flashHelper,i+1);
        TEST_ASSERT_EQUAL_STRING(adventtxt1[i], result);
        free(result);
    }
    for (int i = 0; i < 140; i++) {
        result = getShortLocation(stringRepository, flashHelper,i+1);
        TEST_ASSERT_EQUAL_STRING(adventtxt2[i], result);
        free(result);
    }
    for (int i = 0; i < 64; i++) {
        result = getObject(stringRepository, flashHelper,i+1);
        TEST_ASSERT_EQUAL_STRING(adventtxt3[i], result);
        free(result);
    }
    for (int i = 0; i < 201; i++) {
        result = getAction(stringRepository, flashHelper,i+1);
        TEST_ASSERT_EQUAL_STRING(adventtxt4[i], result);
        free(result);
    }
    for (int i = 0; i < 140; i++) {
        result = getCave(stringRepository, flashHelper,i+1);
        TEST_ASSERT_EQUAL_STRING(cave[i], result);
        free(result);
    }
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(convertAdvent);
    RUN_TEST(test_convertAdvent);

    return UNITY_END();
}