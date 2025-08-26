#include <stdio.h>
#include <math.h>
#include "zero.h"
#include "square.h"
#include "testing.h"
#include "output.h"
#include "string.h"

int main (void)
{
    if (allTests() == 0 ) {

        int ex = 5;
        //char = 'G';
        do {
            double a, b, c, x1, x2 = NAN;

            printf ("Введите коэффициенты квадратного уравнения a, b и c \n");
            int num = scanf ("%lf %lf %lf", &a, &b, &c);

            if (num != 3) {
                printf("\nError input\n");
                return 0;
            }
            else {
            output(a, b, c, &x1, &x2);
            printf ("\nType \"0\" to exit\nOr enter any other number to continue\n");
            scanf ("%d", &ex);
            };
        } while (ex != 0);
        return 0;
    } //
}




// Точность, выход, тесты, указатели
//Разделить на хедеры, цикл для выхода, юнитест доделать, условная компиляция, аутпут отдельный

/*scanf ("%s", input_str);
if (scanf ("%s", input_str) != 1) {
printf("\nError input\n");
return 0;*/

