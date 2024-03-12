/* advent.c */
#ifndef ADVENT_PROTO_H_
#define ADVENT_PROTO_H_

/* collossal_cave_adventure.c */
void setup(void);
void printToSerialOutput(void);
void scanint    (int *pi, char *str);
void initplay   (void);


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

#endif /* ADVENT_PROTO_H_ */
