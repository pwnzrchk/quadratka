#include <stdio.h>
#include <math.h>
#include "zero.h"
#include "square.h"
#include "testing.h"
#include "output.h"

int main (void)
{
    if (allTests() == 0 ) {
        double a, b, c, x1, x2 = NAN;

        printf ("Введите коэффициенты квадратного уравнения a, b и c \n");
        int num = scanf ("%lf %lf %lf", &a, &b, &c);

        if (num != 3) {
            printf("\nError input\n");
        }
        else /*do*/ {
        output(a, b, c, &x1, &x2);
        } /*while ()*/;
        return 0;

    }
}

// Точность, выход, тесты, указатели
//Разделить на хедеры, цикл для выхода, юнитест доделать, условная компиляция, аутпут отдельный
