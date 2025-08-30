#include <stdio.h>
#include <math.h>
#include <string.h>


#include "square.h"
#include "testing.h"
#include "output.h"
#include "parser.h"

int main (void)
{
    if (!allTests()) {                                           // NOTE - хотелось бы по названию понимать что все ок
        bool isExit = false;                                      //TODO - isExit / exitFlag
        double a, b, c, x1, x2 = NAN;
        do {
            isExit = parser(&a, &b, &c);

            if (isExit) break;

            output(a, b, c, &x1, &x2);
        } while (!isExit);

    } else {
        printf("Error test N%d", allTests());
        return 0;
    }
}







