#include <stdio.h>
#include <math.h>
#include "zero.h"
#include "SQUARE_H.h"


struct testData {
        //char *name; //SEX
        double a, b, c;
        double x1ref, x2ref;
        int numRootsRef;
    };

int OneTest (testData test) {

    double x1, x2 = NAN;
    int numRoots = solveSquareEquation(test.a, test.b, test.c, &x1, &x2);

    if (!(isEqual(x1, test.x1ref)) || !(isEqual(x2, test.x2ref)) || numRoots != test.numRootsRef) {

        if (isEqual(x1, test.x1ref) && !(isEqual(x2, x2)) && numRoots == test.numRootsRef) {
            return 0;
        }

        if (!(isEqual(x1, x1)) && !(isEqual(x2, x2)) && numRoots == test.numRootsRef) {
            return 0;
        }
        return 1;
    }
    return 0;

}


int allTests (void) {

    testData TASKS[] = {{.a= 1, .b = -3, .c = 2, .x1ref = 1, .x2ref = 2, .numRootsRef = 2},
                        {.a= 0, .b = 0, .c = 0, .x1ref = NAN, .x2ref = NAN, .numRootsRef = -1},
                        {.a= 426, .b = -386808, .c = 53928192, .x1ref = 172, .x2ref = 736, .numRootsRef = 2},
                        {.a= 1, .b = 0, .c = 0, .x1ref = 0, .x2ref = NAN, .numRootsRef = 1},
                        {.a= 1, .b = 3, .c = -4, .x1ref = -4, .x2ref = 1, .numRootsRef = 2},
                        {.a= 1, .b = -13, .c = 12, .x1ref = 1, .x2ref = 12, .numRootsRef = 2},
                        {.a= 0, .b = 36, .c = -54, .x1ref = 1.5, .x2ref = NAN, .numRootsRef = 1},
                        {.a= 34, .b = -51952, .c = 19845664, .x1ref = 764, .x2ref = NAN, .numRootsRef = 1},
                        };

    int TASKI = sizeof(TASKS)/sizeof(TASKS[0]);

    for (int i = 0; i < TASKI; i++) {
        int numTest = OneTest (TASKS[i]);
        if (numTest != 0) {
            printf("Failed test N%d\n", i);
            return 1;
        } else return 0;
    }
    return 0;
}
