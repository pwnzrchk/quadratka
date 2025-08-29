#include <stdio.h>
#include <math.h>
#include <string.h>


#include "square.h"
#include "testing.h"
#include "output.h"

int main (void)
{
    if (!allTests()) {                                           // NOTE - хотелось бы по названию понимать что все ок
        bool isExit = false;                                      //TODO - isExit / exitFlag
        char exitFlag[100];

        do {
            double a, b, c, x1, x2 = NAN;

            printf ("Введите коэффициенты квадратного уравнения a, b и c \n");
            if (scanf ("%lf %lf %lf", &a, &b, &c) != 3) {
                printf("Error input\n");
                return 0;
            }
            else
                output(a, b, c, &x1, &x2);                       //LINK - я не понимаю из названия то это делает
                printf("Введите \"exit\" для выхода, или что-то другое для продолжения\n");
                scanf("%99s", exitFlag);
                if (!(strcmp(exitFlag, "exit"))) {
                    isExit = true;
                }
            } while (!isExit);
        return 0;
    }
    else {
        printf("Error test N%d", allTests());
        return 0;
    }
}







