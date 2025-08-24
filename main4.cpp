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
    } else if (!(isEqual(b, 0)) && !(isEqual(c,0))) {
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
    if (num == 3) {
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
    }
    return 0;
}
