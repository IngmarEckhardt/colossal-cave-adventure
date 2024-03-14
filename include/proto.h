/* advent.c */
#ifndef ADVENT_PROTO_H_
#define ADVENT_PROTO_H_

/* collossal_cave_adventure.c */
void printToSerialOutput(void);
void scanint    (int *pi, char *str);
void initplay   (void);


/* database.c */
void gettrav (int loc);
int  yes     (int msg1, int msg2, int msg3);
void rspeak  (int msg);
void pspeak  (int item, int state);
void desclg  (int loc);
void descsh  (int loc);
int  vocab   (char *word, int val);
int  binary  (char *w, int maxwc);
int  dark    (void);
int  here    (int item);
int  toting  (int item);
int  forced  (int atloc);
int  pct     (int x);
int  at      (int item);
void dstroy  (int obj);
void move    (int obj, int where);
void juggle  (int loc);
void carry   (int obj, int where);
void drop    (int obj, int where);
int  put     (int obj, int where, int pval);
int  dcheck  (void);
int  liq     (void);
int  liqloc  (int loc);
int  liq2    (int pbottle);
void bug     (int n);

/* english.c */
int  english   (void);
int  analyze   (char *word, int *type, int *value);
void getwords  (void);
void outwords  (void);

/* itverb.c */
void itverb    (void);
void ivtake    (void);
void ivopen    (void);
void ivkill    (void);
void iveat     (void);
void ivdrink   (void);
void ivquit    (void);
void ivfill    (void);
void ivfoo     (void);
void inventory (void);
void addobj    (int obj);

/* turn.c */
void turn     (void);
void describe (void);
void descitem (void);
void domove   (void);
void goback   (void);
void copytrv  (struct trav *trav1, struct trav *trav2);
void dotrav   (void);
void badmove  (void);
void spcmove  (int rdest);
void dwarfend (void);
void normend  (void);
void score    (void);
void death    (void);
void doobj    (void);
void trobj    (void);
char *probj   (int object);
void dwarves  (void);
void dopirate (void);
int  stimer   (void);

/* verb.c */
void trverb (void);
void vtake  (void);
void vdrop  (void);
void vopen  (void);
void vsay   (void);
void von    (void);
void voff   (void);
void vwave  (void);
void vkill  (void);
void vpour  (void);
void veat   (void);
void vdrink (void);
void vthrow (void);
void vfind  (void);
void vfill  (void);
void vfeed  (void);
void vread  (void);
void vblast (void);
void vbreak (void);
void vwake  (void);
void actspk (int verb);
void needobj(void);

/* setup_adventure.c */
void adjustTo1Sec(void);
void putIntoQueue(int item);
void setupAdvent(void);

/* program memory getters */
char * getCave(int caveNumber);
char * getAction(int actionNumber);
char * getLongLocation(int longLocationNumber);
char * getObject(int objectNumber);
char * getShortLocation(int shortLocationNumber);

/* wordtable make sure it is placed at the beginning of the progmem data section, because it uses the 16bit address room*/
char * loadWord(unsigned int index);
unsigned int loadCode(unsigned int index);
int compareWord(const char * string, unsigned int index);
#endif /* ADVENT_PROTO_H_ */
