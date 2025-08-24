#include <stdio.h>
#include <math.h>
#include "zero.h"
#include "SQUARE_H.h"
#include "TEST.h"

const int ONE = 1;
const int TWO = 2;
const int NO = 0;
const int INF = -1;


int main (void)
{

    double a, b, c, x1, x2 = NAN;
    printf ("Введите коэффициенты квадратного уравнения a, b и c \n");
    int num = scanf ("%lf %lf %lf", &a, &b, &c);

    int mistakes = RunTest();

    if (num != 3)
    {
        printf("\nERROR INPUT\n\n");
    }

    if (num == 3 && mistakes == 0) {
    int nRoots = solveSquareEquation(a, b, c, &x1, &x2);

    x1 = zeroing(x1);
    x2 = zeroing(x2);



    if (nRoots == ONE)
    {
        printf("Введите кол-во цифр после точки (до 6)\n");
        int accuracy = 0;
        scanf("%d", &accuracy);
        printf ("x=%.*lf\n", accuracy, x1);
        printf ("\nquantity of roots - %d \n", nRoots);
    } else if (nRoots == INF) {
        printf ("infinity quantity if roots \n\n");
    } else if (nRoots == NO) {
        printf ("there is no roots \n\n");
    } else if (nRoots == TWO) {
        printf("Введите кол-во цифр после точки (до 6)\n");
        int accuracy = 0;
        scanf("%d", &accuracy);
        printf("x1=%.*lf, x2=%.*lf \n", accuracy, x1, accuracy, x2);
        printf("quantity of roots - %d \n", nRoots);
    }
    }

    return 0;
}

// Точность, выход, тесты, указатели done
//Разделить на хедеры, цикл для выхода, юнитест доделать, условная компиляция, аутпут отдельный

