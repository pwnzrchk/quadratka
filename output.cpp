#include <stdio.h>
#include <math.h>
#include "square.h"
#include "testing.h"

const int ONE = 1;
const int TWO = 2;
const int NO = 0;
const int INF = -1;


void output(double a, double b, double c, double * x1, double *x2) {

    int accuracy = 0;
    int m = 0;
    int nRoots = solveSquareEquation(a, b, c, x1, x2);


    isEqual(*x1, 0) ? *x1 = 0 : *x1 = *x1;
    isEqual(*x2, 0) ? *x2 = 0 : *x2 = *x2;

    switch (nRoots) {

        case ONE:   printf("Введите кол-во цифр после точки (до 6)\n");
                    m = scanf("%d", &accuracy);
                    if (m != 1 || accuracy > 6 || accuracy < 0) {
                        printf("Error input\n");
                    } else {
                        printf ("x=%.*lf\n", accuracy, *x1);
                        printf ("\nquantity of roots - %d \n", nRoots);
                    }
                    break;

        case TWO:   printf("Введите кол-во цифр после точки (до 6)\n");
                    m = scanf("%d", &accuracy);
                    if (m != 1 || accuracy > 6 || accuracy < 0) {
                        printf("Error input\n");
                    } else {
                    printf("x1=%.*lf, x2=%.*lf \n", accuracy, *x1, accuracy, *x2);
                    printf("quantity of roots - %d \n", nRoots);
                    }
                    break;


        case NO:    printf ("there is no roots \n\n");
                    break;

        case INF:   printf ("infinity quantity if roots \n\n");
                    break;

        default:    printf ("Error input\n");

    }
}
