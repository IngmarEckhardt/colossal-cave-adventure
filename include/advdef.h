/*	header ADVDEF.H						*\
\*	WARNING: GLOBAL variable allocations for adventure	*/

/*
	Database variables
*/
TravelInfo locationRoutingInfos[MAXTRAV];

uint8_t actmsg[32]; /* action messages	*/

/*
	English variables
*/
int actualVerb, actualObject, actualMotion;
char word1[WORDSIZE], word2[WORDSIZE];

/*
	Play variables
*/
int turns;
int actualLocation, oldLocation, oldLocation2, newLocation; /* location variables */
uint8_t locationStatus[MAXLOC];		  /* location status	*/
uint8_t objectLocation[MAXOBJ];		  /* object location	*/
uint8_t secondObjectLocation[MAXOBJ];		  /* second object location	*/
uint8_t amountOfVisits[MAXLOC];		  /* >0 if has been here	*/
int stateOfObject[MAXOBJ];		  /* status of object	*/
int tally, tally2;		  /* item counts		*/
int timeLimit;			  /* time timeLimit		*/
int lampWarningFlag;			  /* lamp warning flag	*/
uint8_t locationIsDark;
int caveIsClosing, caveIsClosed;      /* game state flags	*/
uint8_t countItemsHeld;			  /* count of held items	*/
uint8_t lookCount;			  /* LOOK count		*/
uint8_t knifeLocation;			  /* knife location	*/
int8_t clock1, clock2, panic;	  /* timing variables	*/
uint8_t dwarfLocations[DWARFMAX];		  /* dwarf locations	*/
uint8_t dwarfFlag;			  /* dwarf flag		*/
uint8_t dwarfSawThePlayer[DWARFMAX];		  /* dwarf seen flag	*/
uint8_t oldLocationOfDwarf[DWARFMAX];		  /* dwarf old locations	*/
const uint8_t dwarfAltLocation = 18;;			  /* alternate appearance	*/
int amountDwarfKills;			  /* dwarves killed	*/
const uint8_t chestLocation = 114; ;/* chest locations	*/
const uint8_t chestLocation2 = 140;

int bonus;			  /* to pass to end	*/
int numberOfDeaths;			  /* number of deaths	*/
int alternativeObject;			  /* to help intrans.	*/
int playerWantToQuitFlag;			  /* 1 if he quit early	*/
int foobar;			  /* fie fie foe foo...	*/
int debugFlag;			  /* if game is in debug	*/
