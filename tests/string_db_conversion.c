#include <unity.h>
#include <stdlib.h>

#include <advent1.h>
#include <advent2.h>
#include <advent3.h>
#include <advent4.h>
#include <advcave.h>
#include <advword.h>

#include <pgm_textfile_generator.h>

#include <_proto.h>


void setUp(void) {}
void tearDown(void) {}
void convertAdvent(void) {
    convertTextArrayToProgMemTextFiles(adventtxt1, 140, (uint16_t[]) {72, 140, 195, 320, 520}, 5, "LONG_LOCATION");
    convertTextArrayToProgMemTextFiles(adventtxt2, 140, (uint16_t[]) {15, 30, 55, 75, 186}, 5, "SHORT_LOCATION");
    convertTextArrayToProgMemTextFiles(cave, 140, (uint16_t[]) {15, 30, 55, 75, 186}, 5, "CAVE");
    convertTextArrayToProgMemTextFiles(adventtxt3, 65, (uint16_t[]) {72, 112,  196, 246}, 4, "OBJECT");
    convertTextArrayToProgMemTextFiles(adventtxt4, 201, (uint16_t[]) {13,31, 62, 100, 156, 320, 520}, 7, "ACTION");
}

//void test_convertAdvent(void) {
//    char * result;
//
//    for (int i = 0; i < 140; i++) {
//        result = getLongLocation(i+1);
//        TEST_ASSERT_EQUAL_STRING(adventtxt1[i], result);
//        free(result);
//    }
//    for (int i = 0; i < 140; i++) {
//        result = getShortLocation(i+1);
//        TEST_ASSERT_EQUAL_STRING(adventtxt2[i], result);
//        free(result);
//    }
//    for (int i = 0; i < 64; i++) {
//        result = getObject(i+1);
//        TEST_ASSERT_EQUAL_STRING(adventtxt3[i], result);
//        free(result);
//    }
//    for (int i = 0; i < 201; i++) {
//        result = getAction(i+1);
//        TEST_ASSERT_EQUAL_STRING(adventtxt4[i], result);
//        free(result);
//    }
//    for (int i = 0; i < 140; i++) {
//        result = getCave(i+1);
//        TEST_ASSERT_EQUAL_STRING(cave[i], result);
//        free(result);
//    }
//    for (int i = 0; i < 306; i++) {
//        //test if getWord is the same as wc[].aword
//        result = getWord(i);
//        TEST_ASSERT_EQUAL_STRING(wc[i].aword, result);
//        free(result);
//    }
//    for (int i = 0; i < 306; i++) {
//        //test compare String
//        int32_t resultInt = compareWord(wc[i].aword, i);
//        TEST_ASSERT_EQUAL(0, resultInt);
//    }
//    for (int i = 0; i < 306; i++) {
//        //test loadCode
//        uint16_t resultInt = getCode(i);
//        TEST_ASSERT_EQUAL(wc[i].acode, resultInt);
//    }
//}

int main(void) {

    UNITY_BEGIN();
    RUN_TEST(convertAdvent);
//    RUN_TEST(test_convertAdvent);

    return UNITY_END();
}