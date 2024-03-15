
/*	program ENGLISH.C					*\
\*	WARNING: "advent.c" allocates GLOBAL storage space by	*\
\*		including "advdef.h".				*\
\*		All other modules use "advdec.h".		*/

#include <stdio.h> /* drv = 1.1st file 2.def 3.A	*/
#include <ctype.h>
#include <stdlib.h>
#include <avr/pgmspace.h>

#include "advent.h"
#include "advdec.h"

#define ENGLISH_HELPER_STRING_LENGTH 31
const __attribute__((__progmem__)) char englishHelperStrings[4][ENGLISH_HELPER_STRING_LENGTH] = {
        "bad grammar...", "WORD1 = ", ", WORD2 = ", "\n\007Enter <RETURN> to continue\n\n"
};

static char * getString(int n) {
    char * stringToReturn = malloc(ENGLISH_HELPER_STRING_LENGTH);
    if (stringToReturn == NULL) { bug(4); }
    switch (n) {
        case 0: {
            flashHelper->loadFarStringFromFlash(stringToReturn, pgm_get_far_address(englishHelperStrings[0]));
            break;
        }
        case 1: {
            flashHelper->loadFarStringFromFlash(stringToReturn, pgm_get_far_address(englishHelperStrings[1]));
            break;
        }
        case 2: {
            flashHelper->loadFarStringFromFlash(stringToReturn, pgm_get_far_address(englishHelperStrings[2]));
            break;
        }
        case 3: {
            flashHelper->loadFarStringFromFlash(stringToReturn, pgm_get_far_address(englishHelperStrings[3]));
            break;
        }
        default: {}
    }
    return stringToReturn;
}

/*
	Analyze a two-word sentence
*/
int parseSimpleEnglish(void) {
    int type1, type2, value1, value2;

    actualVerb = actualObject = actualMotion = 0;
    type2 = value2 = -1;
    type1 = value1 = -1;

    parseFirstTwoWordsFromStdIn();

    if (!(*word1)) {
        return 0;
    }            /* ignore whitespace	*/
    if (!computeTypeAndValue(word1, &type1, &value1)) /* check word1	*/
        return 0;            /* didn't know it	*/

    if (type1 == 2 && value1 == SAY) {
        actualVerb = SAY; /* repeat word & act upon if..	*/
        actualObject = 1;
        return 1;
    }

    if (*word2) {
        if (!computeTypeAndValue(word2, &type2, &value2))
            return 0; /* didn't know it	*/
    }

    /* check his grammar */
    if ((type1 == 3) && (type2 == 3) &&
        (value1 == 51) && (value2 == 51)) {
        printMotionAndVerbWords();
        return 0;
    } else if (type1 == 3) {
        speakReaction(value1);
        return 0;
    } else if (type2 == 3) {
        speakReaction(value2);
        return 0;
    } else if (type1 == 0) {
        if (type2 == 0) {
            char * msg = getString(0);
            printf("%s\n", msg);
            free(msg);
            return 0;
        } else
            actualMotion = value1;
    } else if (type2 == 0)
        actualMotion = value2;
    else if (type1 == 1) {
        actualObject = value1;
        if (type2 == 2)
            actualVerb = value2;
        if (type2 == 1) {
            char * msg = getString(0);
            printf("%s\n", msg);
            free(msg);
            return 0;
        }
    } else if (type1 == 2) {
        actualVerb = value1;
        if (type2 == 1)
            actualObject = value2;
        if (type2 == 2) {
            char * msg = getString(0);
            printf("%s\n", msg);
            free(msg);
            return 0;
        }
    } else
        bug(36);
    return 1;
}

/*
		Routine to analyze a word.
*/
int computeTypeAndValue(char * word, int * type, int * value) {
    int wordval, msg;

    /* make sure I understand */
    if ((wordval = lookUpVocabulary(word, 0)) == -1) {
        switch (rand() % 3) {
            case 0:
                msg = 60;
                break;
            case 1:
                msg = 61;
                break;
            default:
                msg = 13;
        }
        speakReaction(msg);
        return 0;
    }

    *type = wordval / 1000;
    *value = wordval % 1000;

    return 1;
}

/*
	retrieve input line (max 80 chars), convert to lower case
	 & rescan for first two words (max. WORDSIZE-1 chars).
*/
void parseFirstTwoWordsFromStdIn(void) {
    char words[80], * wptr;

    fputs("> ", stdout);
    word1[0] = word2[0] = '\0';
    fflush(stdout);
    if (NULL == fgets(words, 80, stdin)) {
        exit(0);
    }
    wptr = words;
    while ((*wptr = tolower(*wptr))) {
        ++wptr;
    }
    sscanf(words, "%19s %19s", word1, word2);
    if (debugFlag) {
        char * msg1 = getString(1);
        char * msg2 = getString(2);
        printf("%s%s%s%s\n",msg1, msg2, word1, word2);
        free(msg1);
        free(msg2);
    }
}

/*
	output adventure word list (motion/0xxx & verb/2xxx) only
	6 words/line pausing at 20th line until keyboard active
*/
void printMotionAndVerbWords(void) {
    int i, j, line;
    char words[80];

    j = line = 0;
    for (i = 0; i < MAXWC; ++i) {
        uint16_t code = getCode(i);
        if ((code < 1000) || ((code < 3000) && (code > 1999))) {

            char * word = getWord(i);
            printf("%-12s", word);
            free(word);

            if ((++j == 6) || (i == MAXWC - 1)) {
                j = 0;
                fputc('\n', stdout);
                if (++line == 20) {
                    line = 0;
                    char * msg = getString(3);
                    printf("%s", msg);
                    fflush(stdout);
                    free(msg);
                    if (NULL == fgets(words, 80, stdin)) {
                        exit(0);
                    }
                }
            }
        }
    }
}