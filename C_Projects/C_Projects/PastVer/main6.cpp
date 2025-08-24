#include <stdio.h>
#include <math.h>
#include "zero.h"

const double e = 1.0e-10;


const int ONE = 1;
const int TWO = 2;
const int NO = 0;
const int INF = -1;

int solveLinearEquation (double b, double c, double* x1);
int solveSquareEquation (double a, double b, double c, double *x1, double *x2);

int isEqual (double smpl_a, double smpl_b);
double disc (double kfA, double kfB,  double kfC);

int oneTest (double a, double b, double c, double x1ref, double x2ref, double nRootsref);
int RunTest();



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
                *x1 = -b/(2*a);
                *x2 = NAN;
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
    } else if (!(isEqual(b, 0)) && !(isEqual(c, 0))) {
    *x1 = -c/b;
    return ONE;
    }
    return NO;
}

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

int main (void)
{

    double a, b, c, x1, x2 = NAN;
    printf ("Введите коэффициенты квадратного уравнения a, b и c \n");
    int num = scanf ("%lf %lf %lf", &a, &b, &c);

    int RunTest(void);
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
        int accuracy;
        scanf("%d", &accuracy);
        printf ("x=%.*lf\n", accuracy, x1);
        printf ("\nquantity of roots - %d \n", nRoots);
    } else if (nRoots == INF) {
        printf ("infinity quantity if roots \n\n");
    } else if (nRoots == NO) {
        printf ("there is no roots \n\n");
    } else if (nRoots == TWO) {
        printf("Введите кол-во цифр после точки (до 6)\n");
        int accuracy;
        scanf("%d", &accuracy);
        printf("x1=%.*lf, x2=%.*lf \n", accuracy, x1, accuracy, x2);
        printf("quantity of roots - %d \n", nRoots);
    }
    }

    return 0;
}
// Точность, выход, тесты, указатели done
//Разделить на хедеры, цикл для выхода

