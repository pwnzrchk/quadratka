#include <stdio.h>
#include <math.h>
#include "zero.h"
const double e = 1.0e-10;
double zeroing (double a)
{
    if (fabs(a) < e) {
        a = 0;
        return 0;
    } else {
    return a;
    }
}
