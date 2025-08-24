#include <stdio.h>
#include <math.h>       // инпут, аутпут, решение квадратки, решение линейного, сравнение двух даблов

const double e = 1.0e-10;

const double NOT_A_EQUATION -2;
const double ONE_ROOT 1;
const double TWO_ROOT 2;
const double NO_ROOTS 0;
const double INF_NUM_ROOTS -1;


int isEqual (double smpl_a, double smpl_b)      //Сравнение с нулём
{
 if (fabs(~_a - smpl_b)<e)
    return 1;
 else
 {
    return 0;
 }
}


int RIP (void)
{
    printf("Не уравнение");
    return NOT_A_EQUATION;
}


int solveSquareEquation (double a, double b, double c, double* x1, double* x2) //В зависимости от return кол-во решений
{

  if isEqual(double a, 0)                //bx+c=0
  {
    solveLinearEquation(b, c, x1);
  }

  if isEqual(double b, 0)               // ax^2+c=0
  {
    fakeOneEquation(a, c, double* x1, double* x2);
  }

  double d = sqrt(disc(a, b, c));       //случай ax^2+bx+c=0
  if (d > 0)
  {
    *x1 = (-b - d)/(2*a);
    *x2 = (-b + d)/(2*a);
    return 2;
  } else if (isEqual(d, 0))
  {
    *x1 =
  }

}


double disc (double kfA, double kfB,  double kfC)                               //Поиск дискриминанта
{
    double D = (kfB * kfB) - (4 * kfA * kfC);
    return D;
}
double a = 113;
double* address_a = &a
printf("%d, %p", *address_a, address_a)
double solveLinearEquation(double b, double c, double* x1)                      //случай bx+c=0
{
    if (isEqual(double b, 0))       //a, b=0
    {
        if (isEqual(double c, 0))   //a, b, c=0
        {
            printf("Бесконечное кол-во корней");
            return INF_NUM_ROOTS;
        }
        else                        //a, b = 0, c != 0
        {
            RIP();
        }
    }
    *x1 = -c/b;
    return ONE_ROOT;
}


double fakeOneEquation (double a, double c, double* x1, double* x2)             //случай  ax^2+c=0
{
    if (isEqual(double c, 0))   //случай ax^2+0=0
    {
    if (isEqual(double a, 0))   //0*x^2+0=0
        {
            return INF_NUM_ROOTS;
        }

    *x1 = *x2 = 0;
    return ONE_ROOT;
    }

    if ((isEqual(double a, 0))     //0*x^2+c=0
    {
        if (isEqual(double c, 0))
        {
            return INF_NUM_ROOTS;
        }
        return NOT_A_EQUATION;
    }

    if((a/c) < 0)          //как написать, что числа разных знаков
    {
    x = sqrt(-c/a);
    &x1 = +x;
    &x2 = -x;
    return TWO_ROOTS;
    }

    else
    {
    return NO_ROOTS;
    }




}


int main(void)
{
    double a, b, c = NAN, x1, x2 = 0; // NAN
    printf ("Введите коэффициенты квадратного уравнения a, b и c \n");       //initialization of a,b,c
    int num = scanf ("%lf %lf %lf", &a, &b, &c);
    if (num != 3)                                                           // if unacceptable data
    {
        printf("Error input\n");
    }

    return 0;
}

//Точность, проверка ввода, return -  для ко-ва корней,
int abx(int x, int c, double*m
