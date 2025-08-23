#include <stdio.h>
#include <math.h>       // инпут, аутпут, решение квадратки, решение линейного, сравнение двух даблов

const double e = 1.0e-10;

const int NOT_A = -2;
const int ONE = 1;
const int TWO = 2;
const int NO = 0;
const int INF = -1;

int solveLinearEquation (double b, double c, double* x1);
int solveSquareEquation (double a, double b, double c, double *x1, double *x2);



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
        solveLinearEquation (b, c, x1);
    }

    if (isEqual(b,0)) {
        if (a/c < 0) {
            *x1 = -sqrt(-c/a);
            *x2 = sqrt(-c/a);
            return TWO;
        } else {
            return NO;
        }

    }

    double d = sqrt(disc(a,b,c));

    if (d>0) {
        *x1 = (-b-d)/(2*a);
        *x2 = (-b+d)/(2*a);
        return TWO;
    }

    if (isEqual(d,0)) {
        *x1 = *x2 = -b/(2*a);
        return ONE;
    }

    else {
    return NO;
    }
}

int solveLinearEquation (double b, double c, double* x1)
{
    if (isEqual(b, 0))
    {
        if (isEqual(c, 0))
        {
            printf("Бесконечное кол-во корней");
            return INF;
        }
        else
        {
            return NO;
        }
    }
    *x1 = -c/b;
    return ONE;
}

int main (void)
{
    double a, b, c, x1, x2 = NAN;
    printf ("Введите коэффициенты квадратного уравнения a, b и c \n");
    int num = scanf ("%lf %lf %lf", &a, &b, &c);
    if (num != 3)
    {
        printf("ERROR INPUT!!!\n\n\n");
    }
    int nRoots = solveSquareEquation(a, b, c, &x1, &x2);
    if (fabs(x1))

    printf ("\nx1 = %lg, x2 = %lg\n", x1, x2);
    printf ("How much roots - %d\n\n", nRoots);

    return 0;
}
