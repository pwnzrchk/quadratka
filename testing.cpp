#include <stdio.h>
#include <math.h>
#include "square.h"

const int ONE = 1;
const int TWO = 2;
const int NO = 0; //enum
const int INF = -1;

typedef struct {
    double a, b, c;
    double x1ref, x2ref;
    int numRootsRef;
} testData;


int OneTest (testData test) {

    double x1 = NAN, x2 = NAN;
    int mistakes = 0;
    int numRoots = solveSquareEquation(test.a, test.b, test.c, &x1, &x2);

    switch (numRoots) {
        case ONE:
            if (!(isEqual(x1, test.x1ref))) {
                mistakes += 1;
            }
                break;

        case TWO:
            if (!(isEqual(x1, test.x1ref)) || !(isEqual(x2, test.x2ref))) {
                mistakes += 1;
            }
                break;

        case NO:
            if (!(isnan(x1) && isnan(x2))) {
                mistakes += 1;
            }
            break;

        case INF:
            if (!(isnan(x1) && isnan(x2))) {
                mistakes += 1;
            }
            break;

        default: ;

    }
    return mistakes;
}

int allTests (void) {

    testData TASKS[] = { {.a= 1, .b = -3, .c = 2, .x1ref = 1, .x2ref = 2, .numRootsRef = 2},
                        {.a= 0, .b = 0, .c = 0, .x1ref = NAN, .x2ref = NAN, .numRootsRef = -1},
                        {.a= 426, .b = -386808, .c = 53928192, .x1ref = 172, .x2ref = 736, .numRootsRef = 2},
                        {.a= 1, .b = 0, .c = 0, .x1ref = 0, .x2ref = NAN, .numRootsRef = 1},
                        {.a= 1, .b = 3, .c = -4, .x1ref = -4, .x2ref = 1, .numRootsRef = 2},
                        {.a= 1, .b = -13, .c = 12, .x1ref = 1, .x2ref = 12, .numRootsRef = 2},
                        {.a= 0, .b = 36, .c = -54, .x1ref = 1.5, .x2ref = NAN, .numRootsRef = 1},
                        {.a= 34, .b = -51952, .c = 19845664, .x1ref = 764, .x2ref = NAN, .numRootsRef = 1},
                        {.a= 34, .b = 51952, .c = 19845664, .x1ref = -764, .x2ref = NAN, .numRootsRef = 1},
                        {.a = 1,  .b = -3, .c = 2, .x1ref = 1, .x2ref = 2, .numRootsRef = 2},
                        {.a = 2,  .b = -9, .c = -5, .x1ref = -0.5, .x2ref = 5, .numRootsRef = 2},
                        {.a = 1,  .b = 0,  .c = -4, .x1ref = -2, .x2ref = 2,  .numRootsRef = 2},
                        {.a = 1,  .b = -6, .c = 9, .x1ref = 3, .x2ref = NAN, .numRootsRef = 1},
                        {.a = 5,  .b = 0,  .c = 10, .x1ref = NAN, .x2ref = NAN, .numRootsRef = 0},
                        {.a = 0,  .b = 2,  .c = -8, .x1ref = 4, .x2ref = NAN, .numRootsRef = 1},
                        {.a = 0,  .b = 5,  .c = 0, .x1ref = 0, .x2ref = NAN, .numRootsRef = 1},
                        {.a = 0,  .b = 0,  .c = 0, .x1ref = NAN, .x2ref = NAN, .numRootsRef = -1},
                        {.a = 0,  .b = 0,  .c = 5, .x1ref = NAN, .x2ref = NAN, .numRootsRef = 0},
                        {.a = 1,  .b = -1, .c = 0, .x1ref = 0, .x2ref = 1, .numRootsRef = 2},
                        {.a = 1,  .b = 1,  .c = -1, .x1ref = -1.6180339887, .x2ref = 0.6180339887, .numRootsRef = 2}
                        };

    int TASKI = sizeof(TASKS)/sizeof(TASKS[0]);

    for (int i = 0; i < TASKI; i++) {

        if (OneTest (TASKS[i]) != 0) {
            printf("Failed test N%d\n", i);
            return 1;
        }
    }
    return 0;
}
