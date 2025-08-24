#include <stdio.h>
#include <math.h>
#include "SQUARE_H.h"

const double e = 1.0e-10;
const int ONE = 1;
const int TWO = 2;
const int NO = 0;
const int INF = -1;

int isEqual (double smpl_a, double smpl_b)
{
 if (fabs(smpl_a - smpl_b)<e)
    return 1;
 else
 {
    return 0;
 }
}

double disc (double kfA, double kfB,  double kfC)
{
    double D = (kfB * kfB) - (4 * kfA * kfC);
    return D;
}

int solveLinearEquation (double b, double c, double *x1)
{
    if (isEqual(b, 0)) {
        if (isEqual(c, 0)) {
            return INF;
        }
        else {
            return NO;
        }
    }
    if (isEqual(c,0)) {
        *x1=0;
        return ONE;
    } else if (!(isEqual(b, 0)) && !(isEqual(c, 0))) {
    *x1 = -c/b;
    return ONE;
    }
    return NO;
}

int solveSquareEquation (double a, double b, double c, double *x1, double *x2)
{
    if (isEqual(a,0)) {
        return solveLinearEquation (b, c, x1);
    }

    if (isEqual(b,0)) {
        if (isEqual(c, 0)) {
            *x1 = 0;
            return ONE;
        } else if (c/a < 0) {
            *x1 = -sqrt(-c/a);
            *x2 = sqrt(-c/a);
            return TWO;
        } else if (a/c > 0) {
            return NO;
        }

    }
        double d = sqrt(disc(a,b,c));
         if (d>0) {
             *x1 = (-b-d)/(2*a);
             *x2 = (-b+d)/(2*a);
             return TWO;
            } if (isEqual(d,0)) {
                *x1 = -b/(2*a);
                *x2 = NAN;
                return ONE;
            } else {
             return NO;
             }
}
