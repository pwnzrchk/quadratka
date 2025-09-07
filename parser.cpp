#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

const int INP_MAX_SIZE = 100;

int parser(double* a, double* b, double* c) {
    printf ("Введите коэффициенты квадратного уравнения a, b и c\n"
            "Или exit для завершения\n");
        char input[INP_MAX_SIZE];

        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error read\n");
            return 1;
        }

        input[strcspn(input, "\n")] = '\0';

        if (!(strcmp(input, "exit"))) {
            printf("Exiting...\n");
            return 1;
        }

        sscanf(input, "%lf %lf %lf", a, b, c);

    return 0;
}
