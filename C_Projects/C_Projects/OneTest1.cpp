#include <stdio.h>
#include <math.h>
int oneTest (double a, double b, double c, double x1ref, double x2ref, double numRootsref);
int RunTest(void);

int oneTest (double a, double b, double c, double x1ref, double x2ref, double numRootsref)
{
    double x1, x2 = NAN;
    int numRoots = 0;

    numRoots = solveSquareEquation(a, b, c, &x1, &x2);

    if (isEqual(numRoots, 2))
    {
        if (!(isEqual(x1, x1ref)) || !(isEqual(x2, x2ref)) || !(isEqual(numRoots, numRootsref))) {
            printf("Error test, x1=%lg, x2=%lg (should be %lg, %lg)\n",x1, x2, x1ref, x2ref);
            return 1;
        }
        return 0;
    }

    if (isEqual(numRoots, 1)) {
        if (!(isEqual(x1, x1ref)) || !(isEqual(numRoots, numRootsref))) {
            printf("Error test, x=%lg (should be %lg)", x1, x1ref);
            return 1;
        }
        return 0;
    }

    if (isEqual(numRoots, 0)) {
        if (!(isEqual(numRoots, numRootsref))) {
            printf("Error test, x1 = %lg, x2 = %lg (must be without roots), nRoots = %d (should be %lg)", x1, x2, numRoots, numRootsref);
            return 1;
        }
        return 0;
        }

    if (isEqual(numRoots, -1)) {
        if (!(isEqual(numRoots, numRootsref))) {
            printf("Error test, x1 = %lg, x2 = %lg (must be infinity quantity of roots), nRoots = %d (should be inf)",
            x1, x2, numRoots);
            return 1;
        }
        return 0;
    }
    return 0;
}


int RunTest() {
    int failed = 0;
    failed += oneTest (1, -5, 6, 2, 3, 2);
    failed += oneTest (1, -5, 4, 1, 4, 2);
    failed += oneTest (1, -3, 2, 1, 2, 2);
    failed += oneTest (1, -7, 12, 3, 4, 2);
    failed += oneTest (1, 3, -4, -4, 1, 2);
    failed += oneTest (1, -13, 12, 1, 12, 2);
    failed += oneTest (1, -2, 1, 1, NAN, 1);
    failed += oneTest (576, 48, 84, NAN, NAN, 0);
    failed += oneTest (-1, 0, 0, 0, NAN, 1);
    return failed;
    }

