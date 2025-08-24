#include <stdio.h>
#include <math.h>       // инпут, аутпут, решение квадратки, решение линейного, сравнение двух даблов

const double e = 1.0e-10

int isEqual (double smpl_a, 0)                                          //Ф-ция сравнения с 0
{
 if ((smpl_a-0)<e)
 return 1;
 else {
 return 0;
 }
}

//---------------------------

double solveLinearEquation(double fB, double fC, double fX1)  //Ф-ция для решения линейного
{
    return double fX1 = -fC/fB;
}

//---------------------------

double solveFalse1RootEquatinon (double k_a, double k_c, double k_x1, double k_x2) //Ф-ция для решения с 2-мя разнознаковыми корнями
{
    double x = sqrt(-c/a);
    return x, -x;
}
// ХУЙНЯ
//---------------------------

int RIP (void) //Ф-ция для отсутствия корней
{
    printf("Нет корней");
    return 0;
}

//---------------------------

 solveSquareEquatinon (double a, double b, double c, double* x1, double* x2) //Общая ф-ция для решения
{
 if (isEqual(double a, 0))                     //Проверка на квадратность
  {
   if (isEqual(double b, 0))                   //Проверка на коэфф b
   {
    if (isEqual(double c, 0))
    {
    printf("INF num of solutions");             // бесконечность
    } else
    {
    solveLinearEquation(double b, double c, double x1);    //Решаем линейное, если есть b
    }
   }
  }

 if (isEqual(double b, 0) && c < 0)         // сравнение с эпсилон
 {
  solvefalse1RootEquatinon (double a, double c, double x1, double x2);
 }
 else if (isEqual(double b, 0) && c>0)
 {
 RIP(void);
 } else
 {
  solveSquare (double a, double b, double c, double* x1, double* x2);
 }

}


int main (void)
{


}

