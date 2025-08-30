#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int parser(double* a, double* b, double* c) {
    printf ("Введите коэффициенты квадратного уравнения a, b и c\n"
            "Или exit для завершения\n");

        char input[100];
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error read\n");
            return 1;
        }

        input[strcspn(input, "\n")] = '\0';

        if (!(strcmp(input, "exit"))) {
            printf("Exiting...\n");
            return 1;
        }

        char* p = input;
        char* endptr;
        int count = 0;
        double value = NAN;

        while(*p != '\0' && count < 3) {
            value = strtod(p, &endptr);

            if (p == endptr) {
                p++;
                continue;
            }

            switch(count) {
                case 0:
                    *a = value;
                    break;

                case 1:
                    *b = value;
                    break;

                case 2:
                    *c = value;
                    break;

                default: ;
            }
            count++;
            p = endptr;
        }
        if (count != 3) {
            printf("Error! There is no coefficients\n");
            return 1;
        }
    return 0;
}
