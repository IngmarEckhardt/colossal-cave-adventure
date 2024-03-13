#include <input_queue.h>
#include <uart_helper.h>
#include <string_repository.h>

/*	header ADVDEC.H						*\
\*	WARNING: GLOBAL EXTERNAL declarations for adventure	*/


StringRepository * stringRepository;
FlashHelper * flashHelper;
InputQueue * inputQueue;
UartHelper * uartHelper;

volatile uint8_t cca_adjustCounter;
/*
	Database variables
*/
extern struct wac wc[]; /* see ADVWORD.H		*/
//extern char *cave[];    /* see ADVCAVE.H		*/
extern size_t cavesz;



extern struct trav travel[];
extern int actmsg[]; /* action messages	*/

/*
	English variables
*/
extern int verb, object, motion;
extern char word1[], word2[];

/*
	Play variables
*/
extern int turns;
extern int loc, oldloc, oldloc2, newloc; /* location variables  */
extern int cond[];			 /* location status	*/
extern int place[];			 /* object location	*/
extern int fixed[];			 /* second object loc	*/
extern int visited[];			 /* >0 if has been here	*/
extern int prop[];			 /* status of object	*/
extern int tally, tally2;		 /* item counts		*/
extern int limit;			 /* time limit		*/
extern int lmwarn;			 /* lamp warning flag	*/
extern int wzdark, closing, closed;      /* game state flags	*/
extern int holding;			 /* count of held items	*/
extern int detail;			 /* LOOK count		*/
extern int knfloc;			 /* knife location	*/
extern int clock1, clock2, panic;	 /* timing variables	*/
extern int dloc[];			 /* dwarf locations	*/
extern int dflag;			 /* dwarf flag		*/
extern int dseen[];			 /* dwarf seen flag	*/
extern int odloc[];			 /* dwarf old locations	*/
extern int daltloc;			 /* alternate appearance*/
extern int dkill;			 /* dwarves killed	*/
extern int chloc, chloc2;		 /* chest locations	*/
extern int bonus;			 /* to pass to end	*/
extern int numdie;			 /* number of deaths	*/
extern int object1;			 /* to help intrans.	*/
extern int gaveup;			 /* 1 if he quit early	*/
extern int foobar;			 /* fie fie foe foo...	*/
extern int dbugflg;			 /* if game is in debug	*/