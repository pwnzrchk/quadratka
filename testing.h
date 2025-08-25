#ifndef testing
#define testing

#include <stdio.h>
#include <math.h>
#include "zero.h"
#include "SQUARE_H.h"

typedef struct {
    //char *name; //SEX
    double a, b, c;
    double x1ref, x2ref;
    int numRootsRef;
} testData;

int OneTest (testData test);
int allTests (void);

#endif
