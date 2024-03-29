#include <stddef.h>
// Setup DwarfOS
#include <setup.h>
#include <input_queue.h>
#include <uart_helper.h>
#include <string_repository.h>

/*	header ADVDEC.H						*\
\*	WARNING: GLOBAL EXTERNAL declarations for adventure	*/
StringRepository * stringRepository;
FlashHelper * flashHelper;
InputQueue * inputQueue;
UartHelper * uartHelper;
McuClock * mcuClock;

volatile uint8_t cca_adjustCounter;

/*
	Database variables
*/

extern TravelInfo locationRoutingInfos[];
extern uint8_t actmsg[]; /* action messages	*/

/*
	English variables
*/
extern int actualVerb, actualObject, actualMotion;
extern char word1[], word2[];

/*
	Play variables
*/
extern int turns;
extern int actualLocation, oldLocation, oldLocation2, newLocation; /* location variables  */
extern uint8_t locationStatus[];			 /* location status	*/
extern uint8_t objectLocation[];			 /* object location	*/
extern uint8_t secondObjectLocation[];			 /* second object location	*/
extern uint8_t amountOfVisits[];			 /* >0 if has been here	*/
extern int stateOfObject[];			 /* status of object	*/
extern int tally, tally2;		 /* item counts		*/
extern int timeLimit;			 /* time timeLimit		*/
extern int lampWarningFlag;			 /* lamp warning flag	*/
extern uint8_t locationIsDark;
extern int caveIsClosing, caveIsClosed;      /* game state flags	*/
extern uint8_t countItemsHeld;			 /* count of held items	*/
extern uint8_t lookCount;			 /* LOOK count		*/
extern uint8_t knifeLocation;			 /* knife location	*/
extern int8_t clock1, clock2, panic;	 /* timing variables	*/
extern uint8_t dwarfLocations[];			 /* dwarf locations	*/
extern uint8_t dwarfFlag;			 /* dwarf flag		*/
extern uint8_t dwarfSawThePlayer[];			 /* dwarf seen flag	*/
extern uint8_t oldLocationOfDwarf[];			 /* dwarf old locations	*/
extern const uint8_t dwarfAltLocation;			 /* alternate appearance*/
extern int amountDwarfKills;			 /* dwarves killed	*/
extern const uint8_t chestLocation, chestLocation2;		 /* chest locations	*/
extern int bonus;			 /* to pass to end	*/
extern int numberOfDeaths;			 /* number of deaths	*/
extern int alternativeObject;			 /* to help intrans.	*/
extern int playerWantToQuitFlag;			 /* 1 if he quit early	*/
extern int foobar;			 /* fie fie foe foo...	*/
extern int debugFlag;			 /* if game is in debug	*/