/* advent.c */
#ifndef ADVENT_PROTO_H_
#define ADVENT_PROTO_H_

/* init_adventure.c */
void initplay(void);

/* colossal_cave_adventure.c */
void printToSerialOutput(void);
void adjustTo1Sec(void);
void setupAdvent(void);

/* database.c */
void getRoutingInfos(int location);
int yesOrNoQuestion(int question, int yesReactionMsg, int noReactionMsg);
void speakReaction(int actionMsgNumber);
void printItemMessage(int item, int state);
void describeLongLocation(int location);
void describeShortLocation(int location);
int lookUpVocabulary(char * word, int minValue);
int searchWordIndex(char * w, int amountToSearchThrough);
int dark(void);
int here(int item);
int isInInventory(int item);
int isForcingAMove(int location);
int isRandomlyTrue(int percentageOfTrueAnswers);
int isOnEitherSideOfTwoSidedObject(int objectToInvestigate);
void destroy(int object);
void move(int obj, int where);
void juggle(int loc);
void carry(int obj, int where);
void drop(int obj, int where);
int put(int obj, int where, int pval);
int dcheck(void);
int liq(void);
int liqloc(int loc);
int liq2(int pbottle);
void bug(int n);

/* english.c */
int parseSimpleEnglish(void);
int computeTypeAndValue(char * word, int * type, int * value);
void parseFirstTwoWordsFromStdIn(void);
void printMotionAndVerbWords(void);

/* intransitiveVerb.c */
void intransitiveVerb(void);
void ivTake(void);
void ivOpen(void);
void ivKill(void);
void ivEat(void);
void ivDrink(void);
void ivQuit(void);
void ivFill(void);
void ivFoo(void);
void ivInventory(void);
void addObjectIntransitiv(int object);

/* turn.c */
void turn(void);
void describeLocation(void);
void describeItem(void);
void doMove(void);
void processReturnRequest(void);
void copyTravelInfo(TravelInfo * trav1, TravelInfo * trav2);
void processTravel(void);
void reactToBadMove(void);
void processSpecialMovements(int rdest);
void dwarfEnd(void);
void normalEnd(void);
void calcScore(void);
void processPlayerDeath(void);
void processActualObject(void);
void processTransitionOfReferredObject(void);
char * searchObjStringInBothWords(int object);
void processDwarves(void);
void processPirating(void);
int processTimeLimits(void);

/* verb.c */
void transitiveVerb(void);
void tvTake(void);
void tvDrop(void);
void tvOpen(void);
void tvSay(void);
void tvOn(void);
void tvOff(void);
void tvWave(void);
void tvKill(void);
void tvPour(void);
void tvEat(void);
void tvDrink(void);
void tvThrow(void);
void tvFind(void);
void tvFill(void);
void tvFeed(void);
void tvRead(void);
void tvBlast(void);
void tvBreak(void);
void tvWake(void);
void speakDefaultAnswerTo(int verb);
void needObject(void);

/* program memory getters */
char * getCave(int caveNumber);
char * getAction(int actionNumber);
char * getLongLocation(int longLocationNumber);
char * getObject(int objectNumber);
char * getShortLocation(int shortLocationNumber);

/* wordtable make sure it is placed isOnEitherSideOfTwoSidedObject the beginning of the progmem data section, because it uses the 16bit address room*/
char * getWord(unsigned int indexInWordCodeTable);
unsigned int getCode(unsigned int indexInWordCodeTable);
int compareWord(const char * string, unsigned int index);

#endif /* ADVENT_PROTO_H_ */
