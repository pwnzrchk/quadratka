#include <stdio.h>
#include <math.h>
#include "zero.h"

const double e = 1.0e-10;

double zeroing (double a)
{
    return (fabs(a) < e) ? 0 : a;
}
// Makefile
