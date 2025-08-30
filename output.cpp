#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "square.h"
#include "testing.h"

const int ONE = 1;
const int TWO = 2;
const int NO = 0;
const int INF = -1;


void output(double a, double b, double c, double * x1, double *x2) {

    int accuracy = 0;
    int nRoots = solveSquareEquation(a, b, c, x1, x2);


    isEqual(*x1, 0) ? *x1 = 0 : *x1 = *x1;
    isEqual(*x2, 0) ? *x2 = 0 : *x2 = *x2;

    switch (nRoots) {

        case ONE:
            printf("Введите кол-во цифр после точки (до 6)\n");
            char accuracy_read [20];
            if ((fgets(accuracy_read, sizeof(accuracy_read), stdin) != NULL)) {
                if (sscanf(accuracy_read, "%d", &accuracy) == 1 && accuracy <= 6 && accuracy >= 0) {
                    printf ("x=%.*lf", accuracy, *x1);
                    printf ("quantity of roots - %d\n\n", nRoots);
                } else {
                    printf("Error input\n");
                }
            } else {
                printf("Error read");
            }
            break;

        case TWO:
            printf("Введите кол-во цифр после точки (до 6)\n");
            char accuracy_READ [20];
            if ((fgets(accuracy_READ, sizeof(accuracy_READ), stdin) != NULL)) {
                if (sscanf(accuracy_READ, "%d", &accuracy) == 1 && accuracy <= 6 && accuracy >= 0) {
                    printf("x1=%.*lf, x2=%.*lf \n", accuracy, *x1, accuracy, *x2);
                    printf ("quantity of roots - %d\n\n", nRoots);
                } else {
                    printf("Error input\n");
                }
            } else {
                printf("Error read");
            }
            break;


        case NO:
            printf ("there is no roots\n\n");
            break;

        case INF:
            printf ("infinity quantity if roots\n\n");
            break;

        default: ;

    }

}
