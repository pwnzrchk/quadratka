#include <stdio.h>
#include <math.h>

const double e = 1.0e-10;

double disc (double kfA, double kfB,  double kfC)
{
    double D = (kfB * kfB) - (4 * kfA * kfC);
    return D;
}


int main(void)
{
    double a, b, c = NAN;
    printf ("Введите коэффициенты квадратного уравнения a, b и c \n");       //initialization of a,b,c
    int num = scanf ("%lf %lf %lf", &a, &b, &c);
    if (num != 3)                                                           // if unacceptable data
    {
        printf("Error input\n");
    }

    if (fabs(a-0) < e)                                           //If a=0
    {
        printf ("There is not a square equation\n");
        if (abs(b-e) < 0)                                       //and b=0
        {
            printf ("There is not a equation at all\n");    //not a equation
        } else                                                    //a=0, b!=0 - linear case
        {
            printf ("So lets solve linear equation\n");
            float x = -c/b;
            printf ("%g\n", x);
        }
    } else
    {
        if (abs(b-e) < 0 && c < 0)                                  //b=0, c<0 - two same roots with a diff signs
        {
            float x = sqrt(-c/a);
            printf ("+/-%g \n", x);
        }
    }
    else
    {
        double D = disc(a, b, c);
        double x1 = (-b + sqrt(D))/(2*a);                       //standart square
        double x2 = (-b - sqrt(D))/(2*a);
        if (x1 != x2 )
        {
             printf ("%g, %g\n", x1, x2);
        }
        else
        {
            printf ("%g\n", x1);
        }

    }


    double D = disc(a, b, c);
    if (D>0 || (abs(b-e) < 0 && c < 0))
    {
        printf ("There is 2 roots\n");
    }
    else if ( D-e < 0 && D >= 0)
    {
        printf ("There is 1 root\n");
    }
    else
    {
        printf ("No roots\n");
    }


    //double sD = sqrt(disc (a, b, c));
    return 0;
}


// разбить на функции, выводимые значения scanf-do scan w/o char, header file
// command-S
// сравнить дабл и 0 через эпсилон и если модуль разности больше эпсилон - а != 0, иначе а = 0

int solveSquareEquation (double a, double b, double c, double* x1, double* x2) {
  if isEqual(a,0) {
     solveLinearEquation(b, c, x1);
  }
}

// инпут, аутпут, решение квадратки, решение линейного, сравнение двух даблов
//указатели - влияю на оригинал ставя звезду перед
// флаги
