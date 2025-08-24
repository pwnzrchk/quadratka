#include <stdio.h>
#include <math.h>
#include "zero.h"
//#include "testSolveSquare.h"

const double e = 1.0e-10;


const int ONE = 1;
const int TWO = 2;
const int NO = 0;
const int INF = -1;

int solveLinearEquation (double b, double c, double* x1);
int solveSquareEquation (double a, double b, double c, double *x1, double *x2);
int isEqual (double smpl_a, double smpl_b);
double disc (double kfA, double kfB,  double kfC);
int testSolveSquare(void);

int testSolveSquare(void) {

    double x1, x2 = NAN;
    int nRoots1 = solveSquareEquation(1, -5, 4, &x1, &x2); //1 -5 4, 1 4
    if (nRoots1 != 2 || !(isEqual(x1, 1)) || !(isEqual(x2, 4))) {
        printf("Test 1 failed: nRoots = %d (expected 2), x1 = %lf, x2 = %lf (expected 1, 4)\n", nRoots1, x1, x2);
        return 1;
    }

    int nRoots2 = solveSquareEquation(1, -3, 2, &x1, &x2);// 1 -3 2, 1 2
    if (nRoots2 != 2 || !(isEqual(x1, 1)) || !(isEqual(x2, 2))) {
        printf("Test 2 failed: nRoots = %d (expected 2), x1 = %lf, x2 = %lf (expected 1, 2)\n", nRoots2, x1, x2);
        return 2;
    }

    int nRoots3 = solveSquareEquation(1, -7, 12, &x1, &x2);// 1 -7 12, 3 4
    if (nRoots3 != 2 || !(isEqual(x1, 3)) || !(isEqual(x2, 4))) {
        printf("Test 3 failed: nRoots = %d (expected 2), x1 = %lf, x2 = %lf (expected 3, 4)\n", nRoots3, x1, x2);
        return 3;
    }

    int nRoots4 = solveSquareEquation(1, 3, -4, &x1, &x2);
    if (nRoots4 != 2 || !(isEqual(x1, -4)) || !(isEqual(x2, 1))) {
        printf("Test  failed: nRoots = %d (expected 2 ), x1 = %lf, x2 = %lf (expected -4, 1 )\n", nRoots4, x1, x2);
        return 4;
    }
    return 0;
}

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
                *x1 = *x2 = -b/(2*a);
                return ONE;
            } else {
             return NO;
             }
}

int solveLinearEquation (double b, double c, double* x1)
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
    } else if (!(isEqual(b, 0)) && !(isEqual(c,b))) {
    *x1 = -c/b;
    return ONE;
    }
    return NO;

}

int main (void)
{

    double a, b, c, x1, x2 = NAN;
    printf ("Введите коэффициенты квадратного уравнения a, b и c \n");
    int num = scanf ("%lf %lf %lf", &a, &b, &c);
    if (num != 3)
    {
        printf("\nERROR INPUT\n\n");
    }
    int test = testSolveSquare(void);
    if (num == 3 && test == 0 ) {
    int nRoots = solveSquareEquation(a, b, c, &x1, &x2);

    x1 = zeroing(x1);
    x2 = zeroing(x2);

    if (nRoots == ONE)
    {
        printf("Введите кол-во цифр после точки\n");
        int accuracy;
        scanf("%d", &accuracy);
        printf ("x=%.*lf\n", accuracy, x1);
        printf ("\nquantity of roots - %d \n", nRoots);
    } else if (nRoots == INF) {
        printf ("infinity quantity if roots \n\n");
    } else if (nRoots == NO) {
        printf ("there is no roots \n\n");
    } else if (nRoots == TWO) {
        printf("Введите кол-во цифр после точки\n");
        int accuracy;
        scanf("%d", &accuracy);
        printf("x1=%.*lf, x2=%.*lf \n", accuracy, x1, accuracy, x2);
        printf("quantity of roots - %d \n", nRoots);
    }
    } if (test != 0) {
    printf ("Ошибка в %d-ом тесте",test);
    }
    return 0;
}
// Точность, выход, тесты, указатели done
//Разделить на хедеры, цикл для выхода
