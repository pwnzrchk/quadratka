#ifndef testing
#define testing

#include <stdio.h>
#include <math.h>
#include "square.h"

typedef struct {
    //char *name; //SEX
    double a, b, c;
    double x1ref, x2ref;
    int numRootsRef;
} testData_t;

int OneTest (testData_t test);
int allTests (void);

#endif
